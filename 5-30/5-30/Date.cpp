#include "Date.h"

// ���캯��
Date::Date(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

// ��������
Date::Date(const Date& rdate)
{
	m_year = rdate.m_year;
	m_month = rdate.m_month;
	m_day = rdate.m_day;
}

// ��ӡ
void Date::DatePrint()
{
	cout << m_year << "��" << m_month
		<< "��" << m_day << "��" << endl;
}

// ��ȡĳ�µ�����
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

// ���� += ����
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

// ���� + ����
Date Date::operator+(int day) const
{
	Date tmp(*this);
	tmp += day;

	return tmp;
}

// ���� -= ����
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

// ���� - ����
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;

	return tmp;
}

// ��ֵ����
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

// �ȽϺ���
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

// ǰ�� ++ ���� ����Ҫ�ı�
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// ���� ++ ���� ������Ҫ���ı�
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}

// ǰ�� -- ���� ����Ҫ�ı�
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// ���� -- ���� ������Ҫ���ı�
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;

	return tmp;
}

// ���� - ����
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
	rout << rdate.m_year << "��" << rdate.m_month
		 << "��" << rdate.m_day << "��" << endl;

	return rout;
}

bool Date::CheckDate()
{
	return m_year > 0 && (m_month > 0 && m_month < 13)
		&& (m_day > 0 && m_day <= GetMonthDay(m_year, m_month));
}

// ����ȡ >> ���������
istream& operator>>(istream& rin, Date& rdate)
{
	cout << "�����������գ�> ";
	rin >> rdate.m_year >> rdate.m_month >> rdate.m_day;
	while (1)
	{
		if (rdate.CheckDate())
		{
			break;
		}
		else
		{
			cout << "���������Ϊ�Ƿ����ڣ����������룺> ";
			rin >> rdate.m_year >> rdate.m_month >> rdate.m_day;
		}
	}

	return rin;
}