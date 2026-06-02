// #include "ObjectPool.h"
#include "ConcurrentAlloc.h"

void Alloc1()
{
	for (size_t i = 0; i < 5; i++)
	{
		void *ptr = ConcurrentAlloc(6);		// 每次申请 6 byte
	}
}

void Alloc2()
{
	for (size_t i = 0; i < 5; i++)
	{
		void* ptr = ConcurrentAlloc(7);		// 每次申请 7 byte
	}
}

void TLSTest()		// 测试 TLS，多线程
{
	std::thread t1(Alloc1);
	std::thread t2(Alloc2);

	// 线程等待
	t1.join();
	t2.join();
}

// 对当前的实现的内存池进行测试
void TestConcurrentAlloc()
{
	void* p1 = ConcurrentAlloc(6);
	void* p2 = ConcurrentAlloc(7);
	void* p3 = ConcurrentAlloc(8);
}

// 测试地址的转换
void TestAddressShift()
{
	PAGE_ID id1 = 2000, id2 = 2001;
	void* p1 = (void*)(id1 << PAGE_SHIFT);
	void* p2 = (void*)(id2 << PAGE_SHIFT);
	cout << id1 << " " << p1 << endl;
	cout << id2 << " " << p2 << endl;

	while (p1 < p2)
	{
		cout << (void*)p1 << ": " << ((PAGE_ID)p1 >> PAGE_SHIFT) << endl;
		cout << (void*)p2 << ": " << ((PAGE_ID)p2 >> PAGE_SHIFT) << endl;
	}
}

void BigAlloc()
{
	void* p1 = ConcurrentAlloc(257 * 1024);
	ConcurrentFree(p1);

	void* p2 = ConcurrentAlloc(129 * 8 * 1024);
	ConcurrentFree(p2);
}

void MultiThreadAlloc1()
{

}

void TestMultiThread()
{
	std::thread t1();
}

//int main()
//{
//	// TestObjectPool();	// 由结果可知，内存池比平常的 new，效率大概快 3 倍
//	// TLSTest();
//	// TestAddressShift();
//	// BigAlloc();
//
//
//	return 0;
//}


//#include <iostream>
//#include <thread>
//#include <vector>
//#include <chrono>
//#include <mutex>
//#include <atomic>
//
//using namespace std;
//using namespace chrono;
//
//mutex mtx;
//const int THREAD_NUM = 4;      // 线程数
//const int LOOP_COUNT = 1000000; // 每个线程的循环次数
//const int INNER_WORK = 10;      // 每次循环内部的工作量
//
//// 方案1：循环内加锁
//void inner_lock(int& counter)
//{
//    for (int i = 0; i < LOOP_COUNT; ++i)
//    {
//        lock_guard<mutex> lock(mtx);  // 每次循环都加锁解锁
//        counter++;
//
//        // 模拟一些轻量级工作
//        for (int j = 0; j < INNER_WORK; ++j)
//        {
//            volatile int tmp = j * j;
//        }
//    }
//}
//
//// 方案2：循环外加锁
//void outer_lock(int& counter)
//{
//    lock_guard<mutex> lock(mtx);  // 只加一次锁
//    for (int i = 0; i < LOOP_COUNT; ++i)
//    {
//        counter++;
//
//        // 模拟相同的工作量
//        for (int j = 0; j < INNER_WORK; ++j)
//        {
//            volatile int tmp = j * j;
//        }
//    }
//}
//
//// 方案3：使用原子变量作为对比（无锁）
//void atomic_add(atomic<int>& counter)
//{
//    for (int i = 0; i < LOOP_COUNT; ++i)
//    {
//        counter++;
//
//        for (int j = 0; j < INNER_WORK; ++j)
//        {
//            volatile int tmp = j * j;
//        }
//    }
//}
//
//// 测试函数
//template<typename Func, typename... Args>
//double test_performance(Func func, Args&&... args)
//{
//    vector<thread> threads;
//    auto start = high_resolution_clock::now();
//
//    for (int i = 0; i < THREAD_NUM; ++i)
//    {
//        threads.emplace_back(func, ref(args)...);
//    }
//
//    for (auto& t : threads)
//    {
//        t.join();
//    }
//
//    auto end = high_resolution_clock::now();
//    duration<double> elapsed = end - start;
//    return elapsed.count();
//}
//
//int main()
//{
//    cout << "========== 加锁方案性能对比测试 ==========\n";
//    cout << "线程数: " << THREAD_NUM << ", 每个线程循环次数: " << LOOP_COUNT << "\n\n";
//
//    // 测试循环内加锁
//    int counter1 = 0;
//    double time1 = test_performance(inner_lock, counter1);
//    cout << "方案1 - 循环内加锁:\n";
//    cout << "  耗时: " << time1 << " 秒\n";
//    cout << "  最终结果: " << counter1 << " (预期: " << THREAD_NUM * LOOP_COUNT << ")\n\n";
//
//    // 测试循环外加锁
//    int counter2 = 0;
//    double time2 = test_performance(outer_lock, counter2);
//    cout << "方案2 - 循环外加锁:\n";
//    cout << "  耗时: " << time2 << " 秒\n";
//    cout << "  最终结果: " << counter2 << " (预期: " << THREAD_NUM * LOOP_COUNT << ")\n\n";
//
//    // 测试原子变量（无锁但原子操作）
//    atomic<int> counter3(0);
//    double time3 = test_performance(atomic_add, counter3);
//    cout << "方案3 - 原子变量 (参考对比):\n";
//    cout << "  耗时: " << time3 << " 秒\n";
//    cout << "  最终结果: " << counter3.load() << " (预期: " << THREAD_NUM * LOOP_COUNT << ")\n\n";
//
//    // 性能分析
//    cout << "========== 性能分析 ==========\n";
//    cout << "循环内加锁 vs 循环外加锁:\n";
//    cout << "  性能差距: " << (time1 / time2) << " 倍\n";
//
//    if (time1 > time2 * 5)
//    {
//        cout << "  结论: 循环外加锁效率远高于循环内加锁！\n";
//        cout << "  原因: 每次加锁解锁都有系统调用开销，循环内加锁会产生"
//            << THREAD_NUM * LOOP_COUNT << "次加锁解锁操作\n";
//    }
//
//    cout << "\n额外测试 - 不同循环次数的影响:\n";
//
//    // 测试不同循环次数的影响
//    vector<int> test_loops = { 1000, 10000, 100000, 1000000 };
//
//    cout << "循环次数\t循环内加锁(s)\t循环外加锁(s)\t性能比\n";
//    for (int loop : test_loops)
//    {
//        int c1 = 0, c2 = 0;
//
//        auto start1 = high_resolution_clock::now();
//        {
//            vector<thread> ts;
//            for (int i = 0; i < THREAD_NUM; ++i)
//                ts.emplace_back([&c1, loop]() {
//                for (int j = 0; j < loop; ++j) {
//                    lock_guard<mutex> lock(mtx);
//                    c1++;
//                }
//                    });
//            for (auto& t : ts) t.join();
//        }
//        auto end1 = high_resolution_clock::now();
//        double t1 = duration<double>(end1 - start1).count();
//
//        auto start2 = high_resolution_clock::now();
//        {
//            vector<thread> ts;
//            for (int i = 0; i < THREAD_NUM; ++i)
//                ts.emplace_back([&c2, loop]() {
//                lock_guard<mutex> lock(mtx);
//                for (int j = 0; j < loop; ++j)
//                    c2++;
//                    });
//            for (auto& t : ts) t.join();
//        }
//        auto end2 = high_resolution_clock::now();
//        double t2 = duration<double>(end2 - start2).count();
//
//        cout << loop << "\t\t"
//            << t1 << "\t\t" << t2 << "\t\t"
//            << (t1 / t2) << "\n";
//    }
//
//    return 0;
//}