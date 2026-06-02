#pragma once

#include "Share.h"
#include "ThreadCache.h"
#include "PageCache.h"
#include "ObjectPool.h"

// 提供两个接口 —— TLS 相关草族谱

// 通过 TLS 每个线程无锁的获取自己专属的 ThreadCache 对象
static void *ConcurrentAlloc(size_t size)
{
	if (size > MAX_BYTES)
	{
		size_t alignSize = SizeClass::RoundUp(size);
		size_t kpage = alignSize >> PAGE_SHIFT;

		PageCache::GetInstance().GetPageMutex().lock();
		Span *span = PageCache::GetInstance().NewSpan(kpage);
		span->s_objSize = size;
		PageCache::GetInstance().GetPageMutex().unlock();

		void* ptr = (void*)((span->s_pageId) << PAGE_SHIFT);	// 获取 span 的地址

		return ptr;
	}
	else
	{
		if (pTLSThreadCache == nullptr)
		{
			// pTLSThreadCache = new ThreadCache;
			static ObjectPool<ThreadCache> tcPool;
			pTLSThreadCache = tcPool.New();
		}

		std::cout << std::this_thread::get_id() << " : " << pTLSThreadCache << endl;

		return pTLSThreadCache->Allocate(size);
	}
}

// static void ConcurrentFree(void* ptr, size_t size)
static void ConcurrentFree(void* ptr)
{
	Span* span = PageCache::GetInstance().MapObjectToSpan(ptr);		// 通过页号找到对应的 span
	size_t size = span->s_objSize;
	if (size > MAX_BYTES)
	{
		PageCache::GetInstance().GetPageMutex().lock();
		PageCache::GetInstance().ReleaseSpanToPageCache(span);
		PageCache::GetInstance().GetPageMutex().unlock();
	}
	else
	{
		assert(pTLSThreadCache);	// TLS 不为空

		// 一般来说，调用 malloc 需要知道 size 大小，调用 free 需要知道指针就可以了
		// 调用 Deallocate, 需要知道大小，从而知道内存空间归还给哪个桶的位置
		pTLSThreadCache->Deallocate(ptr, size);
	}
}

// 优化1：使用定长内存池 ObjectPool 中实现的 New/Delete 替换 new/delete
// 优化2：释放对象时优化为不传对象大小
// 性能测试：多线程环境下对比 malloc 测试