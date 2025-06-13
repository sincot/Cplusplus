#pragma once

#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

using namespace std;

namespace AY
{
	class string
	{
	public:
		//// �������캯��
		//string();
		//string(const char* s);

		// ȫȱʡ���캯��
		string(const char* s = "");

		// ��������
		~string();

		// �������캯��
		string(const string& str);

		// ��ֵ���������
		string& operator= (const string& str);

		// c_str ����
		const char* c_str() const;

		// size ����
		size_t size() const;

		// operator[] ���� ���� ��ͨ�汾
		char& operator[] (size_t pos);
		// operator[] ���� ���� const �汾
		const char& operator[] (size_t pos) const;

		typedef char* iterator;
		// begin ����
		iterator begin();
		// end ����
		iterator end();

		typedef const char* const_iterator;
		// const �汾�� begin ����
		const_iterator begin() const;
		// const �汾�� end ����
		const_iterator end() const;

		// reserve ����
		void reserve(size_t n = 0);
		
		// push_back ����
		void push_back(char c);

		// append ����
		string& append(const char* s);

		// operator+= ���� ���� += �ַ�
		string& operator+= (char c);
		// operator+= ���� ���� += �ַ���
		string& operator+= (const char* s);
		
		// insert ���� ���� �����ַ�
		string& insert(size_t pos, char c);
		// insert ���� ���� �����ַ���
		string& insert(size_t pos, const char* s);

		// erase ����
		string& erase(size_t pos = 0, size_t len = npos);

		// pop_back ����
		void pop_back();

		// find ���� ���� �����ַ�
		size_t find(char c, size_t pos = 0) const;
		// find ���� ���� �����ַ���
		size_t find(const char* s, size_t pos = 0) const;

		// substr ����
		string substr(size_t pos = 0, size_t len = npos) const;

		// ���ֱȽϺ���
		bool operator< (const string& str);
		bool operator<= (const string& str);
		bool operator> (const string& str);
		bool operator>= (const string& str);
		bool operator== (const string& str);
		bool operator!= (const string& str);

		// clear ����
		void clear();

		// swap ����
		void swap(string& str);

	private:
		char* m_str;
		size_t m_size;
		size_t m_capacity;
	public:
		// ����
		static const size_t npos;
	};

	// ����������� << ����
	ostream& operator<< (ostream& os, const string& str);
	// ����ȡ����� >> ����
	istream& operator>> (istream& is, string& str);
	// getline ����
	istream& getline(istream& is, string& str, char delim = '\n');
}