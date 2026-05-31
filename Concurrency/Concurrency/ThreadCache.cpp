#include "ThreadCache.h"
#include "CentralCache.h"


// 每个线程的 Thread Cache 对应的桶中没有内存对象了，都会从 Central Cache 获取
// 如何获取到 Central Cache 的对象 —— 单例模式（饿汉模式 和 懒汉模式） 
void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	// Thread Cache 的内存对象不够用了，从 Central Cache 中获取，但是不可能只分配一点一点，应该分配多少
	// 对于 8byte 这样小的对齐数来说，分配多一点似乎没什么问题，但是对于 128byte 这样大的对齐数来说，分配多一点回浪费
	// 采用 慢开始反馈调节算法 —— 小对象分配多一点，大对象分配少一点，怎么实现？
	// 取桶与一次批量移动的上限值中的最小值
	size_t batchNum = min(_freeLists[index].MaxSize(), SizeClass::NumMoveSize(size));

	// 第二次来取了, _maxSize+1，也可以加其它的值，让增长变得更快一点，这就是慢增长
	// 1. 最开始不会一次向 central cache 一次批量的要太多，因为要太多了可能用不完
	// 2. 如果不断有 size 大小的内存需求，那么 batchNum 会不断的增长，直到上限
	// 3. size 越大，一次向 central cache 要的 batchNum 就越小
	// 4. size 越小，一次向 central cache 要的 batchNum 就越大
	if (_freeLists[index].MaxSize() == batchNum)	_freeLists[index].MaxSize() += 1;

	void* start = nullptr, * end = nullptr;
	// 申请单例 —— 获取全局唯一的实例对象
	// 可能需要10个内存对象，但是 span 中并没有这么多。即便如此，有多少给多少
	size_t actualNum = CentralCache::GetInStance().FetchRangeObj(start, end, batchNum, size);
	assert(actualNum > 0);	// 实际获得的内存对象至少得有一个

	// 如果实际获取到的内存对象只有一个，将获取到的内存块链表的头指针返回
	if (actualNum == 1)
	{
		assert(start == end);
		return start;
	}
	// 如果实际获取的内存对象有多个，将获取到内存块链表的头指针返回，剩下的挂回桶中
	else
	{
		// 将 start 的下个节点的地址传给 PushRange
		_freeLists[index].PushRange(*(void**)start, end);
		return start;
	}


	return nullptr;
}

void* ThreadCache::Allocate(size_t size)	// 申请内存对象
{
	assert(size <= MAX_BYTES);		// 申请的内存对象的大小要小于 ThreadCache 所能分配的最大空间

	size_t alignSize = SizeClass::RoundUp(size);	// 对齐的结果
	// 计算对齐的结果在哪个桶，从对应的桶中获取内存对象
	size_t index = SizeClass::Index(size);			// 位于哪个桶

	if (!_freeLists[index].Empty())		// 如果桶不为空，可以取内存
	{
		return _freeLists[index].Pop();
	}
	else                               // 桶为空，先 Central Cache 获取内存对象  
	{
		return FetchFromCentralCache(index, alignSize);		// 获取对齐后的大小
	}
}

void ThreadCache::Deallocate(void* ptr, size_t size)	// 释放内存对象
{
	assert(size <= MAX_BYTES);
	assert(ptr);	// 指针不能为空

	size_t index = SizeClass::Index(size);	// 内存空间要归还给哪个桶
	_freeLists[index].Push(ptr);			// 头插进对应的桶中
}