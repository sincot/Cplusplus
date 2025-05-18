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
		//string();

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

	private:
		char* m_str;        // ָ���ַ��������ָ��
		size_t m_size;      // �ַ����ĳ���
		size_t m_capacity;  // �ַ������������
	};

	// ȫ�ֺ��� ���� ����ͨ�� c_str ��������ȡ���е�˽�б���
	// ������ << ����
	ostream& operator<<(ostream& rout, const string& s);
}