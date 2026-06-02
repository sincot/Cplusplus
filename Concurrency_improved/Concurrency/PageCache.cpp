#include "PageCache.h"

PageCache PageCache::_sInst;

// Central Cache 从 Page Cache 获取 k 页的 Span
// 比如要找 3 页的span，但是 Page Cache 中没有，那么会向后找更大的页，比如找到了 5 页，会将 5 页分成 3 页和 2 页，3 页的分配出去，2 页的挂载到对应的桶位置
// 最极端的情况，找到 128 页，还是没有空闲的 Span，直接向系统申请 128 页的 span
// 比如要 2 页，将向系统申请的 128 页 span 分成 2 页的 span 和 126 页的 spab，2 页的分配给 Central Cache，126 页的 span 挂载到对应的桶位置
// 当 Central Cache 将不使用的 span 归还给 Page Cache。比如归还回来的页号为 100，直接查 99 页的 span 和 101页的 span 是否存在空闲的 span
// 如果 99 页存在空闲的 span，那么将 100页的span 与 99页空闲的 span 合并成更大的页

// 如果 central cache 中的 span use_count == 0，说明切分给 thread cache 的小块内存都回来了，则将 central cache 这个 span 归还给 page cache
// page cache 通过 pageId 页号，查看前后相邻页是否空闲，是的话就合并，合并成更大的页，解决内存碎片问题

// 接着要考虑加锁问题，加在 for 循环外
Span* PageCache::NewSpan(size_t k)
{
	// assert(k > 0 && k < NPAGES);
	assert(k > 0);
	// 大于 128 页直接向堆申请
	if (k > NPAGES - 1)		
	{
		void* ptr = SystemAlloc(k);
		// Span* span = new Span;
		Span* span = _spanPool.New();
		span->s_pageId = (PAGE_ID)ptr >> PAGE_SHIFT;	// 页id
		span->s_n = k;

		_idSpanMap[span->s_pageId] = span;		// 建立 pageid 与 span 的映射关系

		return span;
	}

	// 先在当前所在的第k个桶查看是否存在空闲的 span
	if (!_pageLists[k].Empty())
	{
		return _pageLists->PopFront();		// 返回 span 的头结点
	}
	// 当前所在的桶的不存在空闲的 span，检查后面的桶中是否存在 span，如果有，可以进行切分
	for (size_t i = k + 1; i < NPAGES; i++)
	{
		if (!_pageLists[i].Empty())		// 第 i 个桶不等于空，就可以开始切
		{
			// 获取第 i 页下的头 span，将其切分成一个 k 页的 span 和一个 i-k 页的 span，k 页的 span 返回给 central cache，i-k 页的 span 挂载到 i-k 桶中
			Span* nSpan = _pageLists[i].PopFront();		// 获取第 i 页的头 span
			// 切分成 k 页的 span 和 i-k 页的 span
			// Span* kSpan = new Span;
			Span* kSpan = _spanPool.New();
			kSpan->s_pageId = nSpan->s_pageId;		// 大块内存的起始页号
			kSpan->s_n = k;							// 有几页

			nSpan->s_pageId += k;					// 第 i-k 个桶的大块内存的起始页号向后增加k
			nSpan->s_n -= k;						// 变成第 i - k 页

			//// 现在是找不到前一个页中是否存在空闲的 span，因为 idSpanMap 中只缓存了分配给 central cache 的 span
			//// 将 i-k 页的 span 挂载到对应的位置
			//_pageLists[nSpan->s_n].PushFront(nSpan);

			//// 建立页号id与span的映射，方便 central cache 回收小块内存空间时，查找对应的 span
			//for (PAGE_ID i = 0; i < kSpan->s_n; i++)
			//{
			//	_idSpanMap[kSpan->s_pageId + i] = kSpan;
			//}

			// 将 i-k 页的 span 挂载到对应的位置
			_pageLists[nSpan->s_n].PushFront(nSpan);

			// 存储 nSpan 的首尾页号与 nSpan 的映射，方便 page cahce 回收内存时，进行合并查找
			_idSpanMap[nSpan->s_pageId] = nSpan;
			_idSpanMap[nSpan->s_pageId + nSpan->s_n - 1] = nSpan;

			// 建立页号id与span的映射，方便 central cache 回收小块内存空间时，查找对应的 span
			for (PAGE_ID i = 0; i < kSpan->s_n; i++)
			{
				_idSpanMap[kSpan->s_pageId + i] = kSpan;
			}

			return kSpan;
		}
	}

	// 走到这个位置可以说明，没有大页的 span 了。这时就需要向堆要 128 页的 span
	// Span* bigSpan = new Span;
	Span* bigSpan = _spanPool.New();
	void* ptr = SystemAlloc(NPAGES - 1);	// 向堆申请 NPAGES-1 页的 span
	// 返回的是指针，怎么转成页号？第 1 页的起始地址是 8*1024，第2页的起始地址 8*1024+8*1024 = 16*1024
	bigSpan->s_pageId = (PAGE_ID)ptr >> PAGE_SHIFT;		// 页号
	bigSpan->s_n = NPAGES - 1;							// 页数

	_pageLists[bigSpan->s_n].PushFront(bigSpan);	// 将 bigSpan 插入到对应的桶位置

	return NewSpan(k);	// 递归调用自己
}

Span* PageCache::MapObjectToSpan(void* obj)
{
	PAGE_ID id = ((PAGE_ID)obj >> PAGE_SHIFT);		// 计算出对象的页号
	auto ret = _idSpanMap.find(id);
	if (ret != _idSpanMap.end())	return ret->second;
	else { assert(false); return nullptr; }		// 不可能找不到，找不到说明前面的实现的逻辑存在问题
}

void PageCache::ReleaseSpanToPageCache(Span* span)
{
	// 大于 128 页 page 直接还给堆
	if (span->s_n > NPAGES - 1)
	{
		void* ptr = (void*)(span->s_pageId << PAGE_SHIFT);
		SystemFree(ptr);
		// delete span;
		_spanPool.Delete(span);

		return;
	}


	// span 归还回来了，需要对 span 前后的页，尝试进行合并，缓解内存碎片问题
	// 如果 span pageid: 1000, n: 1，向前找 999pageid，向后找 1001pageid
	// 若 pageid999 有 2页，那么可以与 pageid1000，合并成 3页；若 pageid1000 有 5页，那么可以合并成 8页
	// 如果 span pageid: 2000, n: 5，向前找 1999pageid，向后找 2005pageid
	
	// 合并时需要考虑的问题，其它页的 span 能否合并，只要在 Page Cache 的就可以合并
	// 如何判断是 Central Cache 的 span，还是 Page Cache？根据 use_count 是否为 0？
	// 这个判断显然是不靠谱的，因为新申请给 Central Cache 的 span 的 use_count 是为 0 的
	// 既然如此，在 Span 结构体中新增成员变量，用于标识 span 是否被使用 —— isUse
	
	while (1)	// 死循环向前合并
	{
		// 对 span 前面的页，尝试进行合并，缓解内存碎片问题
		PAGE_ID prevId = span->s_pageId - 1;	// 前一个页的 id

		auto ret = _idSpanMap.find(prevId);
		if (ret == _idSpanMap.end())		// 没有找到
		{
			break;
		}
		Span* prevSpan = ret->second;
		if (prevSpan->s_isUse == true)	// 找到了，但是前面页在被使用
		{
			break;
		}
		// 合并出超过128页的span，没办法管理，不能合并
		if (prevSpan->s_n + span->s_n >= NPAGES - 1)	
		{
			break;
		}

		// 可以合并了
		span->s_pageId = prevSpan->s_pageId;	// 起始页号改变
		span->s_n += prevSpan->s_n;

		_pageLists[prevSpan->s_n].Erase(prevSpan);
		_spanPool.Delete(prevSpan);
	}

	while (1)	// 死循环向后合并
	{
		// 对 span 后面的页，尝试进行合并，缓解内存碎片问题
		PAGE_ID nextId = span->s_pageId + span->s_n;	// 后一个页的 id

		auto ret = _idSpanMap.find(nextId);
		if (ret == _idSpanMap.end())		// 没有找到
		{
			break;
		}
		Span* nextSpan = ret->second;
		if (nextSpan->s_isUse == true)	// 找到了，但是前面页在被使用
		{
			break;
		}
		// 合并出超过128页的span，没办法管理，不能合并
		if (nextSpan->s_n + span->s_n >= NPAGES - 1)
		{
			break;
		}

		// 可以合并
		span->s_n += nextSpan->s_n;

		_pageLists[nextSpan->s_n].Erase(nextSpan);
	}

	// 合并完成，将合并的结果挂起来
	_pageLists[span->s_n].PushFront(span);
	span->s_isUse = false;		// span 没被使用
	_idSpanMap[span->s_pageId] = span;
	_idSpanMap[span->s_pageId + span->s_n - 1] = span;
}
