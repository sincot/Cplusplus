#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

namespace AY
{
	// vector 的底层构造
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		// 构造函数
		vector()
			: m_start(nullptr)
			, m_finish(nullptr)
			, m_end_of_storage(nullptr)
		{
		}

		// reserve 函数
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				// 将就空间中的数据拷贝到新空间中
				if (m_start != nullptr)
				{
					memcpy(tmp, m_start, sizeof(T) * size());
					delete[] m_start;
				}

				m_start = tmp;
				m_finish = m_start + old_size;
				m_end_of_storage = m_start + n;
			}
		}

		// operator[ ] 函数
		void operator[](size_t i)
		{
			assert(i < size());
			return m_start[i];
		}

		// size 函数
		size_t size() const
		{
			return m_finish - m_start;
		}

		// capacity 函数
		size_t capacity() const
		{
			return m_end_of_storage - m_start;
		}

		// push_back 函数
		void push_back(const T& x)
		{
			if (m_finish == m_end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*m_finish = x;
			++m_finish;
		}

		// 实现迭代器
		iterator begin()
		{
			return m_start;
		}

		iterator end()
		{
			return m_finish;
		}

	private:
		iterator m_start;           // 相当于 m_a
		iterator m_finish;          // 相当于 m_a + m_size
		iterator m_end_of_storage;  // 相当于 m_a + capacity
	};
}
