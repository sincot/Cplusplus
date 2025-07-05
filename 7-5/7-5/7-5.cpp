#include "string.h"

namespace AY
{
	// ����
	const size_t string::npos = -1;

	// ȫȱʡ�Ĺ��캯��
	string::string(const char* s)
		: m_size(strlen(s))
	{
		m_str = new char[m_size + 1];
		m_capacity = m_size;
		// �ǵ�����ͷ�ļ� <string.h>
		memcpy(m_str, s, strlen(s) + 1);
	}

	// ��������
	string::~string()
	{
		delete[] m_str;
		m_str = nullptr;
		m_size = m_capacity = 0;
	}

	// c_str ����
	const char* string::c_str() const
	{
		return m_str;
	}

	// size ����
	size_t string::size() const
	{
		return m_size;
	}

	// operator[] ���� ���� ��ͨ�汾
	char& string::operator[] (size_t pos)
	{
		// �ǵ�����ͷ�ļ�<assert.h>
		assert(pos < m_size);

		return m_str[pos];
	}

	// operator[] ���� ���� const �汾
	const char& string::operator[] (size_t pos) const
	{
		// �ǵ�����ͷ�ļ�<assert.h>
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

	// reserve ���� ���� ���ݣ��������
	void string::reserve(size_t n)
	{
		// �ж��Ƿ���Ҫ����
		if (n > m_capacity)
		{
			// �����¿ռ� ���� Ϊ'\0'Ԥ��һ��ռ�
			char* str = new char[n + 1];
			// ����������
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
		// �ж��Ƿ���Ҫ����
		if (m_size >= m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}

		// ��������
		m_str[m_size] = c;
		// ��Ч���ݸ��� +1
		m_size++;
		// �ֶ����� '\0'
		m_str[m_size] = '\0';
	}

	// append ����
	string& string::append(const char* s)
	{
		//�������������ַ����ĳ���
		size_t len = strlen(s);

		// �ж��Ƿ���Ҫ����
		if (m_size + len >= m_capacity)
		{
			size_t newcapacity = m_size + len > 2 * m_capacity
				? m_size + len : 2 * m_capacity;
			reserve(newcapacity);
		}

		// �������� ���� +1 ��������'\0'
		memcpy(m_str + m_size, s, len + 1);
		// ��Ч���ݸ��� + len
		m_size += len;

		return *this;
	}

	// operator+= ���� ���� += �ַ�
	string& string::operator+= (char c)
	{
		push_back(c);

		return *this;
	}

	// operator+= ���� ���� += �ַ���
	string& string::operator+= (const char* s)
	{
		append(s);

		return *this;
	}

	// ����������� << ����
	ostream& operator<< (ostream& os, const string& str)
	{
		// �������
		for (size_t i = 0; i < str.size(); i++)
		{
			os << str[i];
		}

		return os;
	}

	// insert ���� ���� �����ַ�
	string& string::insert(size_t pos, char c)
	{
		// �ж� pos λ���Ƿ�Ϸ�
		assert(pos < m_size);
		// �ж��Ƿ���Ҫ����
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
			end--;
		}

		// ��������
		m_str[pos] = c;
		m_size++;

		return *this;
	}

	// insert ���� ���� �����ַ���
	string& string::insert(size_t pos, const char* s)
	{
		// �ж� pos λ���Ƿ�Ϸ�
		assert(pos < m_size);

		//�������������ַ����ĳ���
		size_t len = strlen(s);

		// �ж��Ƿ���Ҫ����
		if (m_size + len >= m_capacity)
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
			end--;
		}

		// ��������
		for (size_t i = 0; i < len; i++)
		{
			m_str[pos + i] = s[i];
		}

		// m_size �Ĵ�С���� len
		m_size += len;

		return *this;
	}

	string& string::erase(size_t pos, size_t len)
	{
		// �ж� pos λ���Ƿ�Ϸ�
		assert(pos < m_size);

		if (len >= m_size - pos || pos >= npos)
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

			// m_size �Ĵ�С - len
			m_size -= len;
			m_str[m_size] = '\0';
		}

		return *this;
	}

	// pop_back ����
	void string::pop_back()
	{
		assert(m_size != 0);

		m_size--;
		m_str[m_size] = '\0';
	}

	// find ���� ���� �����ַ�
	size_t string::find(char c, size_t pos) const
	{
		for (size_t i = pos; i < m_size; i++)
		{
			if (m_str[i] == c)
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
		if (ret != nullptr)
		{
			return ret - m_str;
		}
		else
		{
			return npos;
		}
	}

	// substr ����
	string string::substr(size_t pos, size_t len) const
	{
		// �ж� pos ��λ���Ƿ�Ϸ�
		assert(pos < m_size);

		// ���� len �Ĵ�С
		if (len >= m_size - pos || len >= npos)
		{
			len = m_size - pos;
		}

		// �ȴ���һ�� string �������������
		string tmp;
		// ��ǰԤ���ÿռ�
		tmp.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			tmp += m_str[pos + i];
		}

		return tmp;
	}

	// ���ֱȽϺ���
	bool string::operator< (const string& str)
	{
		size_t i1 = 0;
		size_t i2 = 0;

		// ���������ַ���
		while (i1 < m_size && i2 < str.m_size)
		{
			if (m_str[i1] < str[i2])
			{
				return true;
			}
			else if (m_str[i1] > str[i2])
			{
				return false;
			}
			else
			{
				i1++;
				i2++;
			}
		}

		return i2 < str.m_size;
	}

	bool string::operator== (const string& str)
	{
		size_t i1 = 0;
		size_t i2 = 0;

		// ���������ַ���
		while (i1 < m_size && i2 < str.m_size)
		{
			if (m_str[i1] != str[i2])
			{
				return false;
			}

			i1++;
			i2++;
		}

		return i1 == m_size && i2 == str.m_size;
	}


	bool string::operator<= (const string& str)
	{
		return (*this < str) || (*this == str);
	}

	bool string::operator> (const string& str)
	{
		return !(*this < str || *this == str);
	}

	bool string::operator>= (const string& str)
	{
		return !(*this < str);
	}

	bool string::operator!= (const string& str)
	{
		return !(*this == str);
	}

	// clear ����
	void string::clear()
	{
		m_size = 0;
		m_str[m_size] = '\0';
	}

	// ����ȡ����� >> ����
	istream& operator>> (istream& is, string& str)
	{
		// ��� str �е�����
		str.clear();
		char c;

		size_t i = 0;
		char buff[128] = "";

		// ���������ַ�
		while (is.get(c))
		{
			if (c == ' ' || c == '\n')
			{
				break;
			}

			if (i == 127)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}

			buff[i++] = c;
		}

		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}

		return is;
	}

	// getline ����
	istream& getline(istream& is, string& str, char delim)
	{
		// ��� str �е�����
		str.clear();
		char c;

		size_t i = 0;
		char buff[128] = "";

		// ���������ַ�
		while (is.get(c))
		{
			if (c == delim)
			{
				break;
			}

			if (i == 127)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}

			buff[i++] = c;
		}

		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}

		return is;
	}

	// swap ����
	void string::swap(string& str)
	{
		// ���� std ���е� swap ����
		std::swap(m_str, str.m_str);
		std::swap(m_size, str.m_size);
		std::swap(m_capacity, str.m_capacity);
	}

	// �������캯�� ���� �ڶ���ʵ�ַ���
	string::string(const string& str)
	{
		string tmp(str.m_str);
		swap(tmp);
	}

	// ��ֵ���������
	string& string::operator= (const string& str)
	{
		if (*this != str)
		{
			// �����¿ռ�
			char* tmp = new char[str.m_capacity + 1];
			// ����������
			memcpy(tmp, str.m_str, str.m_size + 1);
			// �ͷžɿռ�
			delete[] m_str;
			// ���±���������
			m_str = tmp;
			m_size = str.m_size;
			m_capacity = str.m_capacity;

			return *this;
		}
	}

	// ��ֵ���غ���
	string& string::operator= (const string& str)
	{
		if (*this != str)
		{
			string tmp(str);
			swap(tmp);
		}

		return *this;
	}
}