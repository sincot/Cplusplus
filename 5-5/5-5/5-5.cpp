#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	//拷贝构造函数
	// date2(date1) --- rdate是date1的别名
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
	//重载 == 符号
	bool operator==(const Date& rdatef, const Date& rdateb)
	{
		return rdatef.m_year == rdateb.m_year
			&& rdatef.m_month == rdateb.m_month
			&& rdatef.m_day == rdateb.m_day;
	}
	*/

	// 重载 == 符号
	bool operator==(const Date& rdate)
	{
		return m_year == rdate.m_year
			&& m_month == rdate.m_month
			&& m_day == rdate.m_day;
	}

	//重载 < 运算符
	bool operator<(const Date& rdate)
	{
		// 先把小的情况都找出来，返回true
		// 那么剩下的就是大的情况，直接返回false

		// 年小则小
		if (m_year < rdate.m_year)
		{
			return true;
		}
        //年相等，月小则小
		else if (m_year == rdate.m_year && m_month < rdate.m_month)
		{
			return true;
		}
		//年相等，月相等，天小则小
		else if (m_year == rdate.m_year && m_month == rdate.m_month && m_day < rdate.m_day)
		{
			return true;
		}
		
		return false;
	}

	//重载 != 运算符
	bool operator!=(const Date& rdate)
	{
		//对等于取反，就是不等于
		return !(*this == rdate);
	}

	//重载 <= 运算符
	bool operator<=(const Date & rdate)
	{
		//<= 就是 < 或者 == 
		return (*this < rdate) || (*this == rdate);
	}

	//重载 > 运算符
	bool operator>(const Date& rdate)
	{
		//对 <= 取反，就是大于
		return !(*this <= rdate);
	}

	//重载 >= 运算符
	bool operator>=(const Date& rdate)
	{
		//对 < 取反，就是大于等于
		return !(*this < rdate);
	}

	
	// 日期 += 天数 —— date + day(100)
	// +=天数之后，原对象会改变
	Date& operator+=(int day)
	{
		//处理参数day为负值的情况
		if (day < 0)
		{
			//调用 -= 重载函数
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

		//this指针指向的就是调用该函数的对象
		return *this;
	}

	//日期 + 天数 —— date + day(100)
	// + 天数之后，原对象不会改变，因此要事先将原对象拷贝一份
	Date operator+(int day)
	{
		//this指针指向的就是调用该函数的对象
		Date tmp(*this); // 调用了拷贝构造函数
        
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

	
	//日期 -= 天数
	// -= 天数之后，调用该函数的对象会改变
	Date& operator-=(int day)
	{
		//处理参数day为负值的情况
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

			//取上一个月份的天数
			m_day += GetMonthDay(m_year, m_month);
		}

		return *this;
	}
	
	//调用日期 -= 天数的函数来实现日期 - 天数
	Date operator-(int day)
	{
		Date tmp(*this);
		tmp -= day; //调用了日期 -= 天数的函数

		return tmp;
	}

	//前置++
	Date& operator++()
	{
		*this += 1;

		return *this;
	}

	//后置++
	Date operator++(int)
	{
		Date tmp(*this);
		tmp += 1;

		return tmp;
	}

	//前置--
	Date& operator--()
	{
		*this -= 1;

		return *this;
	}

	//后置--
	Date operator--(int)
	{
		Date tmp(*this);
	    tmp -= 1;

		return tmp;
	}

	/*
	//日期 - 天数
	// - 天数之后，调用该函数的对象不会改变
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

			//取上一个月份的天数
			tmp.m_day += GetMonthDay(tmp.m_year, tmp.m_month);
		}

		return tmp;
	}
	
	//调用日期 - 天数的函数来实现日期 -= 天数
	Date& operator-=(int day)
	{
		*this = *this - day;

		return *this;
	}
	*/

	/*
	//赋值运算符重载
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

	//日期 - 日期 —— datefront - datebefore
	int operator-(const Date& rdate)
	{
		//先假设 this 指针指向的日期对象为大的日期
		//rdate日期对象为小的日期
		Date max = *this;
		Date min = rdate;

		//若假设不正确，进行调整
		if (max < min) // 调用了 < 重载函数
		{
			max = rdate;
			min = *this;
		}

		//定义一个计算器变量
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

	//取地址运算符重载

	//普通取地址运算符重载函数
	Date* operator&()
	{
		//return nullptr;
		return this;
	}

	//被const修饰的取地址运算符重载函数
	const Date* operator&() const
	{
		//return nullptr;
		return this;
	}

	//友元函数的声明
	friend ostream& operator<<(ostream& rout, Date& rdate);
	friend istream& operator>>(istream& rin, Date& rdate);

private:
	int m_year;
	int m_month;
	int m_day;
};

//全局函数 
ostream& operator<<(ostream& rout, Date& rdate)
{
	rout << rdate.m_year << "年" << rdate.m_month << "月" << rdate.m_day << "日";

	return rout;
}

istream& operator>>(istream& rin, Date& rdate)
{
	while (1)
	{
		cout << "请输入年月日：";
		rin >> rdate.m_year >> rdate.m_month >> rdate.m_day;

		if (rdate.CheckDate(rdate.m_year, rdate.m_month, rdate.m_day) == true)
		{
			break;
		}
		else
		{
			cout << "非法日期，请重新输入" << endl;
		}
	}

	return rin;
}


/*
//全局函数
//重载 == 符号 —— 用引用来作为函数的参数可以减少拷贝次数，提高效率
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
	//Date date2 = date1++; // 后置++
	//date1.DatePrint();
	//date2.DatePrint();

	//Date date3(2025, 10, 1);
	//date3.DatePrint();
	//Date date4 = date3--; // 后置--
	//date3.DatePrint();
	//date4.DatePrint();

	//Date date1(2025, 5, 31);
	//date1.DatePrint();
	//Date date2 = ++date1; // 前置++
	//date1.DatePrint();
	//date2.DatePrint();

	//Date date3(2025, 10, 1);
	//date3.DatePrint();
	//Date date4 = --date3; // 前置--
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

	////调用方式有两种
	//cout << (date1 == date2) << endl;
	//cout << (date2.operator==(date3)) << endl;

	//Date date1(2025, 5, 5); // 调用构造函数
	//Date date2(date1);      // 调用拷贝构造函数
	//Date date3 = date1;

	//date2.DatePrint();
	//date3.DatePrint();

	return 0;
}