#pragma once

// 大家公共的头文件，包含一些常用的库和定义一些常用的类型
#include <iostream>
#include <thread>
#include <assert.h>
#include <mutex>
#include <algorithm>
#include <unordered_map>

using std::cout;
using std::endl;

static const size_t MAX_BYTES = 256 * 1024;		// 256KB
static const size_t NHASH_LISTS = 208;			// 哈希桶的数量
// 为什么 PageCache 中哈希桶的数量是 128？
// 最大的单个对象 256KB，假设 128 下挂载的页大小为 8KB，128*8 = 1024KB，可以切 4 段 span 给最大的单个对象
static const size_t NPAGES = 129;			// PageCache中哈希桶的数量 128, +1 是因为数组的下标从 0 开始
static const size_t PAGE_SHIFT = 13;		// 2^13 = 8KB 页的大小

// 不调用 malloc 函数，直接调用系统调用
// windows 下的是 VirtualAlloc
#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

inline static void* SystemAlloc(size_t kpage)
{
	// 获取系统页大小
#ifdef _WIN32
	SYSTEM_INFO si;
	GetSystemInfo(&si);
	size_t pageSize = si.dwPageSize;
#else
	size_t pageSize = sysconf(_SC_PAGESIZE);
#endif

	// 计算实际需要分配的字节数
	size_t size = kpage * pageSize;

#ifdef _WIN32
	void* ptr = VirtualAlloc(
		nullptr,						// 系统决定地址
		size,							// 分配大小
		MEM_COMMIT | MEM_RESERVE,		// 提交并预留
		PAGE_READWRITE					// 可读可写
	);
#else	// Linux
	void* ptr = mmap(
		nullptr,						// 系统选择地址
		size,							// 分配大小
		PROT_READ | PROT_WRITE,			// 可读可写
		MAP_PRIVATE | MAP_ANONYMOUS,	// 私有匿名映射
		-1,								// 无文件描述符
		0								// 偏移量0
	);

	if (ptr == MAP_FAILED) ptr = nullptr;
#endif
	if (ptr == nullptr)	throw std::bad_alloc();

	return ptr;
}

inline static void SystemFree(void* ptr)
{
	if (ptr == nullptr) return;

#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#elif defined(__linux__) || defined(__APPLE__)
	// Linux/Mac 使用 munmap 释放 mmap 分配的内存
	// 注意：munmap 需要知道内存大小，通常需要额外记录
	// 这里假设 ptr 是从 mmap 分配的，且大小已记录在其他地方
	munmap(ptr, 0);  // 实际使用中需要传递正确的大小
#else
	free(ptr);
#endif
}

// 管理切分好的小对象的自由链表
class FreeList
{
public:
	void Push(void* object)		// 插入一个内存对象
	{
		// 头插 —— 内存对象的前4/8bbyte用于存储下一个内存对象的地址
		*((void**)object) = _freeList;
		_freeList = object;
	}

	void* Pop()					// 弹出一个内存对象
	{
		// 头删 —— 前提得要有东西
		assert(_freeList);
		void* obj = _freeList;
		void* next = *((void**)_freeList);
		_freeList = next;

		return obj;
	}

	void PushRange(void* start, void* end, size_t n)		// 支持插入多个内存对象
	{
		// 头插一段链表
		//void* next = *((void**)end);	// 获取 end 指针指向的下个节点的地址
		//next = _freeList;	
		//_freeList = start;

		//_size += n;

		*((void**)end) = _freeList;  // 将 end 的 next 指向原链表头
		_freeList = start;           // 新链表头指向 start
		_size += n;
	}

	void* PopRange(void*& start, void*& end, size_t n)	// n 获取的链表的个数
	{
		assert(n <= _size);		// 若 n 小于 size，说明回收的逻辑是出现问题的
		start = _freeList, end = start;

		// 在链表中，取上 n 个节点
		for (size_t i = 0; i < n - 1; i++)
		{
			end = *(void**)end;		// 向后移动
		}

		_freeList = *(void**)end;
		*(void**)end = nullptr;	
		_size -= n;					// 链表的节点个数 -n

		return start;
	}

	bool Empty() { return _freeList == nullptr; }

	size_t& MaxSize() { return _maxSize; }		// 使用引用，为了修改 _maxSize 的值

	size_t Size() { return _size; }
private:
	void* _freeList = nullptr;
	size_t _maxSize = 1;	// 向 CentralCache 获取内存对象时，分配的内存对象
	size_t _size;			// 记录链表节点的个数
};

// 计算对象大小的对齐映射规则 —— 分段映射
// 以 8byte 对齐是最合适的，为什么？为了满足32和64位平台下不同的情况，取64位机器的标准，可以满足32位
// 1~8 映射 8，9~16映射16，17~24映射24。但是到最大 256 * 1024 / 8 = 32786，那么就需要建 32876 个链表
// 我们可以分段对齐，如下所示：
// 整体控制在最多10%左右的内碎片浪费
// [1,128]                    8byte对齐       freelist[0,16)		16 个自由链表
// [128+1,1024]               16byte对齐      freelist[16,72)		56 个自由链表
// [1024+1,8*1024]            128byte对齐     freelist[72,128)		56 个自由链表
// [8*1024+1,64*1024]         1024byte对齐    freelist[128,184)		56 个自由链表
// [64*1024+1,256*1024]       8*1024byte对齐  freelist[184,208)		24 个自由链表

// 之所以这样划分区域对齐，是为了减少内碎片的问题
// 129 按照 16byte 对齐，129+15 = 144，最多浪费 15byte，15 / 144 = 10.4%
// 1025 按照 128byte 对齐，1025+127 = 1152，最多浪费 127byte，127 / 1152 = 11%
// 8193 按照 1024byte 对齐，8193+1023 = 9216，最多浪费 1023byte，1023 / 9216 = 11% 
// 对齐越大，桶的数量越少
class SizeClass
{
public:
	//size_t _RoundUP(size_t size, size_t alignNum)	// 具体计算 size 对齐结果 alignNum 是对齐数
	//{
	//	size_t alignSize;	// 对齐后的结果
	//	// 如果 size 是 alignNum 对齐数的倍数，就不需要处理，正好是按 alignNumbyte 对齐
	//	if (size % alignNum != 0)
	//	{
	//		// size = 129, alignNum = 16, alignSize = 129 / 16 = 8 + 1 = 9 * 16 = 144 满足对齐结果
	//		alignSize = (size / alignNum + 1) * alignNum;
	//	}
	//	else
	//	{
	//		alignSize = size;	// 对齐后的结果就是 size 本身
	//	}

	//	return alignSize;	// 返回对齐的结果
	//}

	// 大佬实现的 —— 实现成静态的，它会被频繁的调用
	static inline size_t _RoundUP(size_t bytes, size_t alignNum)
	{
		// 例如 bytes = 9, alignNum = 16
		// 9 + 16 - 1 = 24 —— 11000，16 - 1 = 15 —— 01111 ~ —— 10000
		// 11000 & 10000 = 10000 = 16，对齐结果为 16
		// 使用逻辑运算替代算数运算，可以提高处理效率
		return ((bytes + alignNum - 1) & ~(alignNum - 1));
	}

	static inline size_t RoundUp(size_t size)			// 计算 size 对齐结果
	{
		if (size <= 128)				// 按 8byte 对齐
		{
			return _RoundUP(size, 8);
		}
		else if (size <= 1024)			// 按 16byte 对齐
		{
			return _RoundUP(size, 16);
		}
		else if (size <= 8*1024)		// 按 128byte 对齐
		{
			return _RoundUP(size, 128);
		}
		else if (size <= 64 * 1024)		// 按 1024byte 对齐
		{
			return _RoundUP(size, 1024);
		}
		else if (size <= 256 * 1024)	// 按 8*1024byte 对齐
		{
			return _RoundUP(size, 8*1024);
		}
		else  // 超过了 ThreadCache 所能分配的最大空间，这是不可能发生的事件
		{
			/*assert(false);
			return -1;*/

			// 依旧以 8KB 对齐
			return _RoundUP(size, 1 << PAGE_SHIFT);
		}
	}

	//size_t _Index(size_t bytes, size_t alignNum)
	//{
	//	if (bytes % alignNum == 0)	// 能够整除对齐数，对应的自由链表的下标就是，整除的结果-1
	//	{
	//		return bytes / alignNum - 1;
	//	}
	//	else
	//	{
	//		return bytes / alignNum;
	//	}
	//}



	// 大佬写的  align_shift 是对齐数是2的几次方，如 8byte -> 3, 128byte -> 7
	// 左移n位 —— *2^n, 右移n位 —— /2^n, -1 —— 下标从 0 开始
	static inline size_t _Index(size_t bytes, size_t align_shift)
	{
		return ((bytes + (1 << align_shift) - 1) >> align_shift) - 1;
	}

	static inline size_t Index(size_t bytes)	// 计算对齐的结果在哪个桶，从对应的桶中获取内存对象
	{
		assert(bytes <= MAX_BYTES);

		// 每个区域中的自由链表的数量是一定的 { 16, 56, 56, 56, 24 }
		// 划分成了多个区域，bytes减去前一个区域的范围，在根据对应的对齐数，计算出bytes在它所处的范围中的偏移量，然后加上前面的范围的自由链表个数，从而计算出bytes所处的自由链表
		static int group_array[4] = { 16, 56, 56, 56 };
		if (bytes <= 128)				// 按 8byte 对齐
		{
			return _Index(bytes, 3);
		}
		else if (bytes <= 1024)			// 按 16byte 对齐
		{
			return _Index(bytes - 128, 4) + group_array[0];
		}
		else if (bytes <= 8 * 1024)		// 按 128byte 对齐
		{
			return _Index(bytes - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (bytes <= 64 * 1024)		// 按 1024byte 对齐
		{
			return _Index(bytes - 8*1024, 10) + group_array[2] + group_array[1] + group_array[0];
		}
		else if (bytes <= 256 * 1024)	// 按 8*1024byte 对齐
		{
			return _Index(bytes - 64*1024, 13) + group_array[3] + group_array[2] + group_array[1] + group_array[0];
		}
		else
		{
			assert(false);
			return -2;
		}
	}

	// 慢开始反馈调节算法 —— 一次 thread cache 从中心缓存获取多少个对象，根据自己是多少字节的
	static size_t NumMoveSize(size_t size)
	{
		assert(size > 0);

		// [2, 512]，一次批量移动多少个对象的（慢启动）上限值
		// 小对象一次批量上限高，大对象一次批量上限低
		int num = MAX_BYTES / size;		// MAX_BYTES：256 * 1024 = 262144
		// 8 byte: 262144 / 8 = 32768 > 512, num = 512
		// 24 byte: 262144 / 24 = 10922 > 512, num = 512
		// 256 KB: 262144 / 262144 = 1 < 2, num = 2
		if (num < 2) num = 2;
		if (num > 512) num = 512;

		return num;
	}

	// 计算一次向 Page Cache 获取几个页
	static size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);		// 批量一次从 Central Cache 获取多少个对象，尽量满足批量的上限值
		// 假设一次批量计算出来是 512 个，512 * 单个对象的大小，算出要获取几页
		size_t npage = num * size;

		// 向右移动相当于除以 2^n 次方
		// 假设 size 为 8byte，512 * 8 / 2^13 = 0(0.5)
		// 假设 size 为 256KB，2 * 256 * 1024 / 2^13 = 64
		npage >>= PAGE_SHIFT;
		if (npage == 0) npage = 1;

		return npage;
	}
};

// 在 Win32 配置下，_WIN32 有定义，_WIN64 没有定义
// 在 x64 配置下，_WIN32 和 _WIN64 都有定义
// 在 Win32 下，进入 #ifdef _WIN32，不进入 #elif _WIN64
// 在 x64 下，进入 #ifdef _WIN32，不会进入 #elif _WIN64，本来是要进入 #elif _WIN64
// 因此以下的写法是不正确的，仅需将 _WIN64 和 _WIN32 调换一下顺序即可
//#ifdef _WIN32
//typedef size_t PAGE_ID
//#elif _WIN64
//typedef unsigned long long PAGE_ID
//#endif 

// 要实现跨平台性，一般都是使用条件编译完成的
#ifdef _WIN64
	typedef unsigned long long PAGE_ID;
#elif _WIN32
	typedef size_t PAGE_ID;
#elif __linux__
	typedef unsigned long PAGE_ID;  // Linux 内核中 pfn_t 就是 unsigned long
#endif


// 管理多个连续页的大块内存跨度结构 span
// 在32位平台下和64位平台下，页的数量是不一样的
// 32 位机器平台下：2^32 / 2^13(8KB) = 2^19 个页
// 64 位机器平台下：2^64 / 2^13(8KB) = 2^51 个页
struct Span
{
	PAGE_ID s_pageId = 0;			// 大块内存起始页的页号
	size_t s_n = 0;					// 页数

	// 带头的双向链表
	Span* s_next = nullptr;		
	Span* s_prev = nullptr;

	size_t s_use_count = 0;			// span 切成的小块内存，分配给 Thread Cache 的计数
	void* s_freeList = nullptr;		// 切好的小块内存的自由链表

	bool s_isUse = false;			// span 是否被使用，默认是 false
	size_t s_objSize = 0;				// 切好的小对象的大小
};

// 管理 span 的双向链表
class SpanList
{
public:
	SpanList()
	{ 
		_head = new Span; 
		_head->s_next = _head;
		_head->s_prev = _head;
	}

	// 支持迭代器遍历
	Span* Begin() { return _head->s_next; }
	Span* End() { return _head; }

	void Insert(Span* pos, Span* newSpan)	// 在 pos 位置插入 newSpan
	{
		assert(pos), assert(newSpan);
		Span* prev = pos->s_prev;
		// prev newSpan pos
		prev->s_next = newSpan;
		newSpan->s_next = pos;
		newSpan->s_prev = prev;
		pos->s_prev = newSpan;
	}

	void Erase(Span* pos)
	{
		assert(pos), assert(pos != _head);
		Span *prev = pos->s_prev, *next = pos->s_next;
		// prev pos next
		prev->s_next = next;
		next->s_prev = prev;
		// delete pos;  不要 delete 掉 pos 指向的内存空间，因为它还要还回来
	}

	void PushFront(Span* span)	{ Insert(Begin(), span); }	// 头插

	Span* PopFront()	// 头删
	{
		Span* front = _head->s_next;
		Erase(front);
		return front;
	}

	bool Empty() { return _head->s_next == _head;  }	// 只有头结点一个节点，那么 SpanList 就为空
private:
	Span* _head = nullptr;		// 头结点

public:
	std::mutex _mutex;			// 桶锁
};