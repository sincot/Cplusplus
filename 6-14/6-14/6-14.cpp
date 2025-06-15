#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <assert.h>

using namespace std;

//int main()
//{
	// ���� vector ����
	/*
	// v1 ʹ���� �޲εĹ��캯����ʼ��
	vector<int> v1;
	// v2 ʹ���� ���εĹ��캯����ʼ��
	vector<int> v2(10, 2);
	// v3 ʹ���� �����������ʼ��
	vector<int> v3(v2.begin(), v2.end());
	// v4 ʹ���� �������캯����ʼ��
	vector<int> v4(v2);
	*/

	// ���� vector ����
	/*
	// ��һ�ַ������±�[ ] ����
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	// �ڶ��ַ���������������
	vector<int>::iterator i1 = v2.begin();
	while (i1 != v2.end())
	{
		cout << (*i1) << " ";
		i1++;
	}
	cout << endl;

	// �����ַ�������Χ for ����
	for (auto& e : v2)
	{
		cout << e << " ";
	}
	*/

	// ������ vs �������� vector �����ݷ���
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

	// ͷ��
	v.insert(v.begin(), 5);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// �±�Ϊ5��λ�ò���
	v.insert(v.begin() + 5, 100);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	*/

	/*vector<int> v(10, 2);
	v.insert(v.begin() + 4, 5);
	// ����
	auto it = find(v.begin(), v.end(), 5);
	// ��ֵΪ5��λ�ô���������
	if (it != v.end())
	{
		v.insert(it, 100);
	}
	// ��ӡ
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

	// ɾ��һ������
	v.erase(v.begin() + 4);
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// ɾ��һ������
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
	// C���Կ��ٹ����Ķ�ά����
	// ����һ��ָ������
	int row; // ����
	int col; // ����
	int** aa = (int**)malloc(sizeof(int*) * col);
	for (size_t i = 0; i < row; i++)
	{
		// ����ÿ�е��ڴ�ռ�
		aa[i] = (int*)malloc(sizeof(int) * col);
	}
	*/

	/*
	// C++ ���ٹ����Ķ�ά����
	vector<vector<int>> vv;
	int row; // ����
	//����һ�� vector ,vector ��ÿ�������ǿ� vector ����
	vv.resize(row, vector<int>());
	// ��ÿ�п��ٿռ�
	for (size_t i = 0; i < row; i++)
	{
		vv[i].resize(row);
	}

	// ���ʶ�ά����
	for (size_t i = 0; i < vv.size(); i++) 	// ������
	{
		for (size_t j = 0; i < vv[i].size(); j++) // ������
		{
			cout << vv[i][j] << endl;
			// ����� vv[i][j]ʵ���������� vv.operator[](i).operator[](j)
		}
	}
	*/
}


//// vector ��ģ��
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
//// �� T ʵ����Ϊ int
//class vector<int>
//{
//
//private:
//	int*   m_a;
//	size_t m_size;
//	size_t m_capacity;
//};
//
//// �� T ʵ����Ϊ vector<int>
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

		// �޲εĹ��캯��
		vector()
			: m_start(nullptr)
			, m_finish(nullptr)
			, m_end_of_storage(nullptr)
		{}

		// reserve ����
		void reserve(size_t n = 0)
		{
			if (n > capacity())
			{
				// ��ǰ���� size ����
				size_t old_size = size();
				// �����¿ռ�
				T* tmp = new T[n];

				// ����������
				// ��������������Ƿ�Ϊ0
				if (m_start != NULL)
				{
					memcpy(tmp, m_start, old_size);
					// �ͷžɿռ�
					delete[] m_start;
				}

				// ���±���������
				m_start = tmp;
				m_finish = m_start + old_size;
				m_end_of_storage = m_start + n;
			}
		}

		// size ����
		size_t size() const
		{
			return m_finish - m_start;
		}

		// capacity ����
		size_t capacity() const
		{
			return m_end_of_storage - m_finish;
		}

		// push_back ����
		void push_back(const T& x)
		{
			if (m_finish == m_end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}

			// finish ָ�������Ч�ַ���ĩβ
			*m_finish = x;
			++m_finish;
		}

		// operator[] ���� ���� ��ͨ�汾
		T& operator[](size_t pos)
		{
			// ���� pos �Ƿ�Ϸ�
			assert(pos < size());

			return m_start[pos];
		}

		// operator[] ���� ���� const �汾
		const T& operator[](size_t pos) const
		{
			// ���� pos �Ƿ�Ϸ�
			assert(pos < size());

			return m_start[pos];
		}

		// begin ����
		iterator begin()
		{
			return m_start;
		}

		// end ����
		iterator end()
		{
			return m_finish;
		}

		// begin ���� ���� const �汾
		const_iterator begin() const
		{
			return m_start;
		}

		// end ���� ���� const �汾
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

