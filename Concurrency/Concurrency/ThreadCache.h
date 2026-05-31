#pragma once

#include "Share.h"

class ThreadCache
{
public:
	// 申请和释放内存对象
	void* Allocate(size_t size);
	// 为什么释放内存对象，需要 size？这样才能知道要链接到哪个自由链表（桶）
	void Deallocate(void* ptr, size_t size);
	// 向 Central Cache 获取内存对象
	void* FetchFromCentralCache(size_t index, size_t alignSize);

private:
	// 我们知道哈希桶的每个桶挂载的都是一个自由链表，因此哈希桶中元素的类型都是 FreeList
	// 哈希桶的元素个数有多少个，需要看映射关系，Thread cache 用于处理小于 256KB 的内存分配 
	FreeList _freeLists[NHASH_LISTS];	// 有208个哈希桶
};

// 每个线程都有一个独享的 ThreadCache, 即 hash 桶
// 每个桶挂载着一个个小内存对象链接形成的自由链表
// 申请内存空间，计算所在的桶位置，如果桶中有内存对象，就直接取出使用，如果没有，找上一层
// 问题：当前的线程如何获取到 Thread Cache? Thread Cache 对象怎么创建，什么时候创建？
// 怎么控制线程所对应的 Thread Cache？哪个线程对应哪一个 Thread Cache？要为几个线程创建 Thread Cache?
// 有线程的时候，再创建 Thread Cahce，这样不就需要加锁了吗？因为有可能多个线程同时来
// 可以借助 TLS —— Thread local storage（线程本地存储），它分为静态的和动态的
// 这里使用静态的 _declspec(thread)
// TLS 是一种变量的存储方法，这个变量在它所在的线程内是全局可访问的，但是不能被其它线程访问到，这样就保持了数据的独立性
static _declspec(thread) ThreadCache* pTLSThreadCache = nullptr;	// 只在当前文件可见