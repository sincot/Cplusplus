#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace AY
{
    const size_t string::npos = -1;
	
	// 全缺省构造函数
	string::string(const char* str)
		:m_size(strlen(str))
	{
		m_capacity = m_size;
		m_str = new char[m_size + 1]; // +1是因为要包含上'\0'
		// 将字符串中的数据拷贝过来
		strcpy(m_str, str);
	}

	// 拷贝构造
	string::string(const string& s)
	{
		// 开辟和字符串 s 一样大的内存空间
		m_str = new char[s.m_capacity + 1];
		// 将字符串 s 中的数据都拷贝到 m_str 中
		memcpy(m_str, s.m_str, s.size() + 1);
		m_size = s.m_size;
		m_capacity = s.m_capacity;
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

	// insert 函数 —— 插入一个字符
	string& string::insert(size_t pos, char ch)
	{
		// 检查 pos 是否为有效位置 —— 是否大于当前字符串的长度
		assert(pos <= m_size);

		// 判断是否要扩容
		if (m_size == m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}

		// 移动数据
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

	// insert 函数 —— 插入一个字符串
	string& string::insert(size_t pos, const char* s)
	{
		size_t len = strlen(s);
		// 判断是否要扩容
		if (m_size + len > m_capacity)
		{
			// 2倍扩容是否足够需要判断，不够就需要多少开多少
			size_t newcapacity = 2 * m_capacity > m_size + len
				? 2 * m_capacity : m_size + len;
			reserve(newcapacity);
		}

		// 移动数据
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

	// erase 函数
	string& string::erase(size_t pos, size_t len)
	{
		// 检查 pos 是否为有效位置 —— 是否大于当前字符串的长度
		assert(pos <= m_size);

		// 要删除的数据 len，大于pos位置后剩余的数据
		if (len == npos || len >= m_size - pos)
		{
			m_size = pos;
			m_str[m_size] = '\0';
		}
		// 要删除的数据 len，小于pos位置后剩余的数据
		else
		{
			size_t end = pos + len;
			memmove(m_str + pos, m_str + end, m_size + 1 - end);
			m_size -= len;
		}

		return *this;
	}

	// pop_back 函数
	void string::pop_back()
	{
		// 检查字符串是否为空字符串，若为空字符串就别删了
		assert(m_size > 0);
		m_size--;
		m_str[m_size] = '\0';
	}

	// find 函数 —— 查找字符
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

	// find 函数 —— 查找字符串
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
	
	// substr 函数 —— 取子串
	string string::substr(size_t pos, size_t len) const
	{
		// 检查 pos 是否为有效位置 —— 是否大于当前字符串的长度
		assert(pos <= m_size);

		// 要删除的数据 len，大于pos位置后剩余的数据
		if (len == npos || len >= m_size - pos)
		{
			len = m_size - pos;
		}

		// 将找到的字串拷贝到新串中
		string ret;
		// 先开辟好 len 长度大小的空间
		ret.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			ret += m_str[pos + i];
		}

		return ret;
	}

	// 小于 <
	bool string::operator<(const string& s) const
	{
		size_t i1 = 0; // 传给 this 指针
		size_t i2 = 0; // 传给 s 

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
	
	// 小于等于 <=
	bool string::operator<=(const string& s) const
	{
		return (*this < s || *this == s);
	}

	// 大于 >
	bool string::operator>(const string& s) const
	{
		return !(*this < s);
	}

	// 大于等于 >=
	bool string::operator>=(const string& s) const
	{
		return !(*this < s);
	}

	// 等于 ==
	bool string::operator==(const string& s) const
	{
		size_t i1 = 0; // 传给 this 指针
		size_t i2 = 0; // 传给 s 

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

	// 不等于 !=
	bool string::operator!=(const string& s) const
	{
		return !(*this == s);
	}
}
