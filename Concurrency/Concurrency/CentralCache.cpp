#include "CentralCache.h"
#include "PageCache.h"

CentralCache CentralCache::_sInst;

// 从 SpanList 中获取一个非空的 span
Span* CentralCache::GetOneSpan(SpanList& list, size_t byte_size)
{
	// 使用自己实现的 Begin 和 End 函数，来实现迭代器遍历
	// 先查看当前的 spanlist 中是否还存在未分配对象的 span
	Span* it = list.Begin();
	while (it != list.End())
	{
		if (it->s_freeList != nullptr)	// 说明 span 有小块的内存对象
		{
			return it;		// 直接返回
		}
		else		// 若为空，找下一个 span
		{
			it = it->s_next;	// 向后移动
		}
	}

	// 要向上找 Page Cache 了，将 central cache 的桶锁解掉，这样其它的线程释放内存对象时，不会阻塞
	list._mutex.unlock();
	
	// 对申请操作加锁
	PageCache::GetInstance().GetPageMutex().lock();
	
	// 当前 spanlist 都遍历完毕了，还是没有空闲的 span，向上 Page Cache 获取 span
	// 计算 byte_size 大小的对象要找哪个页号 —— NumMovePage
	Span* span = PageCache::GetInstance().NewSpan(SizeClass::NumMovePage(byte_size));

	// 申请完毕后再解锁
	PageCache::GetInstance().GetPageMutex().unlock();

	// 申请完毕后，是否需要将桶锁给加上？不需要。为什么？
	// 因为从 Page Cache 获取到 span 之后，是加锁的。只有当前的线程才能访问到这个 span，因为这个span有没有挂载到 SpanList 上。因此不需要对于“对获取span进行切分”这个操作加锁
	// 什么时候才需要加锁，多个线程竞争同一份资源。而span只有当前的线程才能访问，对span进行切分这个操作，也只有当前的线程才会执行
	
	// 找到了拥有空闲的 span 的页，可能需要切分。通过页号，计算页的起始地址：页号 * 8KB(页大小)
	char* start_address = (char*)(span->s_pageId << PAGE_SHIFT);
	size_t bytes = span->s_n << PAGE_SHIFT;		// 大块内存的字节数大小：页数 * 8KB(页大小)

	// 针对找到的 span，插入到 Central Cache 对应的桶位置。在插入之前，需要将获取到的 span 切成小块内存，链接到 Central Cache 的 span 上
	// 知道页的起始地址，知道大块内存的字节大小，根据对齐数，如 8byte 进行切分
	char* end = start_address + bytes;

	// 采取尾插 —— 不仅逻辑上是链式结构，物理上也是连续的内存，预加载的缓存命中率高
	// 1. 先切一块下来做头节点，方便尾插
	span->s_freeList = start_address;
	start_address += byte_size;
	char* tail = (char*)span->s_freeList;
	while (start_address < end)
	{
		// 进行链接
		*(void**)tail = start_address;
		tail = start_address;	// 向后移动 tail = strat_address
		start_address += byte_size;
	}

	// 将 span 插入到 list 中，采用头插的方法，因为 list 中还要内存块
	list.PushFront(span);

	return span;
}

// 从 central cache 获取一定数量的对象给 thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t byte_size)
{
	size_t index = SizeClass::Index(byte_size);		// 在哪个桶

	_spanLists[index]._mutex.lock();	// 加锁

	Span* span = GetOneSpan(_spanLists[index], byte_size);	// 从 SpanList 中获取一个span
	assert(span);	// 不能没有获取到
	// span 中的 freeList 不能为空，不能使用 use_count，为什么？因为切的大小不一样，分配一个内存对象就+1，并不知道对于当前桶而言 use_count 应该是多少
	// 对应的桶中是否有内存对象，根据 freeList 来判断是最准确的
	assert(span->s_freeList);	

	// 获取到了合适的 span，假设 span 下挂载着 4 个内存对象，但是只需要 3 个，应该怎么取
	// // 假设 span 下挂载着 4 个内存对象，但是需要 5 个呢？因此需要对 batchNum 做处理
	// 定义指针 end，向后走 batchNum - 1 步，最后再让 span 指向剩下的链表的头结点，即 end 的下一个节点
	start = span->s_freeList;
	end = start;
	size_t i = 0;
	size_t actualNum = 0;	// 实际获取到了多少个内存对象
	while(i < batchNum - 1 && *(void**)end != nullptr)
	{
		end = *(void**)end;
		i++, actualNum++;
	}
	span->s_freeList = *(void**)end;
	*(void**)end = nullptr;		// end 指向为空
	
	_spanLists[index]._mutex.unlock();	// 解锁
	
	return actualNum;
}