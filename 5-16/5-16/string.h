#pragma once
#include <string.h>
#include <assert.h>
#include <iostream>

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

		typedef char* iterator;
		iterator begin();
		iterator end();


	private:
		char* m_str;        // ָ���ַ��������ָ��
		size_t m_size;      // �ַ����ĳ���
		size_t m_capacity;  // �ַ������������
	};
}




