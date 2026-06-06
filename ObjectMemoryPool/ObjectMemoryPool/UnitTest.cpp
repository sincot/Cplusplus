#include "ObjectPool.h"
#include "ConcurrentAlloc.h"


void Alloc1()
{
	for (size_t i = 0; i < 5; i++)
	{
		void* ptr = ConcurrentAlloc(6);
	}
}

void Alloc2()
{
	for (size_t i = 0; i < 5; i++)
	{
		void* ptr = ConcurrentAlloc(9);
	}
}

void TestObjectPool()
{
	std::thread t1(Alloc1);
	std::thread t2(Alloc2);
	
	t1.join();
	t2.join();
}

int main()
{
	TestObjectPool();
	return 0;
}