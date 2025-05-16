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

	string::iterator string::end()
	{
		return m_str + m_size;
	}
}



