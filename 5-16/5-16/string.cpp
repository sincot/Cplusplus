#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace AY
{
	/*
	// 函数的定义
	string::string()
		: m_str(new char[1] {""}) //初始化为空字符串
		, m_size(0)
		, m_capacity(0)
	{}
	*/

	// 全缺省构造函数
	string::string(const char* str)
		:m_size(strlen(str))
	{
		m_capacity = m_size;
		m_str = new char[m_size + 1]; // +1是因为要包含上'\0'
		// 将字符串中的数据拷贝过来
		strcpy(m_str, str);
	}

	// 析构函数
	string::~string()
	{
		// 将动态开辟的内存空间给释放掉
		// 注意new与delete的搭配使用，new使用了[]，delete也要使用[]
		delete[] m_str;
		// 手动置空
		m_str = nullptr;
		// 置为0
		m_size = m_capacity = 0;
	}

	// size 函数
	size_t string::size() const
	{
		return m_size;
	}

	// 普通 [] 函数
	char& string::operator[](size_t i)
	{
		//断言，判断下标 i 是否越界，写为真的条件
		// i 为 size_t 类型，不会小于0
		assert(i < m_size);

		return m_str[i];
	}

	// const [] 函数
	const char& string::operator[](size_t i) const
	{
		assert(i < m_size);

		return m_str[i];
	}

	// c_str 函数
	const char* string::c_str() const
	{
		return m_str;
	}

	// begin 函数
	string::iterator string::begin()
	{
		return m_str;
	}

	string::iterator string::end()
	{
		return m_str + m_size;
	}
}



