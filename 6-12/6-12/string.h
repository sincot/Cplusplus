#pragma once

#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

namespace AY
{
	// ȷ�� string �ĵײ�ṹ
	class string
	{
	public:
		// ���������Ĺ��캯��
		/*string();
		string(const char* str);*/

		// c_str ����
		const char* c_str() const;

		// ȫȱʡ�Ĺ��캯��
		string(const char* str = "");
		// ��������
		~string();
		// �������캯��
		string(const string& s);
		// ��ֵ���غ���
		string& operator=(const string& s);
		// swap ����
		void swap(string& s);

		typedef char* iterator;
		// ��ͨ�汾�� begin �� end ����
		iterator begin();
		iterator end();

		// const �汾�� begin �� end ����
		typedef const char* const_iterator;
		const_iterator begin() const;
		const_iterator end() const;


		// size ����
		size_t size() const;
		// operator[ ] ����
		char& operator[] (size_t pos);
		const char& operator[] (size_t pos) const;

		// reserve ����
		void reserve(size_t n = 0);
		// push_back ����
		void push_back(char c);
		// append ����
		string& append(const char* str);

		// operator+= ����
		string& operator+= (const char* str);
		string& operator+= (char c);

		// insert ���� ���� �����ַ� �� �����ַ���
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);

		// erase ����
		string& erase(size_t pos = 0, size_t len = npos);

		// pop_back ����
		void pop_back();

		// find ����
		size_t find(char c, size_t pos = 0);
		size_t find(const char* str, size_t pos = 0);

		// substr ����
		string substr(size_t pos = 0, size_t len = npos) const;

		// һϵ�еıȽϺ���
		bool operator>(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator<(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;

		// clear ����
		void clear();
	public:
		static const size_t npos;

	private:
		char* m_str = nullptr;
		size_t m_capacity = 0;
		size_t m_size = 0;
	};

	// ����������� << ����  
	ostream& operator<< (ostream& os, const string& s);
	istream& operator>> (istream& is, string& s);
	// getline ����
	istream& getline(istream& is, string& s, char delim = '\n');
}