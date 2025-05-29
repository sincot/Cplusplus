#include "Date.h"

// ����������

// ���캯��
Date::Date(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

// �������� ���� �Ѿ����ڵĶ���ȡ��ʼ����һ��Ҫʵ�����Ķ���
Date::Date(const Date& rdate)
{
	m_year = rdate.m_year;
	m_month = rdate.m_month;
	m_day = rdate.m_day;
	cout << "�����˿������캯��" << endl;
}

// ��ֵ���� ���� �Ѿ����ڵ���������֮��Ŀ���
Date& Date::operator=(const Date& rdate)
{
	// �����Լ����Լ���ֵ
	if (this != &rdate)
	{
		m_year = rdate.m_year;
		m_month = rdate.m_month;
		m_day = rdate.m_day;
	}
	cout << "�����˸�ֵ��������غ���" << endl;

	return *this;
}

// ��ȡĳ�µ�����
int Date::GetMonthDay(int year, int month)
{
	// ����
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

// ���� += ���� ���� ����ֵΪ Date ����
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		// ���� -= ���غ���
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

// ���� + ���� ���� ����ֵΪ Date ����
Date Date::operator+(int day) const
{
	// ���øú����Ķ���û�иı�
	Date tmp(*this);
	tmp += day;
	return tmp;
}

// ���� -= ���� ���� ����ֵΪ Date ����
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		// ���� += ���غ���
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

// ���� - ���� ���� ����ֵΪ Date ����
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

// ǰ�� ++ 
Date& Date::operator++()
{
	return *this += 1;
}

// ���� ++
Date Date::operator++(int) const
{
	Date tmp(*this);
	tmp += 1;

	return tmp;
}

// ǰ�� --
Date& Date::operator--()
{
	return *this -= 1;
}

// ���� --
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

// ���� - ����
int Date::operator-(const Date& rdate) const
{
	// ��С�����ڲ��ϵ�++��ֱ�����ڴ������
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

// ��ӡ����
void Date::DatePrint()
{
	cout << m_year << "��" << m_month << "��" << m_day << "��" << endl;
}

// ������ << ���������
ostream& operator<<(ostream& rout, const Date& rdate)
{
	rout << rdate.m_year << "��" << rdate.m_month
		 << "��" << rdate.m_day << "��" << endl;

	return rout;
}

// ����ȡ >> ����
istream& operator>>(istream& rin, Date& rdate)
{
	cout << "���������ڣ� ";
	cin >> rdate.m_year >> rdate.m_month >> rdate.m_day;
	while (1)
	{
		if (rdate.m_year < 0 || (rdate.m_month < 0 || rdate.m_month > 12)
			|| (rdate.m_day < 1 || rdate.m_day > rdate.GetMonthDay(rdate.m_year, rdate.m_month)))
		{
			cout << "���������Ϊ�Ƿ����ڣ����������룺";
			cin >> rdate.m_year >> rdate.m_month >> rdate.m_day;
		}
		else
		{
			break;
		}
	}

	return rin;
}