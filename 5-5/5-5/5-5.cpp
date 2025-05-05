#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
public:
	//���캯��
	Date(int year = 1, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	//�������캯��
	// date2(date1) --- rdate��date1�ı���
	Date(const Date& rdate)
	{
		m_year = rdate.m_year;
		m_month = rdate.m_month;
		m_day = rdate.m_day;
	}

	void DatePrint()
	{
		cout << m_year << "/" << m_month << "/" << m_day << endl;
	}

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);

		int arr[13] = { -1, 31, 28, 31, 30, 31, 30,
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

	/*
	//���� == ����
	bool operator==(const Date& rdatef, const Date& rdateb)
	{
		return rdatef.m_year == rdateb.m_year
			&& rdatef.m_month == rdateb.m_month
			&& rdatef.m_day == rdateb.m_day;
	}
	*/

	// ���� == ����
	bool operator==(const Date& rdate)
	{
		return m_year == rdate.m_year
			&& m_month == rdate.m_month
			&& m_day == rdate.m_day;
	}

	//���� < �����
	bool operator<(const Date& rdate)
	{
		// �Ȱ�С��������ҳ���������true
		// ��ôʣ�µľ��Ǵ�������ֱ�ӷ���false

		// ��С��С
		if (m_year < rdate.m_year)
		{
			return true;
		}
        //����ȣ���С��С
		else if (m_year == rdate.m_year && m_month < rdate.m_month)
		{
			return true;
		}
		//����ȣ�����ȣ���С��С
		else if (m_year == rdate.m_year && m_month == rdate.m_month && m_day < rdate.m_day)
		{
			return true;
		}
		
		return false;
	}

	//���� != �����
	bool operator!=(const Date& rdate)
	{
		//�Ե���ȡ�������ǲ�����
		return !(*this == rdate);
	}

	//���� <= �����
	bool operator<=(const Date & rdate)
	{
		//<= ���� < ���� == 
		return (*this < rdate) || (*this == rdate);
	}

	//���� > �����
	bool operator>(const Date& rdate)
	{
		//�� <= ȡ�������Ǵ���
		return !(*this <= rdate);
	}

	//���� >= �����
	bool operator>=(const Date& rdate)
	{
		//�� < ȡ�������Ǵ��ڵ���
		return !(*this < rdate);
	}

	
	// ���� += ���� ���� date + day(100)
	// +=����֮��ԭ�����ı�
	Date& operator+=(int day)
	{
		//�������dayΪ��ֵ�����
		if (day < 0)
		{
			//���� -= ���غ���
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

		//thisָ��ָ��ľ��ǵ��øú����Ķ���
		return *this;
	}

	//���� + ���� ���� date + day(100)
	// + ����֮��ԭ���󲻻�ı䣬���Ҫ���Ƚ�ԭ���󿽱�һ��
	Date operator+(int day)
	{
		//thisָ��ָ��ľ��ǵ��øú����Ķ���
		Date tmp(*this); // �����˿������캯��
        
		tmp.m_day += day;
		while (tmp.m_day > GetMonthDay(tmp.m_year, tmp.m_month))
		{
			tmp.m_day -= GetMonthDay(tmp.m_year, tmp.m_month);
			++tmp.m_month;

			if (tmp.m_month == 13)
			{
				tmp.m_month = 1;
				++tmp.m_year;
			}
		}

		return tmp;
	}

	
	//���� -= ����
	// -= ����֮�󣬵��øú����Ķ����ı�
	Date& operator-=(int day)
	{
		//�������dayΪ��ֵ�����
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

			//ȡ��һ���·ݵ�����
			m_day += GetMonthDay(m_year, m_month);
		}

		return *this;
	}
	
	//�������� -= �����ĺ�����ʵ������ - ����
	Date operator-(int day)
	{
		Date tmp(*this);
		tmp -= day; //���������� -= �����ĺ���

		return tmp;
	}

	//ǰ��++
	Date& operator++()
	{
		*this += 1;

		return *this;
	}

	//����++
	Date operator++(int)
	{
		Date tmp(*this);
		tmp += 1;

		return tmp;
	}

	//ǰ��--
	Date& operator--()
	{
		*this -= 1;

		return *this;
	}

	//����--
	Date operator--(int)
	{
		Date tmp(*this);
	    tmp -= 1;

		return tmp;
	}

	/*
	//���� - ����
	// - ����֮�󣬵��øú����Ķ��󲻻�ı�
	Date operator-(int day)
	{
		Date tmp(*this);

		tmp.m_day -= day;

		while (tmp.m_day < 0)
		{
			--tmp.m_month;

			if (tmp.m_month == 0)
			{
				tmp.m_month = 12;
				--tmp.m_year;
			}

			//ȡ��һ���·ݵ�����
			tmp.m_day += GetMonthDay(tmp.m_year, tmp.m_month);
		}

		return tmp;
	}
	
	//�������� - �����ĺ�����ʵ������ -= ����
	Date& operator-=(int day)
	{
		*this = *this - day;

		return *this;
	}
	*/

	/*
	//��ֵ���������
	void operator=(Date& rdate)
	{
		m_year = rdate.m_year;
		m_month = rdate.m_month;
		m_day = rdate.m_day;
	}
	*/

	Date& operator=(const Date& rdate)
	{
		if (this != &rdate)
		{
			m_year = rdate.m_year;
			m_month = rdate.m_month;
			m_day = rdate.m_day;
		}

		return *this;
	}

	//���� - ���� ���� datefront - datebefore
	int operator-(const Date& rdate)
	{
		//�ȼ��� this ָ��ָ������ڶ���Ϊ�������
		//rdate���ڶ���ΪС������
		Date max = *this;
		Date min = rdate;

		//�����費��ȷ�����е���
		if (max < min) // ������ < ���غ���
		{
			max = rdate;
			min = *this;
		}

		//����һ������������
		int count = 0;

		while (min != max)
		{
			count++;
			++min;
		}

		return count;
	}

	bool CheckDate(int m_year, int m_month, int m_day)
	{
		if (m_year < 0 || m_month < 1 || m_month > 12 ||
			m_day > GetMonthDay(m_year, m_month) || m_day < 1)
		{
			return false;
		}
		
		return true;
	}

	//ȡ��ַ���������

	//��ͨȡ��ַ��������غ���
	Date* operator&()
	{
		//return nullptr;
		return this;
	}

	//��const���ε�ȡ��ַ��������غ���
	const Date* operator&() const
	{
		//return nullptr;
		return this;
	}

	//��Ԫ����������
	friend ostream& operator<<(ostream& rout, Date& rdate);
	friend istream& operator>>(istream& rin, Date& rdate);

private:
	int m_year;
	int m_month;
	int m_day;
};

//ȫ�ֺ��� 
ostream& operator<<(ostream& rout, Date& rdate)
{
	rout << rdate.m_year << "��" << rdate.m_month << "��" << rdate.m_day << "��";

	return rout;
}

istream& operator>>(istream& rin, Date& rdate)
{
	while (1)
	{
		cout << "�����������գ�";
		rin >> rdate.m_year >> rdate.m_month >> rdate.m_day;

		if (rdate.CheckDate(rdate.m_year, rdate.m_month, rdate.m_day) == true)
		{
			break;
		}
		else
		{
			cout << "�Ƿ����ڣ�����������" << endl;
		}
	}

	return rin;
}


/*
//ȫ�ֺ���
//���� == ���� ���� ����������Ϊ�����Ĳ������Լ��ٿ������������Ч��
bool operator==(const Date& rdatef, const Date& rdateb)
{
	return rdatef.m_year == rdateb.m_year
		&& rdatef.m_month == rdateb.m_month
		&& rdatef.m_day == rdateb.m_day;
}
*/


int main()
{
	/*Date date1(2025, 5, 5);
	Date date2(2027, 6, 10);
	cout << date1 - date2 << endl;*/

	/*Date date1;
	Date date2;
	cin >> date1 >> date2;
	cout << date1 << "\t" << date2;*/

	Date date1(2025, 5, 5);
	const Date date2(2027, 6, 10);
	date1.DatePrint();
	date2.DatePrint();

	//Date date1(2025, 5, 5);
	//Date date2(2027, 6, 10);

	//cout << (date1 > date2) << endl;  // false
	//cout << (date2 > date1) << endl;  // true
	//cout << (date1 < date2) << endl;  // true
	//cout << (date2 < date1) << endl;  // false
	//cout << (date1 == date2) << endl; // false
	//cout << (date1 == date1) << endl; // true
	//cout << (date1 != date2) << endl; // true
	//cout << (date2 != date2) << endl; // false
	//cout << (date1 >= date2) << endl; // false
	//cout << (date2 >= date1) << endl; // true
	//cout << (date1 <= date2) << endl; // true
	//cout << (date2 <= date1) << endl; // false


	//Date date1(2025, 5, 31);
	//date1.DatePrint();
	//Date date2 = date1++; // ����++
	//date1.DatePrint();
	//date2.DatePrint();

	//Date date3(2025, 10, 1);
	//date3.DatePrint();
	//Date date4 = date3--; // ����--
	//date3.DatePrint();
	//date4.DatePrint();

	//Date date1(2025, 5, 31);
	//date1.DatePrint();
	//Date date2 = ++date1; // ǰ��++
	//date1.DatePrint();
	//date2.DatePrint();

	//Date date3(2025, 10, 1);
	//date3.DatePrint();
	//Date date4 = --date3; // ǰ��--
	//date3.DatePrint();
	//date4.DatePrint();

	/*Date date1(2025, 5, 5);
	date1.DatePrint();
	Date date2 = date1 += -100;
	date1.DatePrint();
	date2.DatePrint();*/

	/*Date date1(2025, 5, 5);
	date1.DatePrint();
	Date date2 = date1 -= 100;
	date1.DatePrint();
	date2.DatePrint();*/

	/*Date date1(2025, 5, 5);
	date1.DatePrint();
	Date date2 = date1 - 10000;
	date1.DatePrint();
	date2.DatePrint();*/

	/*Date date1(2025, 5, 5);
	Date date2(2027, 6, 10);
	Date date3(2035, 10, 1);
	date2.DatePrint();
	date3.DatePrint();
	date3 = date2 = date1;
	date1.DatePrint();
	date3.DatePrint();*/

	/*Date date1(2025, 5, 5);
	date1.DatePrint();
	Date date2 = date1 + 100;
	date1.DatePrint();
	date2.DatePrint();*/

	/*Date date1(2025, 5, 5);
	date1.DatePrint();
	Date date2(date1 += 100);
	date1.DatePrint();
	date2.DatePrint();*/

	/*Date date2(2025, 5, 5);
	Date date3(2025, 5, 5);*/

	////���÷�ʽ������
	//cout << (date1 == date2) << endl;
	//cout << (date2.operator==(date3)) << endl;

	//Date date1(2025, 5, 5); // ���ù��캯��
	//Date date2(date1);      // ���ÿ������캯��
	//Date date3 = date1;

	//date2.DatePrint();
	//date3.DatePrint();

	return 0;
}