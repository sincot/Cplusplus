#include <iostream>
#include <list>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

template <class T>
void Print(list<T> lt)
{
	for (auto& e : lt)
	{
		cout << e << " ";
		e++;
	}
	cout << endl;
}

void test1()
{
	list<int> lt1; // 无参初始化
	list<int> lt2(10, 2); // n 个 val 值初始化
	Print(lt2);
	vector<int> v = { 1, 3, 5, 7, 9 };
	list<int>lt3(v.begin(), v.end()); // 迭代器区间初始化
	Print(lt3);
	list<int> lt4 = { 1, 2, 3, 4, 5 }; // 大括号初始化
	Print(lt4);


	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	list<int> lt5(arr + 2, arr + 7);
	Print(lt5);
}

void test2()
{
	srand(time(0));
	const int N = 1000000;

	vector<int> v;
	list<int> lt;

	for (int i = 0; i < N; i++)
	{
		auto e = rand() + i;
		v.push_back(e);
		lt.push_back(e);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	lt.sort();
	int end2 = clock();

	printf("vector sort：%d\n", end1 - begin1);
	printf("list sort：%d\n", end2 - begin2);
}

void test3()
{
	srand(time(0));
	const int N = 1000000;

	list<int> lt1;
	list<int> lt2;

	for (int i = 0; i < N; i++)
	{
		auto e = rand() + i;
		lt1.push_back(e);
		lt2.push_back(e);
	}

	vector<int> v(lt1.begin(), lt1.end());
	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	lt2.sort();
	int end2 = clock();

	printf("list copy vector sort：%d\n", end1 - begin1);
	printf("list sort：%d\n", end2 - begin2);
}

void test4()
{
	/*list<int> lt1 = { 2,4,5,3,7,3,7,2,1,3 };
	Print(lt1);
	lt1.remove(3);
	Print(lt1);*/

	list<int>lt2 = { 2, 4, 6, 8, 0 };
	Print(lt2);
	auto it = find(lt2.begin(), lt2.end(), 0);
	lt2.splice(lt2.begin(), lt2, it);
	Print(lt2);
}

int main()
{
	//test2();
	//test3();
	//test4();

	return 0;
}