#include "string.h"

namespace AY
{
	/*
	// ���������Ĺ��캯��
	string::string()
		: m_str(new char[1]{""})
		, m_capacity(0)
		, m_size(0)
	{}

	string::string(const char* str)
		: m_size(strlen(str))
	{
		m_str = new char[m_size + 1];
		m_capacity = m_size;
		// �� str �е��ַ������� m_str ��
		memcpy(m_str, str, m_size);
	}
	*/

	const char* string::c_str() const
	{
		return m_str;
	}

	// ȫȱʡ�Ĺ��캯��
	string::string(const char* str)
		: m_size(strlen(str))
	{
		m_str = new char[m_size + 1];
		m_capacity = m_size;
		// �� str �е��ַ������� m_str ��
		memcpy(m_str, str, m_size);
	}

	// ��������
	string::~string()
	{
		delete[] m_str;
		m_str = nullptr;
		m_size = m_capacity = 0;
	}

	// size ����
	size_t string::size() const
	{
		return m_size;
	}

	// ���� operator ����
	char& string::operator[] (size_t pos)
	{
		assert(pos < m_size);
		return m_str[pos];
	}

	const char& string::operator[] (size_t pos) const
	{
		assert(pos < m_size);
		return m_str[pos];
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

	// const �汾�� begin ����
	string::const_iterator string::begin() const
	{
		return m_str;
	}

	// const �汾�� end ����
	string::const_iterator string::end() const
	{
		return m_str + m_size;
	}

	// reserve ���� 
	void string::reserve(size_t n)
	{
		// �������
		if (n > m_capacity)
		{
			// �����¿ռ� ���� Ϊ'\0'Ԥ��һ��ռ�
			char* str = new char[n + 1];
			//���������� ���� ��'\0'Ҳ������ȥ
			memcpy(str, m_str, m_size + 1);
			// �ͷžɿռ�
			delete[] m_str;
			// ���±���������
			m_str = str;
			m_capacity = n;
		}
	}

	// push_back ����
	void string::push_back(char c)
	{
		// �ж��Ƿ�Ҫ����
		if (m_size >= m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}

		// ��������
		m_str[m_size++] = c;
		// ���� '\0'
		m_str[m_size] = '\0';
	}

	// append ����
	string& string::append(const char* str)
	{
		// �����Ҫ������ַ����Ĵ�С
		size_t len = strlen(str);
		// �ж��Ƿ�Ҫ����
		if (m_size + len > m_capacity)
		{
			size_t newcapacity = m_size + len > 2 * m_capacity
				? m_size + len : 2 * m_capacity;
			reserve(newcapacity);
		}

		// ׷���ַ��� ���� ���� '\0' 
		memcpy(m_str + m_size, str, len + 1);
		m_size += len;

		return *this;
	}

	// operator+= ����
	string& string::operator+= (const char* str)
	{
		append(str);

		return *this;

	}
	string& string::operator+= (char c)
	{
		push_back(c);

		return *this;
	}

	// ����������� << ���� ���� ����ַ���
	ostream& operator<< (ostream& os, const string& s)
	{
		/*
		// ֱ�ӵ��� c_str ������
		os << s.c_str() << endl;
		*/

		// �������
		for (char e : s)
		{
			os << e;
		}

		return os;
	}

	// insert ���� ���� �����ַ�
	string& string::insert(size_t pos, char c)
	{
		// �ж� pos �ĺϷ���
		assert(pos <= m_size);
		// ����
		if (m_size >= m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}

		// Ų������
		size_t end = m_size + 1;
		while (end > pos)
		{
			m_str[end] = m_str[end - 1];
			--end;
		}
		
		// ��������
		m_str[pos] = c;
		m_size++;

		return *this;
	}

	// insert ���� ���� �����ַ���
	string& string::insert(size_t pos, const char* str)
	{
		// �����Ҫ������ַ����Ĵ�С
		size_t len = strlen(str);
		// �ж��Ƿ�Ҫ����
		if (m_size + len > m_capacity)
		{
			size_t newcapacity = m_size + len > 2 * m_capacity
				? m_size + len : 2 * m_capacity;
			reserve(newcapacity);
		}

		// Ų������
		size_t end = m_size + len;
		while (end > pos + len - 1)
		{
			m_str[end] = m_str[end - len];
			--end;
		}

		// �����ַ��� ���� һ��һ���Ĳ���
		for (size_t i = 0; i < len; i++)
		{
			m_str[pos + i] = str[i];
		}

		m_size += len;
		return *this;
	}

	// erase ����
	string& string::erase(size_t pos, size_t len)
	{
		// ���� len �Ĳ�ͬ�����в�ͬ��ɾ�����
		// len ���� npos ���� ���� pos λ�ÿ�ʼ�� '\0' �������ַ����ĳ���
		if (len >= m_size - pos || len >= npos)
		{
			m_size = pos;
			m_str[m_size] = '\0';
		}
		else
		{
			// Ų������
			for (size_t i = pos; i < pos + len; i++)
			{
				m_str[i] = m_str[i + len];
			}

			m_size -= len;
		}

		return *this;
	}

	// pop_back ����
	void string::pop_back()
	{
		// �ж��ַ������Ƿ��������
		assert(m_size != 0);

		m_size--;
		m_str[m_size] = '\0';
	}
}