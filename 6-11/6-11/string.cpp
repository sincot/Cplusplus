#include "string.h"

namespace AY
{
	/*
	// 两个基本的构造函数
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
		// 将 str 中的字符拷贝到 m_str 中
		memcpy(m_str, str, m_size);
	}
	*/

	const char* string::c_str() const
	{
		return m_str;
	}

	// 全缺省的构造函数
	string::string(const char* str)
		: m_size(strlen(str))
	{
		m_str = new char[m_size + 1];
		m_capacity = m_size;
		// 将 str 中的字符拷贝到 m_str 中
		memcpy(m_str, str, m_size);
	}

	// 析构函数
	string::~string()
	{
		delete[] m_str;
		m_str = nullptr;
		m_size = m_capacity = 0;
	}

	// size 函数
	size_t string::size() const
	{
		return m_size;
	}

	// 两个 operator 函数
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

	// const 版本的 begin 函数
	string::const_iterator string::begin() const
	{
		return m_str;
	}

	// const 版本的 end 函数
	string::const_iterator string::end() const
	{
		return m_str + m_size;
	}

	// reserve 函数 
	void string::reserve(size_t n)
	{
		// 异地扩容
		if (n > m_capacity)
		{
			// 开辟新空间 —— 为'\0'预留一块空间
			char* str = new char[n + 1];
			//拷贝旧数据 —— 将'\0'也拷贝进去
			memcpy(str, m_str, m_size + 1);
			// 释放旧空间
			delete[] m_str;
			// 更新变量的数据
			m_str = str;
			m_capacity = n;
		}
	}

	// push_back 函数
	void string::push_back(char c)
	{
		// 判断是否要扩容
		if (m_size >= m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}

		// 插入数据
		m_str[m_size++] = c;
		// 加上 '\0'
		m_str[m_size] = '\0';
	}

	// append 函数
	string& string::append(const char* str)
	{
		// 先求出要插入的字符串的大小
		size_t len = strlen(str);
		// 判断是否要扩容
		if (m_size + len > m_capacity)
		{
			size_t newcapacity = m_size + len > 2 * m_capacity
				? m_size + len : 2 * m_capacity;
			reserve(newcapacity);
		}

		// 追加字符串 —— 包含 '\0' 
		memcpy(m_str + m_size, str, len + 1);
		m_size += len;

		return *this;
	}

	// operator+= 函数
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

	// 流插入运算符 << 函数 —— 输出字符串
	ostream& operator<< (ostream& os, const string& s)
	{
		/*
		// 直接调用 c_str 函数？
		os << s.c_str() << endl;
		*/

		// 依次输出
		for (char e : s)
		{
			os << e;
		}

		return os;
	}

	// insert 函数 —— 插入字符
	string& string::insert(size_t pos, char c)
	{
		// 判断 pos 的合法性
		assert(pos <= m_size);
		// 扩容
		if (m_size >= m_capacity)
		{
			size_t newcapacity = m_capacity == 0 ? 4 : 2 * m_capacity;
			reserve(newcapacity);
		}

		// 挪动数据
		size_t end = m_size + 1;
		while (end > pos)
		{
			m_str[end] = m_str[end - 1];
			--end;
		}
		
		// 插入数据
		m_str[pos] = c;
		m_size++;

		return *this;
	}

	// insert 函数 —— 插入字符串
	string& string::insert(size_t pos, const char* str)
	{
		// 先求出要插入的字符串的大小
		size_t len = strlen(str);
		// 判断是否要扩容
		if (m_size + len > m_capacity)
		{
			size_t newcapacity = m_size + len > 2 * m_capacity
				? m_size + len : 2 * m_capacity;
			reserve(newcapacity);
		}

		// 挪动数据
		size_t end = m_size + len;
		while (end > pos + len - 1)
		{
			m_str[end] = m_str[end - len];
			--end;
		}

		// 插入字符串 —— 一个一个的插入
		for (size_t i = 0; i < len; i++)
		{
			m_str[pos + i] = str[i];
		}

		m_size += len;
		return *this;
	}

	// erase 函数
	string& string::erase(size_t pos, size_t len)
	{
		// 根据 len 的不同，会有不同的删除结果
		// len 大于 npos 或者 大于 pos 位置开始到 '\0' 结束的字符串的长度
		if (len >= m_size - pos || len >= npos)
		{
			m_size = pos;
			m_str[m_size] = '\0';
		}
		else
		{
			// 挪动数据
			for (size_t i = pos; i < pos + len; i++)
			{
				m_str[i] = m_str[i + len];
			}

			m_size -= len;
		}

		return *this;
	}

	// pop_back 函数
	void string::pop_back()
	{
		// 判断字符串中是否存在数据
		assert(m_size != 0);

		m_size--;
		m_str[m_size] = '\0';
	}
}