#pragma once

#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

namespace AY
{
	// 确定 string 的底层结构
	class string
	{
	public:
		// 两个基本的构造函数
		/*string();
		string(const char* str);*/

		// c_str 函数
		const char* c_str() const;

		// 全缺省的构造函数
		string(const char* str = "");
		// 析构函数
		~string();
		// 拷贝构造函数
		string(const string& s);
		// 赋值重载函数
		string& operator=(const string& s);
		// swap 函数
		void swap(string& s);

		typedef char* iterator;
		// 普通版本的 begin 和 end 函数
		iterator begin();
		iterator end();

		// const 版本的 begin 和 end 函数
		typedef const char* const_iterator;
		const_iterator begin() const;
		const_iterator end() const;


		// size 函数
		size_t size() const;
		// operator[ ] 函数
		char& operator[] (size_t pos);
		const char& operator[] (size_t pos) const;

		// reserve 函数
		void reserve(size_t n = 0);
		// push_back 函数
		void push_back(char c);
		// append 函数
		string& append(const char* str);

		// operator+= 函数
		string& operator+= (const char* str);
		string& operator+= (char c);

		// insert 函数 —— 插入字符 和 插入字符串
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);

		// erase 函数
		string& erase(size_t pos = 0, size_t len = npos);

		// pop_back 函数
		void pop_back();

		// find 函数
		size_t find(char c, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);

		// substr 函数
		string substr(size_t pos = 0, size_t len = npos) const;

		// 一系列的比较函数
		bool operator>(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator<(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;

		// clear 函数
		void clear();
	public:
		static const size_t npos;

	private:
		char* m_str = nullptr;
		size_t m_capacity = 0;
		size_t m_size = 0;
	};

	// 流插入运算符 << 函数  
	ostream& operator<< (ostream& os, const string& s);
	istream& operator>> (istream& is, string& s);
	// getline 函数
	istream& getline(istream& is, string& s, char delim = '\n');
}