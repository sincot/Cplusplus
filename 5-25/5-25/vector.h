#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

namespace AY
{
	// vector �ĵײ㹹��
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		// ���캯��
		vector()
			: m_start(nullptr)
			, m_finish(nullptr)
			, m_end_of_storage(nullptr)
		{
		}

		// reserve ����
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				// ���Ϳռ��е����ݿ������¿ռ���
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

		// operator[ ] ����
		void operator[](size_t i)
		{
			assert(i < size());
			return m_start[i];
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

		// push_back ����
		void push_back(const T& x)
		{
			if (m_finish == m_end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*m_finish = x;
			++m_finish;
		}

		// ʵ�ֵ�����
		iterator begin()
		{
			return m_start;
		}

		iterator end()
		{
			return m_finish;
		}

	private:
		iterator m_start;           // �൱�� m_a
		iterator m_finish;          // �൱�� m_a + m_size
		iterator m_end_of_storage;  // �൱�� m_a + capacity
	};
}
