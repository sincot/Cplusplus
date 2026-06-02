#pragma once

#include "Share.h"
#include "ObjectPool.h"

// 单例饿汉模式 —— 与 Central Cache 部分实现的差不多
class PageCache
{
public:
	static PageCache& GetInstance() { return _sInst;  }

	Span* NewSpan(size_t k);	// Central Cache 从 Page Cache 获取 k 页的 Span

	std::mutex& GetPageMutex() { return _pageMutex; }

	Span* MapObjectToSpan(void* obj);	// 通过 obj 对象，计算它的页号与span的映射关系

	// 释放空闲的 span 回到 PageCache，并合并相邻的 span
	void ReleaseSpanToPageCache(Span* span);

private:
	SpanList _pageLists[NPAGES];	// 第 i 号桶中挂的 span 都是 i 页内存

	ObjectPool<Span> _spanPool;		// 使用定长内存池替换 new/delete

	// page cache 使用的页锁，为什么不使用桶锁
	// 当线程1和线程2分别找 1页的 span 和 2页的 span，但是对应的桶位置都没有，那么都会访问第3页的桶位置
	// 使用桶锁也可以，但是会涉及不断的加锁与解锁操作，加锁解锁的消耗也很大的，直接加一把大锁更省事
	// 最主要的是它不同与 Central Cache，要 8byte 的就到对应的桶位置去找，Page Cache 要 8页的span，可能需要找 9/10/12 页的span，看看是否有空闲的 span
	// 若使用桶锁，每次向后查找空闲其它页的空闲 span 时都需要加锁与解锁，十分的麻烦
	std::mutex _pageMutex;			// 将整个 Page Cache 锁起来

	// 在 Page Cache 分配 span 是就要建立映射关系
	std::unordered_map<PAGE_ID, Span*> _idSpanMap;		// 建立页号与 span 的映射
	// std::unordered_map<PAGE_ID, size_t> idSizeMap;		// 建立页号与 span 大小的映射

	// 由 CentralCache.cpp 中可知，每页 span 切割成小块内存空间的大小都是一样的：start_address += byte_size;
	// 因此，可以在 span 结构体定义一个变量来记录 span 的大小

private:
	PageCache() {}
	PageCache(const PageCache&) = delete;

	static PageCache _sInst;
};