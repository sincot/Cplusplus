#include "6-23.h"

namespace AY
{
	void test1()
	{
		// 调用无参的构造函数
		vector<int> v1;
		//vector<int> v2;
		// 尾插 4 个数据
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//v1.push_back(5);

		v1.insert(v1.begin() + 2, 100);

		for (auto& e : v1)
		{
			cout << e << " ";
		}

		/*v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();*/

		/*cout << v1.empty() << endl;
		cout << v2.empty() << endl;*/

		/*
		vector<int>::iterator it1 = v1.begin();
		while (it1 != v1.end())
		{
			(*it1)++;
			cout << *it1 << " ";
			it1++;
		}
		cout << endl;

		
		for (auto& e : v1)
		{
			e += 2;
			cout << e << " ";
		}
		cout << endl;

		
		vector<int>::const_iterator it2 = v1.begin();
		while (it2 != v1.end())
		{
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;

		for (const auto& e : v1)
		{
			cout << e << " ";
		}
		*/
		
		//// 打印
		//for (size_t i = 0; i < v1.size(); i++)
		//{
		//	cout << v1[i] << " ";
		//}
	}

	void test2()
	{
		vector<int> v2;

		/*v2.push_back(1);
		v2.push_back(2);
		v2.push_back(4);
		v2.push_back(5);
		v2.push_back(5);*/
		/*
		auto it = find(v2.begin(), v2.end(), 4);
		if (it != v2.end())
		{
			v2.insert(it, 100);
			*it = 20;
		}
		*/

		for (auto& e : v2)
		{
			cout << e << " ";
		}
	}

	void test3()
	{
		vector<int> v3;
		v3.reserve(50);

		for (size_t i = 0; i < 50; i++)
		{
			v3.push_back(i);
		}

		v3.resize(100, 100);

		for (auto& e : v3)
		{
			cout << e << " ";
		}
	}
}

int main()
{
	//AY::test1();
	//AY::test2();
	AY::test3();
	return 0;
}