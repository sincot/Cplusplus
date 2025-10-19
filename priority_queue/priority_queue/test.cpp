#include "priority_queue.h"
using namespace std;
#include <algorithm>
#include <iostream>

// 仿函数
template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

struct func
{
	bool operator()(int val)
	{
		return val % 2 == 0;
	}
};

int main()
{
	int arr[] = { 5, 3, 4, 2, 1, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// 查找第一个偶数
	auto it = find_if(arr, arr + n, func());
	cout << *it << " ";

	/*Less<int> lessfunc;
	cout << lessfunc(1, 2) << endl;*/

	int arr[] = { 8, 4, 9, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n, Less<int>());
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	sort(arr, arr + n, Greater<int>());
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	//// 栈不为空，就一直取栈顶元素
	//while (!st.empty())
	//{
	//	// 取栈顶元素
	//	cout << st.top() << " ";
	//	// 出栈顶元素
	//	st.pop();
	//}

	//// 队列不为空，就一直取队头元素
	//while (!q.empty())
	//{
	//	// 取队头元素
	//	cout << q.front() << " ";
	//	// 出队头元素
	//	q.pop();
	//}

	//AY::priority_queue<int> pq;
	//AY::priority_queue<int, std::deque<int>> pq;
	/*AY::priority_queue<int, vector<int>> pq;
	pq.push(4);
	pq.push(9);
	pq.push(3);
	pq.push(7);
	pq.push(5);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}*/


	return 0;
}