#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <algorithm>
#include <string>

using namespace std;

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
		{
		}

		// 析构函数
		~vector()
		{
			if (m_start != nullptr)
			{
				delete[] m_start;
				m_start = m_finish = m_end_of_storage = nullptr;
			}
		}

		// 拷贝构造函数
		vector(const vector<int>& x)
			: m_start(nullptr)
			, m_finish(nullptr)
			, m_end_of_storage(nullptr)
		{
			// 开辟新空间，更新数据
			reserve(x.capacity());

			// 拷贝数据
			for (auto& e : x)
			{
				push_back(e);
			}
		}

		// 使用迭代器区间初始化
		/*
		vector(iterator first, iterator last)
		{
			// 使用迭代器
			while (first != last)
			{
				// 将数据尾插至 *this 对象中
				push_back(*first);
				++first;
			}
		}
		*/

		// 使用迭代器区间初始化
		template <class InputIterator, 
			      enable_if_t<_Is_iterator_v<InputIterator>, int> = 0>
		vector(InputIterator first, InputIterator last)
		{
			// 使用迭代器
			while (first != last)
			{
				// 将数据尾插至 *this 对象中
				push_back(*first);
				++first;
			}
		}

		// 使用 n 个 val 值初始化
		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}

		// 初始化列表初始化（花括号初始化）
		vector(initializer_list<T> il)
		{
			for (auto& e : il)
			{
				// 这里实际上是 this->push_back(e)
				push_back(e);
			}
		}
		
		// swap 函数
		void swap(vector<T>& x)
		{
			std::swap(m_start, x.m_start);
			std::swap(m_finish, x.m_finish);
			std::swap(m_end_of_storage, x.m_end_of_storage);
		}

		// 赋值重载函数
		vector& operator= (vector<T>& x)
		{
			swap(x);

			return *this;
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

		// reserve 函数
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				// 开辟新空间
				T* tmp = new T[n];

				// 判断数组中的数据是否为0
				if (m_start != nullptr)
				{
					// 拷贝旧数据
					//memcpy(tmp, m_start, sizeof(T) * old_size);
					for (size_t i = 0; i < old_size; i++)
					{
						tmp[i] = m_start[i];
					}
					// 释放旧空间
					delete[] m_start;
				}

				// 更新数据
				m_start = tmp;
				m_finish = m_start + old_size;
				m_end_of_storage = m_start + n;
			}
		}

		// push_back 函数
		void push_back(const T& val)
		{
			// 判断是否需要扩容
			if (m_finish == m_end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}

			// 扩容完毕后，插入数据
			*m_finish = val;
			// 有效数据个数增加 1
			++m_finish;
		}

		// 普通版本的 operator[ ] 函数
		T& operator[](size_t n)
		{
			// 判断位置 n 是否合法
			assert(n < size());

			return m_start[n];
		}

		// const 版本的 operator[ ] 函数
		const T& operator[](size_t n) const
		{
			// 判断位置 n 是否合法
			assert(n < size());

			return m_start[n];
		}

		// 普通版本的 begin 函数
		iterator begin()
		{
			return m_start;
		}

		// 普通版本的 end 函数
		iterator end()
		{
			return m_finish;
		}

		// const 版本的 begin 函数
		const_iterator begin() const
		{
			return m_start;
		}

		// const 版本的 end 函数
		const_iterator end() const
		{
			return m_finish;
		}

		// empty 函数
		bool empty() const
		{
			return m_start == m_finish;
		}

		// pop_back 函数
		void pop_back()
		{
			// 判断有效数据个数是否为 0
			assert(!empty());

			// 有效数据个数减少 1 
			--m_finish;
		}

		// insert 函数
		iterator insert(iterator pos, const T& val)
		{
			// 判断 pos 迭代器的合法性
			assert(pos >= m_start && pos <= m_finish);

			// 判断是否需要扩容
			if (m_finish == m_end_of_storage)
			{
				// 求得 pos 指向的位置的相对距离
				size_t offset = pos - m_start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				// 更新迭代器 pos 的指向
				pos = m_start + offset;
			}

			// 挪动数据
			iterator it = m_finish;
			while (it > pos)
			{
				*it = *(it - 1);
				it--;
			}

			// 插入数据
			*pos = val;

			// 有效数据个数加 1
			++m_finish;

			// 返回值为 pos
			return pos;
		}

		// erase 函数
		iterator erase(iterator pos)
		{
			// 检验 pos 迭代器位置的合法性
			assert(pos >= m_start && pos <= m_finish);

			// 挪动数据
			iterator it = pos;
			while (it != m_finish)
			{
				*it = *(it + 1);
				it++;
			}

			// 有效数据个数减 1 
			--m_finish;

			return pos;
		}

		// clear 函数
		void clear()
		{
			m_finish = m_start;
		}

		// resize 函数
		void resize(size_t n, T val = T())
		{
			// 当 n 大于有效数据个数
			if (n > size())
			{
				// 扩容
				reserve(n);

				// 将多出来的有效数据赋值为 val
				while (m_finish != m_start + n)
				{
					*m_finish = val;
					++m_finish;
				}
			}
			// 当 n 小于有效数据个数
			else
			{
				// 有效数据个数减至 n 
				m_finish = m_start + n;
			}
		}
	private:
		iterator m_start;
		iterator m_finish;
		iterator m_end_of_storage;
	};

}
