/*
1.下⾯程序编译运⾏结果是（）
A、编译报错 B、运⾏崩溃 C、正常运⾏
*/

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}

/*
2.下⾯程序编译运⾏结果是（）
A、编译报错 B、运⾏崩溃 C、正常运⾏
*/

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//		cout << _a << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}

/*
3.下⾯程序编译运⾏结果是（）
A、编译报错 B、运⾏崩溃 C、正常运⾏
*/
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	(*p).Print();
//	return 0;
//}

#include <iostream>

class Data
{
public:
	/*
	void DataInit(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	*/

	/*
	//以下两个函数的功能与DataInit函数的功能一致
	//构造函数 --- 无参
	Data()
	{
		m_year = 1;
		m_month = 1;
		m_day = 1;
	}

	//构造函数 --- 有参
	Data(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	*/

	//构造函数
	/*
	Data(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	*/

	// 拷贝构造函数
	// 这里的参数必须是引用
	// 相当与data2(data1)，rd就是data1的别名
	// 在C++中规定自定义类型的对象在直接的拷贝与传值传参的拷贝时，都要调用拷贝构造函数
	/*
	Data(Data& rd)
	{
		//把data1的year，month，day都拷贝给data2
		m_year = rd.m_year;
		m_month = rd.m_month;
		m_day = rd.m_day;
	}
	*/

	Data(int year = 1, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	void DataPrint()
	{
		std::cout << m_year << "/" << m_month
			<< "/" << m_day << std::endl;
	}


	bool operator==(const Data& rdata2)
	{
		// 位于 == 左边的参数的前面编译器默认会加上this->
		// 当然也可以自己写上
		return m_year == rdata2.m_year
			&& m_month == rdata2.m_month
			&& m_day == rdata2.m_day;
	}

private:
	int m_year;
	int m_month;
	int m_day;
};

class Func
{
public:
	void func()
	{
		
	}
};

void fun()
{
	
}
int main()
{
	void(*Func1)() = fun; //函数指针
	(*Func1)();

	//调用成员函数 --- func
	// 指定类域，在函数声明的时候前面也要加上类域
	void(Func::*Func2)() = &Func::func;
	Func f; //实例化对象
	(f.*Func2)();


	/*Data data1(2025, 4, 27); 
	Data data2(2028, 6, 28); 
	bool ret = data1 == data2;
	
	std::cout << ret << std::endl;*/

	/*
	data1.DataPrint();
	data2.DataPrint();
	*/

	/*data1.DataInit(2001, 10, 9);
	data2.DataInit(2025, 4, 26);

	data1.DataPrint();
	data2.DataPrint();*/

	return 0;
}