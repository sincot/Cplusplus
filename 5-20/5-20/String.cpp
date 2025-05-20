#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace AY
{
    const size_t string::npos = -1;
	
	// ȫȱʡ���캯��
	string::string(const char* str)
		:m_size(strlen(str))
	{
		m_capacity = m_size;
		m_str = new char[m_size + 1]; // +1����ΪҪ������'\0'
		// ���ַ����е����ݿ�������
		strcpy(m_str, str);
	}

	// ��������
	string::string(const string& s)
	{
		// ���ٺ��ַ��� s һ������ڴ�ռ�
		m_str = new char[s.m_capacity + 1];
		// ���ַ��� s �е����ݶ������� m_str ��
		memcpy(m_str, s.m_str, s.size() + 1);
		m_size = s.m_size;
		m_capacity = s.m_capacity;
	}

	// ��������
	string::~string()
	{
		// ����̬���ٵ��ڴ�ռ���ͷŵ�
		// ע��new��delete�Ĵ���ʹ�ã�newʹ����[]��deleteҲҪʹ��[]
		delete[] m_str;
		// �ֶ��ÿ�
		m_str = nullptr;
		// ��Ϊ0
		m_size = m_capacity = 0;
	}

	// size ����
	size_t string::size() const
	{
		return m_size;
	}

	// ��ͨ [] ����
	char& string::operator[](size_t i)
	{
		//���ԣ��ж��±� i �Ƿ�Խ�磬дΪ�������
		// i Ϊ size_t ���ͣ�����С��0
		assert(i < m_size);

		return m_str[i];
	}

	// const [] ����
	const char& string::operator[](size_t i) const
	{
		assert(i < m_size);

		return m_str[i];
	}

	// c_str ����
	const char* string::c_str() const
	{
		return m_str;
	}

	// begin ����
	string::iterator string::begin()
	{
		return m_str;
	}

	// end ����
	string::iterator string::end()
	{
		return m_str + m_size;
	}

	// reserve ����
	void string::reserve(size_t n)
	{
		// �����
		if (n > m_capacity)
		{
			// n + 1 ��Ϊ '\0' ���ٵ�
			char* str = new char[n + 1];
			// ���ɿռ�����ݿ�������
			memcpy(str, m_str, m_size + 1);
			// �ͷžɿռ�
			delete[] m_str;
			// ��ֵ
			m_str = str;
			m_capacity = n;
		}
	}

	// push_back ���� ���� β��
	void string::push_back(char ch)
	{
		// �жϿռ��Ƿ��㹻������������
		if (m_size == m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}
		m_str[m_size] = ch;
		m_size++;
		m_str[m_size] = '\0';
	}

	// append ���� ���� �൱��׷���ַ���
	void string::append(const char* str)
	{
		// �����Ҫ������ַ����ĳ��ȣ���������
		size_t len = strlen(str);

		// �ж��Ƿ�Ҫ����
		if (m_size + len > m_capacity)
		{
			// 2�������Ƿ��㹻��Ҫ�жϣ���������Ҫ���ٿ�����
			size_t newcapacity = 2 * m_capacity > m_size + len
				? 2 * m_capacity : m_size + len;
			// ���ռ�
			reserve(newcapacity);
		}

		// ��������
		memcpy(m_str + m_size, str, len + 1);
		// �ַ����ĳ������� len
		m_size += len;
	}

	// operator+= ����
	string& string::operator+=(char ch)
	{
		// �ӵ�һ���ַ�ʵ���Ͼ���β��һ���ַ�
		push_back(ch);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		// �ӵ��ַ���ʵ���Ͼ���append
		append(str);
		return *this;
	}

	// �����뺯��
	ostream& operator<<(ostream& rout, const string& s)
	{
		// һ���ַ�һ���ַ������
		for (size_t i = 0; i < s.size(); i++)
		{
			rout << s[i];
		}

		return rout;
	}

	// insert ���� ���� ����һ���ַ�
	string& string::insert(size_t pos, char ch)
	{
		// ��� pos �Ƿ�Ϊ��Чλ�� ���� �Ƿ���ڵ�ǰ�ַ����ĳ���
		assert(pos <= m_size);

		// �ж��Ƿ�Ҫ����
		if (m_size == m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}

		// �ƶ�����
		size_t end = m_size + 1;
		while (end > pos)
		{
			m_str[end] = m_str[end - 1];
			end--;
		}

		m_str[pos] = ch;
		m_size++;

		return *this;
	}

	// insert ���� ���� ����һ���ַ���
	string& string::insert(size_t pos, const char* s)
	{
		size_t len = strlen(s);
		// �ж��Ƿ�Ҫ����
		if (m_size + len > m_capacity)
		{
			// 2�������Ƿ��㹻��Ҫ�жϣ���������Ҫ���ٿ�����
			size_t newcapacity = 2 * m_capacity > m_size + len
				? 2 * m_capacity : m_size + len;
			reserve(newcapacity);
		}

		// �ƶ�����
		size_t end = m_size + len;
		while (end > pos + len - 1)
		{
			m_str[end] = m_str[end - len];
			end--;
		}

		for (size_t i = 0; i < len; i++)
		{
			m_str[pos + i] = s[i];
		}

		m_size += len;

		return *this;
	}

	// erase ����
	string& string::erase(size_t pos, size_t len)
	{
		// ��� pos �Ƿ�Ϊ��Чλ�� ���� �Ƿ���ڵ�ǰ�ַ����ĳ���
		assert(pos <= m_size);

		// Ҫɾ�������� len������posλ�ú�ʣ�������
		if (len == npos || len >= m_size - pos)
		{
			m_size = pos;
			m_str[m_size] = '\0';
		}
		// Ҫɾ�������� len��С��posλ�ú�ʣ�������
		else
		{
			size_t end = pos + len;
			memmove(m_str + pos, m_str + end, m_size + 1 - end);
			m_size -= len;
		}

		return *this;
	}

	// pop_back ����
	void string::pop_back()
	{
		// ����ַ����Ƿ�Ϊ���ַ�������Ϊ���ַ����ͱ�ɾ��
		assert(m_size > 0);
		m_size--;
		m_str[m_size] = '\0';
	}

	// find ���� ���� �����ַ�
	size_t string::find(char ch, size_t pos) const
	{
		for (size_t i = pos; i < m_size; i++)
		{
			if (m_str[i] == ch)
			{
				return i;
			}
		}

		return npos;
	}

	// find ���� ���� �����ַ���
	size_t string::find(const char* s, size_t pos) const
	{
		char* ret = strstr(m_str + pos, s);
		if (ret == nullptr)
		{
			return npos;
		}
		else
		{
			return ret - m_str;
		}
	}
	
	// substr ���� ���� ȡ�Ӵ�
	string string::substr(size_t pos, size_t len) const
	{
		// ��� pos �Ƿ�Ϊ��Чλ�� ���� �Ƿ���ڵ�ǰ�ַ����ĳ���
		assert(pos <= m_size);

		// Ҫɾ�������� len������posλ�ú�ʣ�������
		if (len == npos || len >= m_size - pos)
		{
			len = m_size - pos;
		}

		// ���ҵ����ִ��������´���
		string ret;
		// �ȿ��ٺ� len ���ȴ�С�Ŀռ�
		ret.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			ret += m_str[pos + i];
		}

		return ret;
	}

	// С�� <
	bool string::operator<(const string& s) const
	{
		size_t i1 = 0; // ���� this ָ��
		size_t i2 = 0; // ���� s 

		while (i1 < m_size && i2 < s.m_size)
		{
			if (m_str[i1] < s[i2])
			{
				return true;
			}
			else if (m_str[i1] > s[i2])
			{
				return false;
			}
			else
			{
				i1++;
				i2++;
			}
		}

		return i2 < s.m_size;
	}
	
	// С�ڵ��� <=
	bool string::operator<=(const string& s) const
	{
		return (*this < s || *this == s);
	}

	// ���� >
	bool string::operator>(const string& s) const
	{
		return !(*this < s);
	}

	// ���ڵ��� >=
	bool string::operator>=(const string& s) const
	{
		return !(*this < s);
	}

	// ���� ==
	bool string::operator==(const string& s) const
	{
		size_t i1 = 0; // ���� this ָ��
		size_t i2 = 0; // ���� s 

		while (i1 < m_size && i2 < s.m_size)
		{
			if (m_str[i1] != s[i2])
			{
				return false;
			}

			i1++;
			i2++;
		}

		return i1 == m_size && i2 == s.m_size;
	}

	// ������ !=
	bool string::operator!=(const string& s) const
	{
		return !(*this == s);
	}
}
