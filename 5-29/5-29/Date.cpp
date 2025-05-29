#include "Date.h"

// 函数的声明

// 构造函数
Date::Date(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

// 拷贝构造 —— 已经存在的对象取初始化另一个要实例化的对象
Date::Date(const Date& rdate)
{
	m_year = rdate.m_year;
	m_month = rdate.m_month;
	m_day = rdate.m_day;
	cout << "调用了拷贝构造函数" << endl;
}

// 赋值重载 —— 已经存在的两个对象之间的拷贝
Date& Date::operator=(const Date& rdate)
{
	// 避免自己给自己赋值
	if (this != &rdate)
	{
		m_year = rdate.m_year;
		m_month = rdate.m_month;
		m_day = rdate.m_day;
	}
	cout << "调用了赋值运算符重载函数" << endl;

	return *this;
}

// 获取某月的天数
int Date::GetMonthDay(int year, int month)
{
	// 断言
	assert(month > 0 && month < 13);
	static int arr[13] = { 0, 31, 28, 31, 30, 31, 30,
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

// 日期 += 天数 —— 返回值为 Date 类型
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		// 调用 -= 重载函数
		return *this -= -day;
	}
	m_day += day;
	while (m_day > GetMonthDay(m_year, m_month))
	{
		m_day -= GetMonthDay(m_year, m_month);
		++m_month;
		if (m_month == 13)
		{
			++m_year;
			m_month = 1;
		}
	}

	return *this;
}

// 日期 + 天数 —— 返回值为 Date 类型
Date Date::operator+(int day) const
{
	// 调用该函数的对象没有改变
	Date tmp(*this);
	tmp += day;
	return tmp;
}

// 日期 -= 天数 —— 返回值为 Date 类型
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		// 调用 += 重载函数
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

// 日期 - 天数 —— 返回值为 Date 类型
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

// 前置 ++ 
Date& Date::operator++()
{
	return *this += 1;
}

// 后置 ++
Date Date::operator++(int) const
{
	Date tmp(*this);
	tmp += 1;

	return tmp;
}

// 前置 --
Date& Date::operator--()
{
	return *this -= 1;
}

// 后置 --
Date Date::operator--(int) const
{
	Date tmp(*this);
	tmp -= 1;

	return tmp;
}

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
	else if (m_year == rdate.m_year && m_month == rdate.m_month && m_day < rdate.m_day)
	{
		return true;
	}

	return false;
}

bool Date::operator<=(const Date& rdate) const
{
	return *this < rdate || *this == rdate;
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

// 日期 - 日期
int Date::operator-(const Date& rdate) const
{
	// 让小的日期不断的++，直到等于大的日期
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
		count++;
		++min;
	}

	return flag * count;
}

// 打印函数
void Date::DatePrint()
{
	cout << m_year << "年" << m_month << "月" << m_day << "日" << endl;
}

// 流插入 << 运算符重载
ostream& operator<<(ostream& rout, const Date& rdate)
{
	rout << rdate.m_year << "年" << rdate.m_month
		 << "月" << rdate.m_day << "日" << endl;

	return rout;
}

// 流提取 >> 函数
istream& operator>>(istream& rin, Date& rdate)
{
	cout << "请输入日期： ";
	cin >> rdate.m_year >> rdate.m_month >> rdate.m_day;
	while (1)
	{
		if (rdate.m_year < 0 || (rdate.m_month < 0 || rdate.m_month > 12)
			|| (rdate.m_day < 1 || rdate.m_day > rdate.GetMonthDay(rdate.m_year, rdate.m_month)))
		{
			cout << "输入的日期为非法日期，请重新输入：";
			cin >> rdate.m_year >> rdate.m_month >> rdate.m_day;
		}
		else
		{
			break;
		}
	}

	return rin;
}