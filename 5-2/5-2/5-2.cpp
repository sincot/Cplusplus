#include <iostream>

//class Stu
//{
//public:
//	Stu(int id, char name[], int age)
//	{
//	    //std::cout << " " << std::endl;
//	}
//private:
//	int m_id;
//	char m_name[20];
//	int m_age;
//};

/*
class Date
{
public:

	//�������ڳ�ʼ��
	Date(int year = 1, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	

	Date(int& rret, int year = 1, int month = 1, int day = 1)
		:m_ret(rret)
		,m_bef(3)
		,m_year(year)
		,m_month(month)
		,m_day(day)
	{

	}

private:
	int m_year = 2027;
	int m_month = 6;
	int m_day = 10;

	int& m_ret;
	const int m_bef;
};

class Test
{
public:
	//���캯�� --- һ������
	Test(int txt1)
		:m_txt1(txt1)
	{

	}

	int GetTxt1() const
	{
		return m_txt1;
	}

	//���캯�� --- ��������
	Test(int txt1, int txt2)
		:m_txt1(txt1)
		,m_txt2(txt2)
	{

	}

private:
	int m_txt1 = 10;
	int m_txt2 = 20;
};

class Work
{
	//�ڲ��� --- A��Work���ڲ���
	class A
	{
	public:
		A()
		{
			++m_count;
		}

		//��̬��Ա���� --- û��thisָ��
		static int GetCount()
		{
			return m_count;
		}

	private:
		//����
		static int m_count;
		int m_date;
	};

public:
	Work(const Test& test)
		:m_work1(test.GetTxt1())
	{

	}
private:
	int m_work1;
	int m_work2;
};

//����
int Work::A::m_count = 0;
*/

/*
int main()
{
	std::cout << sizeof(Work) << std::endl;

	////���������ʽ����ת��
	//Test test1 = 1;
	//Test test2 = { 1, 2 };

	//Work work1 = test1;
	//const Work work2 = test2;

	//const Test& test2 = 2;

	int ret = 0;
	Date data1(ret, 2025, 5, 2);

	return 0;
}
*/

/*
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int a = 10;
	int b = 20;
	int ret = Add(a, b);
	++ret;
	printf("%d ", ret);

}
*/

int main()
{
	/*
	int a = 10;
	int b = 20;
	int c = 3.14;
	const int& r1 = a; // ������ȡ����
	const int& r2 = b; // ������ȡ����
	const int& r3 = 30; // ������ȡ����
    //�����ʽ������Ϻ������һ����������������������ʱ������
	const int& r4 = a * 4; // ����ʱ����ȡ����
	const int& r5 = c;
	const double& r6 = c;

	std::cout << sizeof(r1) << std::endl;
	std::cout << sizeof(r6) << std::endl;
	*/

	int a = 1;
	int& ra = a;
	ra = 2;

	int* ptr = &a;
	*ptr = 3;

	return 0;
}