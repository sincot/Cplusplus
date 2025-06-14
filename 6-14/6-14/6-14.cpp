#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <assert.h>

using namespace std;

//int main()
//{
	// 创建 vector 对象
	/*
	// v1 使用了 无参的构造函数初始化
	vector<int> v1;
	// v2 使用了 带参的构造函数初始化
	vector<int> v2(10, 2);
	// v3 使用了 迭代器区间初始化
	vector<int> v3(v2.begin(), v2.end());
	// v4 使用了 拷贝构造函数初始化
	vector<int> v4(v2);
	*/

	// 遍历 vector 对象
	/*
	// 第一种方法：下标[ ] 方法
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	// 第二种方法：迭代器方法
	vector<int>::iterator i1 = v2.begin();
	while (i1 != v2.end())
	{
		cout << (*i1) << " ";
		i1++;
	}
	cout << endl;

	// 第三种方法：范围 for 方法
	for (auto& e : v2)
	{
		cout << e << " ";
	}
	*/

	// 检验在 vs 编译器下 vector 的扩容方法
	/*
	vector<int> v;
	size_t old = v.capacity();
	cout << "capacity = " << v.capacity() << endl;
	cout << endl;

	for (size_t i = 0; i < 100; i++)
	{
		v.push_back('*');
		if (v.capacity() != old)
		{
			cout << "newcapacity = " << v.capacity() << endl;
		}

		old = v.capacity();
	}
	*/

	/*vector<int> v(10, 2);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 头插
	v.insert(v.begin(), 5);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 下标为5的位置插入
	v.insert(v.begin() + 5, 100);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	*/

	/*vector<int> v(10, 2);
	v.insert(v.begin() + 4, 5);
	// 查找
	auto it = find(v.begin(), v.end(), 5);
	// 在值为5的位置处插入数据
	if (it != v.end())
	{
		v.insert(it, 100);
	}
	// 打印
	for (auto& e : v)
	{
		cout << e << " ";
	}*/

	/*vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 删除一个数据
	v.erase(v.begin() + 4);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 删除一段数据
	v.erase(v.begin() + 2, v.begin() + 6);
	for (auto& e : v)
	{
		cout << e << " ";
	}*/

//	return 0;
//}

void func1()
{
	/*vector<string> v;
	v.push_back("hello");
	v.push_back(" world");
	v.push_back(" and");
	v.push_back(" linux");

	for (const auto& e : v)
	{
		cout << e;
	}*/

	//auto il1 = { 10, 20, 30 };
	////cout << typeid(il1).name() << endl;
	//auto il2 = { 'h', 'c'};
	////cout << typeid(il2).name() << endl;
	//for (auto& e : il1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//for (auto& e : il2)
	//{
	//	cout << e << " ";
	//}

	/*vector<int> v1({ 10, 20, 30 });
	vector<char> v2({ 'n', 'e', 'w' });*/

	/*vector<int> v1 = { 10, 20, 30 };
	vector<char> v2 = { 'n', 'e', 'w' };*/

	/*
	// C语言开辟规整的二维数组
	// 开辟一个指针数组
	int row; // 行数
	int col; // 列数
	int** aa = (int**)malloc(sizeof(int*) * col);
	for (size_t i = 0; i < row; i++)
	{
		// 开辟每行的内存空间
		aa[i] = (int*)malloc(sizeof(int) * col);
	}
	*/

	/*
	// C++ 开辟规整的二维数组
	vector<vector<int>> vv;
	int row; // 行数
	//开辟一个 vector ,vector 的每行数据是空 vector 容器
	vv.resize(row, vector<int>());
	// 给每行开辟空间
	for (size_t i = 0; i < row; i++)
	{
		vv[i].resize(row);
	}

	// 访问二维数组
	for (size_t i = 0; i < vv.size(); i++) 	// 访问行
	{
		for (size_t j = 0; i < vv[i].size(); j++) // 访问列
		{
			cout << vv[i][j] << endl;
			// 这里的 vv[i][j]实际上是这样 vv.operator[](i).operator[](j)
		}
	}
	*/
}


//// vector 的模板
//template<class T>
//class vector
//{
//
//private:
//	T*     m_a;
//	size_t m_size;
//	size_t m_capacity;
//};
//
//// 把 T 实例化为 int
//class vector<int>
//{
//
//private:
//	int*   m_a;
//	size_t m_size;
//	size_t m_capacity;
//};
//
//// 把 T 实例化为 vector<int>
//class vector<vector<int>>
//{
//
//private:
//	 vector<int>* m_a;
//	       size_t m_size;
//	       size_t m_capacity;
//};

namespace AY
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		// 无参的构造函数
		vector()
			: m_start(nullptr)
			, m_finish(nullptr)
			, m_end_of_storage(nullptr)
		{}

		// reserve 函数
		void reserve(size_t n = 0)
		{
			if (n > capacity())
			{
				// 提前更新 size 数据
				size_t old_size = size();
				// 开辟新空间
				T* tmp = new T[n];

				// 拷贝旧数据
				// 检验数组的数据是否为0
				if (m_start != NULL)
				{
					memcpy(tmp, m_start, old_size);
					// 释放旧空间
					delete[] m_start;
				}

				// 更新变量的数据
				m_start = tmp;
				m_finish = m_start + old_size;
				m_end_of_storage = m_start + n;
			}
		}

		// size 函数
		size_t size() const
		{
			return m_finish - m_start;
		}

		// capacity 函数
		size_t capacity() const
		{
			return m_end_of_storage - m_finish;
		}

		// push_back 函数
		void push_back(const T& x)
		{
			if (m_finish == m_end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}

			// finish 指向的是有效字符的末尾
			*m_finish = x;
			++m_finish;
		}

		// operator[] 函数 —— 普通版本
		T& operator[](size_t pos)
		{
			// 检验 pos 是否合法
			assert(pos < size());

			return m_start[pos];
		}

		// operator[] 函数 —— const 版本
		const T& operator[](size_t pos) const
		{
			// 检验 pos 是否合法
			assert(pos < size());

			return m_start[pos];
		}

		// begin 函数
		iterator begin()
		{
			return m_start;
		}

		// end 函数
		iterator end()
		{
			return m_finish;
		}

		// begin 函数 —— const 版本
		const_iterator begin() const
		{
			return m_start;
		}

		// end 函数 —— const 版本
		const_iterator end() const
		{
			return m_finish;
		}

	private:
		iterator m_start;
		iterator m_finish;
		iterator m_end_of_storage;
	};

}

int main()
{
	AY::vector<int> v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}


	return 0;
}

