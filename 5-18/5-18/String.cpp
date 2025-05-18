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

	// end 函数
	string::iterator string::end()
	{
		return m_str + m_size;
	}

	// reserve 函数
	void string::reserve(size_t n)
	{
		// 异地扩
		if (n > m_capacity)
		{
			// n + 1 是为 '\0' 开辟的
			char* str = new char[n + 1];
			// 将旧空间的数据拷贝过来
			memcpy(str, m_str, m_size + 1);
			// 释放旧空间
			delete[] m_str;
			// 赋值
			m_str = str;
			m_capacity = n;
		}
	}

	// push_back 函数 —— 尾插
	void string::push_back(char ch)
	{
		// 判断空间是否足够，不够就扩容
		if (m_size == m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}
		m_str[m_size] = ch;
		m_size++;
		m_str[m_size] = '\0';
	}

	// append 函数 —— 相当于追加字符串
	void string::append(const char* str)
	{
		// 先求出要插入的字符串的长度，方便扩容
		size_t len = strlen(str);
		
		// 判断是否要扩容
		if (m_size + len > m_capacity)
		{
			// 2倍扩容是否足够需要判断，不够就需要多少开多少
			size_t newcapacity = 2 * m_capacity > m_size + len 
				                 ? 2 * m_capacity : m_size + len;
			// 开空间
			reserve(newcapacity);
		}

		// 拷贝数据
		memcpy(m_str + m_size, str, len + 1);
		// 字符串的长度增加 len
		m_size += len;
	}

	// operator+= 函数
	string& string::operator+=(char ch)
	{
		// 加等一个字符实际上就是尾插一个字符
		push_back(ch);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		// 加等字符串实际上就是append
		append(str);
		return *this;
	}

	// 流插入函数
	ostream& operator<<(ostream& rout, const string& s)
	{
		// 一个字符一个字符的输出
		for (size_t i = 0; i < s.size(); i++)
		{
			rout << s[i];
		}

		return rout;
	}
}