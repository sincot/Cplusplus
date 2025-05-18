#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace AY
{
	/*
	// �����Ķ���
	string::string()
		: m_str(new char[1] {""}) //��ʼ��Ϊ���ַ���
		, m_size(0)
		, m_capacity(0)
	{}
	*/

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
}