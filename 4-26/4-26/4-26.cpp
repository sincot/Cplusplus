#include <iostream>
//#include <stddef.h>

/*nline int Add(int x, int y)
{
	int ret = x + y;
	return ret;
}

int main()
{
	int ret = Add(10, 20);
	std::cout << ret << std::endl;

	return 0;
}*/

//void Func(int x)
//{
//	std::cout << "Func(int x)" << std::endl;
//}
//
//void Func(int* ptr)
//{
//	std::cout << "Func(int* ptr)" << std::endl;
//}

//class Test
//{
//public:
//	//成员函数
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//
//private:
//	//成员变量
//	int id;
//	int name[20];
//	int age;
//};

/*
typedef struct StackNodeC
{
	int* arr;
	int top;
	int capacity;
}StackC;
*/

/*
class Stack
{
public:
	int Add(int x, int y)
	{
		return x + y;
	}

private:
	int* arr;
	int top;
	int capacity;
};

class Queue
{
public:
	int Add(int x, int y)
	{
		return x + y;
	}
private:
	int* phead;
	int* ptail;
};
*/

//class Test
//{
//public:
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//
//	void Swap(int& rx, int& ry)
//	{
//		int tmp = rx;
//		rx = ry;
//		ry = tmp;
//	}
//
////private:
//	//总内存为96个字节
//	int id;
//	int name[20];
//	int age;
//	double high;
//};

class Data
{
public:
	void DataInit(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	void DataPrint()
	{
		//this = nullptr;
		//std::cout << this << std::endl;
		std::cout << m_year << "/" << m_month 
			      << "/" << m_day << std::endl;
	}

	/*
	void DataPrint(Data* this)
	{
		std::cout << this->m_year << "/" << this->m_month 
			      << "/" << this->m_day << std::endl;
	}
	*/

private:
	int m_year;
	int m_month;
	int m_day;
};

//class Test
//{
//public:
//	void Data()
//	{
//
//	}
//};

int main()
{
	Data data1;
	Data data2;

	data1.DataInit(2001, 10, 9);
	data2.DataInit(2025, 4, 26);

	data1.DataPrint();
	data2.DataPrint();

	data1.DataPrint(&data1);
	data2.DataPrint(&data2);

	data1.m_day++;
	data2.m_day++;

	/*
	std::cout << sizeof(Data) << std::endl;
	std::cout << sizeof(data1) << std::endl;
	*/

	/*Test tst1;
	Test tst2;

	std::cout << sizeof(Test) << std::endl;
	std::cout << sizeof(tst1) << std::endl;*/

	

	//Test tst; // 类实例化
	//Test tst1;
	//std::cout << sizeof(Test) << std::endl;
	//std::cout << sizeof(tst) << std::endl;

	/*int a = 10;
	int b = 20;
	tst.Add(a, b);
	tst.Swap(a, b);
	tst.age = 10;*/


	/*Stack st;
	st.Add(1, 2);*/
	//Func((void*)NULL);
	/*Func(0);
	Func(NULL)*/
	/*Func(0);
	Func(NULL);
	Func(nullptr);*/
	
	return 0;
}

//#ifndef NULL
//    #ifdef __cplusplus
//         #define NULL   0
//    #else
//         #define NULL ((void*)0)
//    #endif
//#endif