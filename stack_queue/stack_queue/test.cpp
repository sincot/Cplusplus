#include <iostream>
#include <queue>

using namespace std;

// 栈的使用
int main()
{
	//stack<int> st;
	//st.push(1);
	//st.push(5);
	//st.push(7);
	//st.push(3);
	//st.push(8);
	//st.push(2);

	//// 遍历
	//while (!st.empty()) //非空
	//{
	//	cout << st.top() << " ";
	//	st.pop();
	//}

	/*queue<int> q;
	q.push(8);
	q.push(3);
	q.push(1);
	q.push(4);
	q.push(7);
	q.push(6);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}*/

	// 仿函数使用 less
	priority_queue<int> pqless;
	pqless.push(4);
	pqless.push(7);
	pqless.push(3);
	pqless.push(9);
	pqless.push(5);

	while (!pqless.empty())
	{
		cout << pqless.top() << " ";
		pqless.pop();
	}
	cout << endl;

	// 仿函数使用 greater
	priority_queue<int, vector<int>, greater<int>> pqgreater;
	pqgreater.push(4);
	pqgreater.push(7);
	pqgreater.push(3);
	pqgreater.push(9);
	pqgreater.push(5);

	while (!pqgreater.empty())
	{
		cout << pqgreater.top() << " ";
		pqgreater.pop();
	}
	cout << endl;

	return 0;
}