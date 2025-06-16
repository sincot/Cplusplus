#include "vector.h"

namespace AY
{
	// 打印 vector 容器中的数据
	template<class Container>
	void Print(const Container& con)
	{
		for (auto e : con)
		{
			cout << e << " ";
		}

		cout << endl;
	}

	void test1()
	{
		/*vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.insert(v.begin() + 2, 100);

		for (auto& e : v)
		{
			cout << e << " ";
		}*/

		/*vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		auto it = find(v.begin(), v.end(), 3);
		if (it != v.end())
		{
			v.erase(it);
		}*/

		/*v.insert(v.begin() + 2, 10);
		v.insert(v.begin() + 3, 20);

		auto it = find(v.begin(), v.end(), 4);
		if (it != v.end())
		{
			v.insert(it, 100);
		}*/
	}

	void test2()
	{
		/*v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);*/

		/*vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		// 删除 v 中所有的偶数
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		// 打印
		Print(v);*/
	}

	void test3()
	{
		/*int i = 0;
		int j(1);
		char c('s');
		bool b(true);*/

		/*vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		
		vector<int> v1 = v;
		vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
		Print(v2);*/

		//Print(v1);

		/*v.resize(10, 20);
		Print(v);*/

		/*v.resize(3);
		Print(v);*/
	}

	void test4()
	{
		/*vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(2);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);*/

		/*vector<int> v2(v1.begin() + 1, v1.end() - 1);
		Print(v2);*/

		/*string str("hello world");
		vector<int> v(str.begin(), str.end());
		Print(v);*/

		/*vector<int> v1(10, 2);
		Print(v1);*/

		/*vector<size_t> v2(10, 4);
		Print(v2);*/

		/*string str("hello world");
		vector<int> v(str.begin(), str.end());
		vector<int> v2 = v;
		Print(v2);*/

		vector<string> v;
		v.push_back("1234567");
		v.push_back("2345678");
		v.push_back("3456789");
		v.push_back("4567890");
		v.push_back("5678900");

		Print(v);
	}
}

int main()
{
	//AY::test1();
	//AY::test2();
	//AY::test3();
	AY::test4();

	return 0;
}