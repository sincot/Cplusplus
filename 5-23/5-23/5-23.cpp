#include <iostream>
#include <vector>

using namespace std;

void func1()
{
	/*
	// 检验 vector 在 Vs 中的扩容方式
	vector<int> v1;
	// 保留原来的capacity的大小
	size_t old = v1.capacity();
	cout << "capacity = " << old << endl;
	for (size_t i = 0; i < 100; i++)
	{
		v1.push_back(i);
		if (v1.capacity() != old)
		{
			cout << "caapcity = " << v1.capacity() << endl;
			old = v1.capacity();
		}
	}
	*/

	/*
	// 头插
	vector<int> v;
	v.insert(v.begin(), 2);
	// 尾插
	v.insert(v.end(), 3);
	// 中间插入
	v.insert(v.begin() + 1, 4);

	for (auto e : v)
	{
		cout << e << " ";
	}
	*/

	// vector 对象的初始化
	// 调用了vector的构造函数
	vector<int> v1({ 10, 20, 30 });

	// 隐式类型转换
	vector<int> v2 = { 10, 20, 30 };

}

struct A
{
	A(int a1, int a2)
		:m_a1(a1)
		, m_a2(a2)
	{}

	int m_a1;
	int m_a2;
};

void func2()
{
	// 插入数据
	vector<A> v1;
	A aa1(10, 10);
	v1.push_back(aa1);

	// 匿名对象
	vector<A> v2;
	v2.push_back(A(20, 20));

	// 隐式类型转换
	vector<A> v3;
	v3.push_back({ 30, 30 });

	// 使用 emplace_back
	v2.emplace_back(aa1);
	v3.emplace_back(A(20, 20));
	// 传构造 A 的参数，效率较高
	v3.emplace_back(30, 30);

	// 访问
	vector<A>::iterator it2 = v2.begin();
	while (it2 != v2.end())
	{
		cout << it2->m_a1 << " " << it2->m_a2 << "\t";
		it2++;
	}
	cout << endl << endl;

	// 范围 for
	for (auto& e : v3)
	{
		cout << e.m_a1 << " " << e.m_a2 << "\t";
	}
	cout << endl << endl;

	//结构化绑定
	for (auto& [x, y] : v1)
	{
		cout << x << " " << y << "\t";
	}
}

int main()
{
	/*
	// 无参构造
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	// 带参构造 —— 用 10个1 来初始化 v2
	vector<int> v2(10, 1);

	// 迭代器区间
	vector<int> v3(v1.begin(), v1.end());

	// 三种遍历方式
	// 1. 下标加 [ ] 
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl << endl;

	// 2. 范围 for
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl << endl;

	// 3. 迭代器
	vector<int>::iterator vit2 = v2.begin();
	while (vit2 != v2.end())
	{
		cout << *vit2 << " ";
		vit2++;
	}
	*/

	//func1();
	func2();

	return 0;
}