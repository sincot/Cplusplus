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

	// 打印
	void DatePrint();

	// 获取某月的天数
	int GetMonthDay(int year, int month);

	// 日期 += 天数
	Date& operator+=(int day);

	// 日期 + 天数
	Date operator+(int day) const;

	// 日期 -= 天数
	Date& operator-=(int day);

	// 日期 - 天数
	Date operator-(int day) const;

	// 赋值重载
	Date& operator=(const Date& rdate);

	// 比较运算符重载
	bool operator<(const Date& rdate) const;
	bool operator<=(const Date& rdate) const;
	bool operator>(const Date& rdate) const;
	bool operator>=(const Date& rdate) const;
	bool operator==(const Date& rdate) const;
	bool operator!=(const Date& rdate) const;

	// 前置 ++ —— 本身要改变
	Date& operator++();

	// 后置 ++ —— 本身不需要被改变
	Date operator++(int);

	// 前置 -- —— 本身要改变
	Date& operator--();

	// 后置 -- —— 本身不需要被改变
	Date operator--(int);

	// 日期 - 日期
	int operator-(const Date& rdate);

	// 流插入 << 运算符重载
	friend ostream& operator<<(ostream& rout, const Date& rdate);
	// 流提取 >. 运算符重载
	friend istream& operator>>(istream& rin, Date& rdate);

	// 检查输入的日期的合法性
	bool CheckDate();

private:
	int m_year;
	int m_month;
	int m_day;
};