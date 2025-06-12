#include "string.h"

namespace AY
{
	// 定义
	const size_t string::npos = -1;
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

	// operator+= 函数 —— += 字符串
	string& string::operator+= (const char* str)
	{
		append(str);

		return *this;
	}

	// operator+= 函数 —— += 字符
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

	// find 函数 —— 查找字符
	size_t string::find(char c, size_t pos)
	{
		// 遍历
		for (size_t i = pos; i < m_size; i++)
		{
			if (m_str[i] == c)
			{
				return i;
			}
		}

		return npos;
	}

	// find 函数 —— 查找字符串
	size_t string::find(const char* str, size_t pos)
	{
		// 借助 strstr 字符串函数
		const char* ptr = strstr(m_str + pos, str);
		// 没找到
		if (ptr == nullptr)
		{
			return npos;
		}
		else
		{
			// 返回下标
			return ptr - m_str;
		}
	}

	// substr 函数
	string string::substr(size_t pos, size_t len) const
	{
		// 调整 len
		if (len >= m_size - pos || len >= npos)
		{
			len = m_size - pos;
		}

		string tmp;
		// 提前开辟好空间
		tmp.reserve(len);

		for (size_t i = 0; i < len; i++)
		{
			// 从 pos 位置开始，直到加了 len 次
			tmp += m_str[pos + i];
		}

		return tmp;
	}

	// 拷贝构造函数
	// 第一种写法：
	/*
	string::string(const string& s)
	{
		// 开辟新空间
		m_str = new char[s.m_capacity + 1];
		// 拷贝旧数据
		memcpy(m_str, s.m_str, s.m_size + 1);
		// 更新变量的数据
		m_size = s.m_size;
		m_capacity = s.m_capacity;
	}
	*/
	// swap 函数
	void string::swap(string& s)
	{
		// 调用 std 中的 swap 函数
		std::swap(m_str, s.m_str);
		std::swap(m_size, s.m_size);
		std::swap(m_capacity, s.m_capacity);
	}

	// 拷贝构造函数
	// 第二种写法：
	string::string(const string& s)
	{
		// 调用构造函数
		string tmp(s.m_str);
		// 调用自己实现的 swap 函数
		// 这里的swap(tmp)实际上是this->swap(tmp)，只是省略不写
		swap(tmp);
	}

	// 赋值重载函数
	// 第一种写法：
	/*
	string& string::operator=(const string& s)
	{
		if (*this != s)
		{
			// 开辟新空间
			char* str = new char[s.m_capacity + 1];
			// 拷贝旧数据
			memcpy(str, s.m_str, s.m_size + 1);
			// 释放旧空间
			delete[] m_str;
			// 更新变量的数据
			m_str = str;
			m_size = s.m_size;
			m_capacity = s.m_capacity;
		}

		return *this;
	}
	*/

	// 赋值重载函数
	// 第二种写法
	string& string::operator=(const string& s)
	{
		if (*this != s)
		{
			// 调用了拷贝构造函数
			string tmp(s);
			// 这里的swap(tmp)实际上是this->swap(tmp)，只是省略不写
			swap(tmp);
		}

		return *this;
	}

	// 一系列的比较函数
	bool string::operator<(const string& s) const
	{
		size_t i1 = 0;
		size_t i2 = 0;

		while (i1 < m_size && i2 < s.m_size)
		{
			if (m_str[i1] < s.m_str[i2])
			{
				return true;
			}
			else if (m_str[i1] > s.m_str[i2])
			{
				return false;
			}
			else
			{
				i1++;
				i2++;
			}
		}

		return i2 != s.m_size;
	}

	bool string::operator<=(const string& s) const
	{
		return (*this < s) || (*this == s);
	}

	bool string::operator>(const string& s) const
	{
		return !((*this < s) || (*this == s));
	}

	bool string::operator>=(const string& s) const
	{
		return !(*this < s);
	}

	bool string::operator==(const string& s) const
	{
		size_t i1 = 0;
		size_t i2 = 0;

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

	bool string::operator!=(const string& s) const
	{
		return !(*this == s);
	}

	// clear 函数
	void string::clear()
	{
		m_size = 0;
		m_str[m_size] = '\0';
	}

	// 流提取运算符 >> 函数
	/*
	istream& operator>> (istream& is, string& s)
	{
		char c;
		is >> c;
		while (c != ' ' || c != '\n')
		{
			s += c;
			is >> c;
		}

		return is;
	}
	*/

	// 改进1
	/*
	istream& operator>> (istream& is, string& s)
	{
		char c = is.get();
		while (c != ' ' || c != '\n')
		{
			s += c;
			c = is.get();
		}

		return is;
	}
	*/

	// 改进2
	/*
	istream& operator>> (istream& is, string& s)
	{
		// 先将s中的原数据清理掉
		s.clear();
		char c = is.get();
		while (c != ' ' || c != '\n')
		{
			s += c;
			c = is.get();
		}

		return is;
	}
	*/

	// 改进3 —— 最终版本
	istream& operator>> (istream& is, string& s)
	{
		// 先将s中的原数据清理掉
		s.clear();

		size_t i = 0;
		char buff[128];

		char c = is.get();
		while (c != ' ' || c != '\n')
		{
			buff[i++] = c;
			// 这里的 i 是下标
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			c = is.get();
		}

		if (i < 127)
		{
			s += buff;
		}

		return is;
	}

	// getline 函数
	istream& getline(istream& is, string& s, char delim)
	{
		s.clear();
		char c = is.get();
		while (c != delim)
		{
			s += c;
			c = is.get();
		}

		return is;
	}
}