#include "9_20.h"

namespace AY
{
	void test1()
	{
		AY::list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);
		//l1.insert(l1.begin(), 100);
		//l1.erase(l1.begin());
		//l1.clear();

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			++it;
		}
	}

	struct XHM
	{
		int s_left;
		int s_right;

		XHM(int left = 0, int right = 0)
			: s_left(left)
			, s_right(right)
		{}
	};
	
	void test2()
	{
		AY::list<XHM> lt;
		lt.push_back({1,2});
		lt.push_back({2,3});
		lt.push_back({3,4});
		lt.push_back({4,5});
		lt.push_back({5,6});

		auto it = lt.begin();
		while (it != lt.end())
		{
			cout << (*it).s_left << ":" << (*it).s_right << endl;
			++it;
		}
	}

	void test3()
	{
		AY::list<XHM> lt;
		lt.push_back({ 1,2 });
		lt.push_back({ 2,3 });
		lt.push_back({ 3,4 });
		lt.push_back({ 4,5 });
		lt.push_back({ 5,6 });

		auto it = lt.begin();
		while (it != lt.end())
		{
			cout << it->s_left << ":" << it->s_right << endl;
			++it;
		}
	}
	/*void Print(list<int> lt)
	{
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
	}*/

	template<class T>
	void print(const list<T>& lt)
	{
		typename list<T>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	template<class T>
	void print(const list<T>& lt)
	{
		auto it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}

int main()
{
	AY::test1();
	//AY::test2();
	//AY::test3();

	return 0;
}