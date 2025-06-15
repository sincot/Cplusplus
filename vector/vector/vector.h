#pragma once

#include <iostream>
#include <assert.h>
#include <string.h>

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
		{}

		// ��������
		~vector()
		{
			if (m_start != nullptr)
			{
				delete[] m_start;
				m_finish = m_end_of_storage = nullptr;
			}
		}

		// reserve ����
		void reserve(size_t n = 0)
		{
			if (n > capacity())
			{
				// ��ǰ�洢 size �����ķ���ֵ
				size_t old_size = size();
				// �����¿ռ�
				T* tmp = new T[n];

				// ����������
				// ��������������Ƿ�Ϊ0
				if (m_start != NULL)
				{
					memcpy(tmp, m_start, sizeof(T) * old_size);
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
			return m_end_of_storage - m_start;
		}

		// push_back ����
		void push_back(const T& x)
		{
			if (m_finish == m_end_of_storage)
			{
				size_t newcapacity = (capacity() == 0 ? 4 : 2 * capacity());
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

		// empty ����
		bool empty() const
		{
			return m_start == m_finish;
		}

		// pop_back ����
		void pop_back()
		{
			assert(!empty());

			--m_finish;
		}

		// insert ����
		iterator insert(iterator pos, const T& val)
		{
			// ���� pos �������ĺϷ���
			assert(pos >= m_start && pos <= m_finish);

			// �ж��Ƿ���Ҫ����
			if (m_finish == m_end_of_storage)
			{
				size_t len = pos - m_start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				// ���� pos ��ָ��
				pos = m_start + len;
			}

			iterator end = m_finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			++m_finish;

			// ָ��������ݵ�λ�õĵ�������������Ҳ���� pos
			return pos;
		}

		// erase ����
		iterator erase(iterator pos)
		{
			// ��� pos �������ĺϷ���
			assert(pos >= m_start && pos <= m_finish);

			// Ų������
			iterator it = pos;
			while (it != m_finish)
			{
				*it = *(it + 1);
				it++;
			}

			// ��Ч���ݸ��� - 1
			--m_finish;

			// ���ر�ɾ�����ݵ��¸����ݵ�λ�õĵ�������������Ҳ���� pos
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
			// n ���� ��Ч���ݸ��� ���� ������
			if (n > size())
			{
				reserve(n);
				while (m_finish != m_start + n)
				{
					*m_finish = val;
					++m_finish;
				}
			}
			// n С�ڵ��� ��Ч���ݸ�����������Ч���ݸ���
			else
			{
				m_finish = m_start + n;
			}
		}

		// swap ����
		void swap(vector& x)
		{
			std::swap(m_start, x.m_start);
			std::swap(m_finish, x.m_finish);
			std::swap(m_end_of_storage, x.m_end_of_storage);
		}

		// �������캯��
		vector(const vector<int>& v)
			: m_start(nullptr)
			, m_finish(nullptr)
			, m_end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		// ֧�ֻ����ų�ʼ������
		vector(initializer_list<T> il)
		{
			reserve(il.size());
			for (auto& e : il)
			{
				push_back(e);
			}
		}

	private:
		iterator m_start = nullptr;
		iterator m_finish = nullptr;
		iterator m_end_of_storage = nullptr;
	};

}

