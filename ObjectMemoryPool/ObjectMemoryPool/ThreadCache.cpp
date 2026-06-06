#include "ThreadCache.h"
#include "CentralCache.h"

/*********************** 申请与释放内存对象 ***********************/
void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAX_BYTES);	// 确保申请的内存大小不超过最大值

	// 申请的内存大小对齐后的大小
	size_t alignedSize = SizeClass::RoundUp(size); 
	// 计算申请的内存大小对应的大小类索引
	size_t index = SizeClass::Index(size);

	if (_freeLists[index].Empty() == false)  // 如果对应大小类的自由链表不为空，就从自由链表中取出一个内存块
	{
		return _freeLists[index].Pop();   // 从自由链表中取出一个内存块(头)并返回
	}
	else    // 如果对应大小类的自由链表为空，就从中央缓存中获取更多的内存块
	{
		// 从 Central Cache 中获取内存块
		return FetchFromCentralCache(index, alignedSize);
	}
}

void ThreadCache::Deallocate(void* ptr, size_t size)
{
	assert(ptr != nullptr);     // 确保释放的内存块不为空
	assert(size <= MAX_BYTES);	// 确保释放的内存大小不超过最大值

	// 找到对应的映射的自由链表桶，将对象插入对应桶的自由链表中
	size_t index = SizeClass::Index(size);  // 计算释放的内存大小对应的大小类索引
	_freeLists[index].Push(ptr);    // 将释放的内存块加入对应大小类的自由链表
}
/******************************************************************/

// 从 Central Cache 中获取内存块 —— 获取 size 大小类的内存块
void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	// 慢开始反馈调节算法
	// 1. 最开始不会一次向 central cache 一批次要太多，因为要太多了可能使用不完
	// 2. 若对于 size 大小内存的需求很大，那么 batchNum 会不断增长，直到达到上限 [2, 512]
	size_t batchNum = min(_freeLists[index].GetMaxSize(), SizeClass::NumMoveSize(size));

	if (batchNum == _freeLists[index].GetMaxSize())	_freeLists[index].GetMaxSize() += 1;	// 慢增长

	void* start = nullptr, * end = nullptr;	
	size_t actualNum = CentralCache::GetInstance().FetchRangeObj(start, end, batchNum, size);		// 实际申请到的 size 大小内存对象的个数
	assert(actualNum > 0);		// 实际获得的 size 大小内存对象至少有 1 个

	if (actualNum == 1) { assert(start == end);	 return start; }	// 如果实际上只获得 1 个，返回获取的链表的头指针
	else    // 挂载
	{
		_freeLists[index].PushRange(*(void**)start, end);
		return start;
	}

	return nullptr;
}

