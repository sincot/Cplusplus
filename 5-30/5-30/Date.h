#pragma once

#include <iostream>
#include <assert.h>
#include <stdbool.h>

using namespace std;

class Date
{
public:
	// ���캯��
	Date(int year = 1, int month = 1, int day = 1);

	// ��������
	Date(const Date& rdate);

	// ��ӡ
	void DatePrint();

	// ��ȡĳ�µ�����
	int GetMonthDay(int year, int month);

	// ���� += ����
	Date& operator+=(int day);

	// ���� + ����
	Date operator+(int day) const;

	// ���� -= ����
	Date& operator-=(int day);

	// ���� - ����
	Date operator-(int day) const;

	// ��ֵ����
	Date& operator=(const Date& rdate);

	// �Ƚ����������
	bool operator<(const Date& rdate) const;
	bool operator<=(const Date& rdate) const;
	bool operator>(const Date& rdate) const;
	bool operator>=(const Date& rdate) const;
	bool operator==(const Date& rdate) const;
	bool operator!=(const Date& rdate) const;

	// ǰ�� ++ ���� ����Ҫ�ı�
	Date& operator++();

	// ���� ++ ���� ������Ҫ���ı�
	Date operator++(int);

	// ǰ�� -- ���� ����Ҫ�ı�
	Date& operator--();

	// ���� -- ���� ������Ҫ���ı�
	Date operator--(int);

	// ���� - ����
	int operator-(const Date& rdate);

	// ������ << ���������
	friend ostream& operator<<(ostream& rout, const Date& rdate);
	// ����ȡ >. ���������
	friend istream& operator>>(istream& rin, Date& rdate);

	// �����������ڵĺϷ���
	bool CheckDate();

private:
	int m_year;
	int m_month;
	int m_day;
};