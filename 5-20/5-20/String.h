#pragma once

#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;

//Ϊ�˱�������е�string����������ͻ������ʹ�������ռ�namespace
namespace AY
{
	//����string�Ľṹ ���� ���������ַ���˳���
	class string
	{
		// ʵ��string�е�һЩ����
	public:
		//���캯��
		string(const char* str = "");
		
		// ��������
		string(const string& s);

		// ��������
		~string();

		// size ����
		size_t size() const;

		// ��ͨ[]����
		char& operator[](size_t i);

		//const[]����
		const char& operator[](size_t i) const;

		//c_str ����
		const char* c_str() const;

		// ������
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin();
		iterator end();

		// reserve ����
		void reserve(size_t n);

		// push_back ����
		void push_back(char ch);

		// append ����
		void append(const char* str);

		// operator += ����
		string& operator+=(char ch);
		string& operator+=(const char* str);

		// insert ���� ���� ����һ���ַ�
		string& insert(size_t pos, char ch);
		// insert ���� ���� ����һ���ַ���
		string& insert(size_t pos, const char* s);

		// erase ���� ���� ɾ������
		string& erase(size_t pos, size_t len = npos);

		// pop_back ���� ���� βɾ
		void pop_back();

		// find ���� ���� �����ַ�
		size_t find(char ch, size_t pos = 0) const;
		// find ���� ���� �����ַ���
		size_t find(const char* s, size_t pos = 0) const;

		// substr ���� ���� ȡ�Ӵ�
		string substr(size_t pos = 0, size_t len = npos) const;

		// ����Ƚ�
		bool operator<(const string& s) const;      // С�� <
		bool operator<=(const string& s) const;     // С�ڵ��� <=
		bool operator>(const string& s) const;      // ���� >
		bool operator>=(const string& s) const;     // ���ڵ��� >=
		bool operator==(const string& s) const;     // ���� ==
		bool operator!=(const string& s) const;     // ������ !=

	private:
		char* m_str;        // ָ���ַ��������ָ��
		size_t m_size;      // �ַ����ĳ���
		size_t m_capacity;  // �ַ������������
		// ����
	public:
		static const size_t npos;
	};

	// ȫ�ֺ��� ���� ����ͨ�� c_str ��������ȡ���е�˽�б���
	// ������ << ����
	ostream& operator<<(ostream& rout, const string& s);
}