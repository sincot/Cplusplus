#pragma once

#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;

//为了避免与库中的string产生命名冲突，可以使用命名空间namespace
namespace AY
{
	//定义string的结构 —— 本质上是字符串顺序表
	class string
	{
		// 实现string中的一些功能
	public:
		//构造函数
		string(const char* str = "");
		//string();

		// 析构函数
		~string();

		// size 函数
		size_t size() const;

		// 普通[]函数
		char& operator[](size_t i);

		//const[]函数
		const char& operator[](size_t i) const;

		//c_str 函数
		const char* c_str() const;

		// 迭代器
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin();
		iterator end();

		// reserve 函数
		void reserve(size_t n);

		// push_back 函数
		void push_back(char ch);

		// append 函数
		void append(const char* str);

		// operator += 函数
		string& operator+=(char ch);
		string& operator+=(const char* str);

	private:
		char* m_str;        // 指向字符串数组的指针
		size_t m_size;      // 字符串的长度
		size_t m_capacity;  // 字符串数组的容量
	};

	// 全局函数 —— 可以通过 c_str 函数来获取类中的私有变量
	// 流插入 << 函数
	ostream& operator<<(ostream& rout, const string& s);
}