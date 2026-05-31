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
	assert(k > 0 && k < NPAGES);

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
			Span* kSpan = new Span;
			kSpan->s_pageId = nSpan->s_pageId;		// 大块内存的起始页号
			kSpan->s_n = k;							// 有几页

			nSpan->s_pageId += k;					// 第 i-k 个桶的大块内存的起始页号向后增加k
			nSpan->s_n -= k;						// 变成第 i - k 页

			// 将 i-k 页的 span 挂载到对应的位置
			_pageLists[nSpan->s_n].PushFront(nSpan);

			return kSpan;
		}
	}

	// 走到这个位置可以说明，没有大页的 span 了。这时就需要向堆要 128 页的 span
	Span* bigSpan = new Span;
	void* ptr = SystemAlloc(NPAGES - 1);	// 向堆申请 NPAGES-1 页的 span
	// 返回的是指针，怎么转成页号？第 1 页的起始地址是 8*1024，第2页的起始地址 8*1024+8*1024 = 16*1024
	bigSpan->s_pageId = (PAGE_ID)ptr >> PAGE_SHIFT;		// 页号
	bigSpan->s_n = NPAGES - 1;							// 页数

	_pageLists[bigSpan->s_n].PushFront(bigSpan);	// 将 bigSpan 插入到对应的桶位置

	return NewSpan(k);	// 递归调用自己
}
