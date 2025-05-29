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

	// ��ֵ����
	Date& operator=(const Date& rdate);

	//  ��ȡ�µ�����
	int GetMonthDay(int year, int month);
	
	// ���� += ���� ���� ����ֵΪ Date ����
	Date& operator+=(int day);

	// ���� + ���� ���� ����ֵΪ Date ����
	Date operator+(int day) const;

	// ���� -= ���� ���� ����ֵΪ Date ����
	Date& operator-=(int day);

	// ���� - ���� ���� ����ֵΪ Date ����
	Date operator-(int day) const;

	// ǰ��++ ��������غ���
	Date& operator++();
	// ����++ ��������غ���
	Date operator++(int) const;

	// ǰ��-- ��������غ���
	Date& operator--();
	// ����-- ��������غ���
	Date operator--(int) const;

	// �Ƚ����������������
	bool operator<(const Date& rdate) const;
	bool operator<=(const Date& rdate) const;
	bool operator>(const Date& rdate) const;
	bool operator>=(const Date& rdate) const;
	bool operator==(const Date& rdate) const;
	bool operator!=(const Date& rdate) const;

	// ���� - ����
	int operator-(const Date& rdate) const;

	// ��ӡ����
	void DatePrint();

	// ��Ԫ����
	friend ostream& operator<<(ostream& rout, const Date& rdate);
	friend istream& operator>>(istream& rin, Date& rdate);

private:
	// ��Ա����
	int m_year;
	int m_month;
	int m_day;
};