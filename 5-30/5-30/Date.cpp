#include "Date.h"

// 构造函数
Date::Date(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

// 拷贝构造
Date::Date(const Date& rdate)
{
	m_year = rdate.m_year;
	m_month = rdate.m_month;
	m_day = rdate.m_day;
}

// 打印
void Date::DatePrint()
{
	cout << m_year << "年" << m_month
		<< "月" << m_day << "日" << endl;
}

// 获取某月的天数
int Date::GetMonthDay(int year, int month)
{
	assert(month > 0 && month < 13);
	int arr[13] = { 0, 31, 28, 31, 30, 31, 30,
					31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return arr[month];
	}
}

// 日期 += 天数
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	m_day += day;
	while (m_day > GetMonthDay(m_year, m_month))
	{
		m_day -= GetMonthDay(m_year, m_month);
		++m_month;
		if (m_month == 13)
		{
			m_month = 1;
			++m_year;
		}
	}

	return *this;
}

// 日期 + 天数
Date Date::operator+(int day) const
{
	Date tmp(*this);
	tmp += day;

	return tmp;
}

// 日期 -= 天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	m_day -= day;
	while (m_day <= 0)
	{
		--m_month;
		if (m_month == 0)
		{
			m_month = 12;
			--m_year;
		}
		m_day += GetMonthDay(m_year, m_month);
	}

	return *this;
}

// 日期 - 天数
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;

	return tmp;
}

// 赋值重载
Date& Date::operator=(const Date& rdate)
{
	if (this != &rdate)
	{
		m_year = rdate.m_year;
		m_month = rdate.m_month;
		m_day = rdate.m_day;
	}

	return *this;
}

// 比较函数
bool Date::operator<(const Date& rdate) const
{
	if (m_year < rdate.m_year)
	{
		return true;
	}
	else if (m_year == rdate.m_year && m_month < rdate.m_month)
	{
		return true;
	}
	else if (m_year == rdate.m_year
		&& m_month == rdate.m_month && m_day < rdate.m_day)
	{
		return true;
	}

	return false;
}

bool Date::operator<=(const Date& rdate) const
{
	return (*this < rdate) || (*this == rdate);
}

bool Date::operator>(const Date& rdate) const
{
	return !(*this <= rdate);
}

bool Date::operator>=(const Date& rdate) const
{
	return !(*this < rdate);
}

bool Date::operator==(const Date& rdate) const
{
	return m_year == rdate.m_year
		&& m_month == rdate.m_month
		&& m_day == rdate.m_day;
}

bool Date::operator!=(const Date& rdate) const
{
	return !(*this == rdate);
}

// 前置 ++ —— 本身要改变
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置 ++ —— 本身不需要被改变
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}

// 前置 -- —— 本身要改变
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// 后置 -- —— 本身不需要被改变
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;

	return tmp;
}

// 日期 - 日期
int Date::operator-(const Date& rdate)
{
	Date max = *this;
	Date min = rdate;
	int flag = 1;
	if (max < min)
	{
		max = rdate;
		min = *this;
		flag = -1;
	}

	int count = 0;
	while (min < max)
	{
		++count;
		++min;
	}

	return count++;
}

ostream& operator<<(ostream& rout, const Date& rdate)
{
	rout << rdate.m_year << "年" << rdate.m_month
		 << "月" << rdate.m_day << "日" << endl;

	return rout;
}

bool Date::CheckDate()
{
	return m_year > 0 && (m_month > 0 && m_month < 13)
		&& (m_day > 0 && m_day <= GetMonthDay(m_year, m_month));
}

// 流提取 >> 运算符重载
istream& operator>>(istream& rin, Date& rdate)
{
	cout << "请输入年月日：> ";
	rin >> rdate.m_year >> rdate.m_month >> rdate.m_day;
	while (1)
	{
		if (rdate.CheckDate())
		{
			break;
		}
		else
		{
			cout << "输入的日期为非法日期，请重新输入：> ";
			rin >> rdate.m_year >> rdate.m_month >> rdate.m_day;
		}
	}

	return rin;
}