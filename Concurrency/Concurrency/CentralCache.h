#pragma once

#include "Share.h"

// 每个线程的 Thread Cache 对应的桶中没有内存对象了，都会从 Central Cache 获取
// 如何获取到 Central Cache 的对象 —— 单例模式（饿汉模式 和 懒汉模式） 
// 设置成单例的饿汉模式
class CentralCache
{
public:
	static CentralCache& GetInStance()		// 获取单例对象
	{
		return _sInst;
	}

	// 从 SpanList 中获取一个非空的 span
	Span* GetOneSpan(SpanList& list, size_t byte_size);

	// start 和 end 分别是从 Central Cache 获取的链表的头与尾
	// n：要多少个内存对象，byte_size：要的内存对象是多大
	size_t FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t byte_size);
private:
	SpanList _spanLists[NHASH_LISTS];	// Central Cache 的桶的数量与位置和 Thread Cache 的数量与位置是相对应的

	// Central Cache 的每个桶是加上锁的，既然如此，直接在 SpanList 结构中定义一把锁

private:
	// 不让其它线程随意的创建单例对象 —— 构造函数设置成私有的
	CentralCache() {}
	
	// 避免线程获取到单例对象后，拷贝构造单例对象 —— 拷贝构造设置成私有的
	CentralCache(const CentralCache&) = delete;

	static CentralCache _sInst;		// 一定要在 .cpp 中定义，定义在 .h 中，会被多个 .cpp 包含，就失去单例模式要达到的效果
};

// Central Cache 也是一个哈希桶结构，与 Thread Cache 是类似的，不同的是 Thread Cache 按照对齐规则下挂载的是切好的小内存对象
// Central Cache 中定义了管理大块对象的结构 —— span，Central Cache 按照对齐规则下挂载的是大块内存 span，span 又被切成小对象
// 有的桶下挂载多个span，有的桶下没有span。桶下的哪些span是有小对象，是区分不清的，因为内存对象有来有回
// Thread Cache 中对应桶位置下的内存对象多了，就会还回来。Central Cache 中对应同位置下的内存对象不足，从 Page Cache 获取
// Central Cache 中桶下挂载的 span 设计成是双向链表，便于 span 归还给 Page Cache