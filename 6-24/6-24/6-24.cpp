#include "6-24.h"
#include <vector>

namespace AY
{
	void test1()
	{
		/*vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int> v2 = v1;
		for (auto& e : v2)
		{
			cout << e << " ";
		}*/

		/*string str1("123456789024680");
		vector<int> v1(str1.begin(), str1.end());
		for (auto& e : v1)
		{
			cout << e << " ";
		}*/

		/*vector<int> v2(10, 1);
		for (auto& e : v2)
		{
			cout << e << " ";
		}*/

		/*vector<size_t> v2(10, 2);
		for (auto& e : v2)
		{
			cout << e << " ";
		}*/
	}

	void test2()
	{
		/*vector<int> v1 = { 2, 4, 6, 8, 0 };
		vector<char> v2 = { 'c', 'p', 'p' };

		for (auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto& e : v2)
		{
			cout << e << " ";
		}
		cout << endl;*/

		/*vector<int> v1(10, 2);
		vector<int> v2;
		v2.swap(v1);

		for (auto& e : v2)
		{
			cout << e << " ";
		}*/

		/*vector<int> v1(10, 4);
		vector<int> v2(v1.begin() + 2, v1.end() - 2);
		for (auto& e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		v2 = v1;
		for (auto& e : v2)
		{
			cout << e << " ";
		}
		cout << endl;*/
	}

	void test3()
	{
		/*vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		auto it = find(v.begin(), v.end(), 4);
		if (it != v.end())
		{
			v.erase(it);
		}

		for (auto& e : v)
		{
			cout << e << " ";
		}*/

		/*v.insert(v.begin(), 10);
		v.insert(v.begin() + 2, 30);*/
		/*v.erase(v.end());
		for (auto& e : v)
		{
			cout << e << " ";
		}*/

		/*
		auto it = find(v.begin(), v.end(), 4);
		if (it != v.end())
		{
			v.insert(it, 400);
			*it = 200;
		}

		for (auto& e : v)
		{
			cout << e << " ";
		}
		*/
	}

	void test4()
	{
		/*vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(4);
		v.push_back(5);
		
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				it++;
			}
		}

		for (auto& e : v)
		{
			cout << e << " ";
		}*/

		vector<string> v;
		v.push_back("1234567890");
		v.push_back("2345678900");
		v.push_back("3456789000");
		v.push_back("4567890000");
		v.push_back("5678900000");

		for (auto& e : v)
		{
			cout << e << endl;
		}
	}
}

int main()
{
	//AY::test1();
	//AY::test2();
	//AY::test3();
	AY::test4();

    /*vector<int> v1({ 1, 2, 3, 4, 5 });
	vector<char> v2({ 'w', 'o', 'r', 'l', 'd' });
	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto& e : v2)
	{
		cout << e << " ";
	}*/

	/*vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<char> v2 = { 'w', 'o', 'r', 'l', 'd' };*/

	/*vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<char> v2{ 'w', 'o', 'r', 'l', 'd' };*/

	return 0;
}