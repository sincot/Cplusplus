#pragma once

#include "Share.h"
#include "ThreadCache.h"

// 提供两个接口 —— TLS 相关草族谱

// 通过 TLS 每个线程无锁的获取自己专属的 ThreadCache 对象
static void *ConcurrentAlloc(size_t size)
{
	if (pTLSThreadCache == nullptr)
	{
		pTLSThreadCache = new ThreadCache;
	}

	std::cout << std::this_thread::get_id() << " : " << pTLSThreadCache << endl;

	return pTLSThreadCache->Allocate(size);
}

static void ConcurrentFree(void* ptr, size_t size)
{
	assert(pTLSThreadCache);	// TLS 不为空

	// 一般来说，调用 malloc 需要知道 size 大小，调用 free 需要知道指针就可以了
	// 调用 Deallocate, 需要知道大小，从而知道内存空间归还给哪个桶的位置
	pTLSThreadCache->Deallocate(ptr, size);
}