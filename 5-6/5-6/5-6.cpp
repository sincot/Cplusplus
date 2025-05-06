#include <iostream>

using namespace std;

//class Test
//{
//public:
//	Test(char ch)
//		: digital(ch)
//	{
//		cout << " " << endl;
//	}
//
//private:
//	char digital;
//};

class Date
{
public:
	void DatePrint()
	{
		cout << m_year << "年" << m_month << "月"
			<< m_day << "日" << endl;
	}


	Date(int& rdate, int year = 1, int month = 1, int day = 1)
		:m_month(month)
		, m_day(day)
		, m_year(year)
		, m_ret(rdate)
		, m_buf(6)
	{

	}

	/*Date(int& rdate, int year = 1, int month = 1, int day = 1)
		:m_month(month)
		, m_day(day)
		, m_ret(rdate)
		, m_buf(6)
		, m_character('G')
	{

	}*/

	/*Date(int& rdate, int year = 1, int month = 1, int day = 1)
		:m_month(month)
		, m_day(day)
		, m_ret(rdate)
		, m_buf(6)
		, m_character('G')
	{

	}*/

	/*Date(int& rdate, int year = 1, int month = 1, int day = 1)
		:m_month(month)
		, m_day(day)
		, m_year(year)
		, m_ret(rdate)
		, m_buf(6)
	{

	}*/

private:
	int m_year;
	int m_month = 6;
	int m_day = 10;

	int& m_ret;             
	const int m_buf = 20;   
	//Test m_character;
};

//class A
//{
//public:
//	A(int txt)
//	 : m_txt1(txt)
//	{
//
//	}
//
//	A(int txt1, int txt2)
//		:m_txt1(txt1), m_txt2(txt2)
//	{
//
//	}
//
//	int GetTxt1() const
//	{
//		return m_txt1;
//	}
//
//	void APrint()
//	{
//		cout << m_txt1 << " " << m_txt2 << endl;
//	}
//
//private:
//	int m_txt1;
//	int m_txt2;
//};
//
//class B
//{
//public:
//	B(const A& txt)
//		: m_work1(txt.GetTxt1())
//	{
//
//	}
//
//private:
//	int m_work1;
//	int m_work2;
//};
//
//class C
//{
//public:
//	void CPrint()
//	{
//		cout << s_c << endl;
//	}
//
//	static int GetC()
//	{
//		return s_c;
//	}
//
//private:
//	//声明
//	static int s_c;
//};
//
////定义
//static int s_c = 0;

class Test;

class Work
{
public:
	friend void TotalPrint(const Work& work, const Test& test);

private:
	int m_work1;
	int m_work2;
};

class Test
{
public:
	friend void TotalPrint(const Work& work, const Test& test);

private:
	int m_test1;
	int m_test2;
};

void TotalPrint(const Work& work, const Test& test)
{
	cout << work.m_work1 << work.m_work2 << endl;
	cout << test.m_test1 << test.m_test2 << endl;
}

int main()
{
	Work work;
	Test test;
	TotalPrint(work, test);
	
	/*A txt1 = 5;
	A txt2 = { 5, 6 };
	B work1 = txt1;
	const B work2 = txt2;*/

	/*A a = { 5, 6 };
	a.APrint();*/

	/*int ret = 2035;
	Date date(ret, 2025, 5, 6);*/

	return 0;
}