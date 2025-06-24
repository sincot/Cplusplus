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

		// �޲εĹ��캯��
		vector()
			: m_start(nullptr)
			, m_finish(nullptr)
			, m_end_of_storage(nullptr)
		{
		}

		// ��������
		~vector()
		{
			if (m_start != nullptr)
			{
				delete[] m_start;
				m_start = m_finish = m_end_of_storage = nullptr;
			}
		}

		// �������캯��
		vector(const vector<int>& x)
			: m_start(nullptr)
			, m_finish(nullptr)
			, m_end_of_storage(nullptr)
		{
			// �����¿ռ䣬��������
			reserve(x.capacity());

			// ��������
			for (auto& e : x)
			{
				push_back(e);
			}
		}

		// ʹ�õ����������ʼ��
		/*
		vector(iterator first, iterator last)
		{
			// ʹ�õ�����
			while (first != last)
			{
				// ������β���� *this ������
				push_back(*first);
				++first;
			}
		}
		*/

		// ʹ�õ����������ʼ��
		template <class InputIterator, 
			      enable_if_t<_Is_iterator_v<InputIterator>, int> = 0>
		vector(InputIterator first, InputIterator last)
		{
			// ʹ�õ�����
			while (first != last)
			{
				// ������β���� *this ������
				push_back(*first);
				++first;
			}
		}

		// ʹ�� n �� val ֵ��ʼ��
		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}

		// ��ʼ���б��ʼ���������ų�ʼ����
		vector(initializer_list<T> il)
		{
			for (auto& e : il)
			{
				// ����ʵ������ this->push_back(e)
				push_back(e);
			}
		}
		
		// swap ����
		void swap(vector<T>& x)
		{
			std::swap(m_start, x.m_start);
			std::swap(m_finish, x.m_finish);
			std::swap(m_end_of_storage, x.m_end_of_storage);
		}

		// ��ֵ���غ���
		vector& operator= (vector<T>& x)
		{
			swap(x);

			return *this;
		}

		// size ����
		size_t size() const
		{
			return m_finish - m_start;
		}

		// capacity ����
		size_t capacity() const
		{
			return m_end_of_storage - m_start;
		}

		// reserve ����
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				// �����¿ռ�
				T* tmp = new T[n];

				// �ж������е������Ƿ�Ϊ0
				if (m_start != nullptr)
				{
					// ����������
					//memcpy(tmp, m_start, sizeof(T) * old_size);
					for (size_t i = 0; i < old_size; i++)
					{
						tmp[i] = m_start[i];
					}
					// �ͷžɿռ�
					delete[] m_start;
				}

				// ��������
				m_start = tmp;
				m_finish = m_start + old_size;
				m_end_of_storage = m_start + n;
			}
		}

		// push_back ����
		void push_back(const T& val)
		{
			// �ж��Ƿ���Ҫ����
			if (m_finish == m_end_of_storage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}

			// ������Ϻ󣬲�������
			*m_finish = val;
			// ��Ч���ݸ������� 1
			++m_finish;
		}

		// ��ͨ�汾�� operator[ ] ����
		T& operator[](size_t n)
		{
			// �ж�λ�� n �Ƿ�Ϸ�
			assert(n < size());

			return m_start[n];
		}

		// const �汾�� operator[ ] ����
		const T& operator[](size_t n) const
		{
			// �ж�λ�� n �Ƿ�Ϸ�
			assert(n < size());

			return m_start[n];
		}

		// ��ͨ�汾�� begin ����
		iterator begin()
		{
			return m_start;
		}

		// ��ͨ�汾�� end ����
		iterator end()
		{
			return m_finish;
		}

		// const �汾�� begin ����
		const_iterator begin() const
		{
			return m_start;
		}

		// const �汾�� end ����
		const_iterator end() const
		{
			return m_finish;
		}

		// empty ����
		bool empty() const
		{
			return m_start == m_finish;
		}

		// pop_back ����
		void pop_back()
		{
			// �ж���Ч���ݸ����Ƿ�Ϊ 0
			assert(!empty());

			// ��Ч���ݸ������� 1 
			--m_finish;
		}

		// insert ����
		iterator insert(iterator pos, const T& val)
		{
			// �ж� pos �������ĺϷ���
			assert(pos >= m_start && pos <= m_finish);

			// �ж��Ƿ���Ҫ����
			if (m_finish == m_end_of_storage)
			{
				// ��� pos ָ���λ�õ���Ծ���
				size_t offset = pos - m_start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				// ���µ����� pos ��ָ��
				pos = m_start + offset;
			}

			// Ų������
			iterator it = m_finish;
			while (it > pos)
			{
				*it = *(it - 1);
				it--;
			}

			// ��������
			*pos = val;

			// ��Ч���ݸ����� 1
			++m_finish;

			// ����ֵΪ pos
			return pos;
		}

		// erase ����
		iterator erase(iterator pos)
		{
			// ���� pos ������λ�õĺϷ���
			assert(pos >= m_start && pos <= m_finish);

			// Ų������
			iterator it = pos;
			while (it != m_finish)
			{
				*it = *(it + 1);
				it++;
			}

			// ��Ч���ݸ����� 1 
			--m_finish;

			return pos;
		}

		// clear ����
		void clear()
		{
			m_finish = m_start;
		}

		// resize ����
		void resize(size_t n, T val = T())
		{
			// �� n ������Ч���ݸ���
			if (n > size())
			{
				// ����
				reserve(n);

				// �����������Ч���ݸ�ֵΪ val
				while (m_finish != m_start + n)
				{
					*m_finish = val;
					++m_finish;
				}
			}
			// �� n С����Ч���ݸ���
			else
			{
				// ��Ч���ݸ������� n 
				m_finish = m_start + n;
			}
		}
	private:
		iterator m_start;
		iterator m_finish;
		iterator m_end_of_storage;
	};

}
