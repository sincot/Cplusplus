#pragma once
#include <iostream>
#include <assert.h>
#include <stdbool.h>

using namespace std;

class Date
{
public:
	// 构造函数
	Date(int year = 1, int month = 1, int day = 1);

	// 拷贝构造
	Date(const Date& rdate);

	// 赋值重载
	Date& operator=(const Date& rdate);

	//  获取月的天数
	int GetMonthDay(int year, int month);
	
	// 日期 += 天数 —— 返回值为 Date 类型
	Date& operator+=(int day);

	// 日期 + 天数 —— 返回值为 Date 类型
	Date operator+(int day) const;

	// 日期 -= 天数 —— 返回值为 Date 类型
	Date& operator-=(int day);

	// 日期 - 天数 —— 返回值为 Date 类型
	Date operator-(int day) const;

	// 前置++ 运算符重载函数
	Date& operator++();
	// 后置++ 运算符重载函数
	Date operator++(int) const;

	// 前置-- 运算符重载函数
	Date& operator--();
	// 后置-- 运算符重载函数
	Date operator--(int) const;

	// 比较运算操作符的重载
	bool operator<(const Date& rdate) const;
	bool operator<=(const Date& rdate) const;
	bool operator>(const Date& rdate) const;
	bool operator>=(const Date& rdate) const;
	bool operator==(const Date& rdate) const;
	bool operator!=(const Date& rdate) const;

	// 日期 - 日期
	int operator-(const Date& rdate) const;

	// 打印函数
	void DatePrint();

	// 友元函数
	friend ostream& operator<<(ostream& rout, const Date& rdate);
	friend istream& operator>>(istream& rin, Date& rdate);

private:
	// 成员变量
	int m_year;
	int m_month;
	int m_day;
};