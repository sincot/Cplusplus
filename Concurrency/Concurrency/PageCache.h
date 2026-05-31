#pragma once

#include "Share.h"

// 单例饿汉模式 —— 与 Central Cache 部分实现的差不多
class PageCache
{
public:
	static PageCache& GetInstance() { return _sInst;  }

	Span* NewSpan(size_t k);	// Central Cache 从 Page Cache 获取 k 页的 Span

	std::mutex& GetPageMutex() { return _pageMutex; }
private:
	SpanList _pageLists[NPAGES];	// 第 i 号桶中挂的 span 都是 i 页内存

	// page cache 使用的页锁，为什么不使用桶锁
	// 当线程1和线程2分别找 1页的 span 和 2页的 span，但是对应的桶位置都没有，那么都会访问第3页的桶位置
	// 使用桶锁也可以，但是会涉及不断的加锁与解锁操作，加锁解锁的消耗也很大的，直接加一把大锁更省事
	// 最主要的是它不同与 Central Cache，要 8byte 的就到对应的桶位置去找，Page Cache 要 8页的span，可能需要找 9/10/12 页的span，看看是否有空闲的 span
	// 若使用桶锁，每次向后查找空闲其它页的空闲 span 时都需要加锁与解锁，十分的麻烦
	std::mutex _pageMutex;			// 将整个 Page Cache 锁起来

private:
	PageCache() {}
	PageCache(const PageCache&) = delete;

	static PageCache _sInst;
};