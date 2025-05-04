#include <iostream>

using namespace std;

/*
class A
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
	}

private:
	int _a;
};

int main()
{
	A* p = nullptr;
	p->Print();
	return 0;
}
*/

/*
class A
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
		cout << _a << endl;
	}

private:
	int _a;
};

int main()
{
	A* p = nullptr;
	p->Print();
	return 0;
}
*/

/*
class A
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
		cout << _a << endl;
	}

private:
	int _a;
};

int main()
{
	A aa;
	A* p = &aa;
	p->Print();
	return 0;
}
*/

/*
class A
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
	}

private:
	int _a;
};

int main()
{
	A* p = nullptr;
	(*p).Print();
	return 0;
}
*/

/*
//C语言中的struct的用法
typedef struct SListNode
{
	int data;
	struct SListNode* next;
};
*/

//C++中的struct的用法
//struct SListNode
//{
//	void SLNodeInit()
//	{
//		next = nullptr;
//	}
//
//	int data;
//	SListNode* next;
//};

/*
class SListNode
{
	void SLNodeInit()
	{
		next = nullptr;
	}

	int data;
	SListNode* next;
};
*/

//class Test
//{
//	void TestInit()
//	{
//
//	}
//};


class Date
{
public:
	//以下两个函数均为构造函数，这两个构造函数构成了函数重载

	
	//全缺省的默认构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	
	//无参的默认构造函数
	Date()
	{
		m_year = 1;
		m_month = 1;
		m_day = 1;
	}

	void DatePrint()
	{
		cout << m_year << "年" << m_month
			<< "月" << m_day << "日" << endl;
	}

	/*
	void DatePrint()
	{
		cout << this << endl;
		cout << m_year << "年" << m_month
			<< "月" << m_day << "日" << endl;
	}
	*/

	/*
	void DatePrint(Date *this)
	{
		cout << this->m_year << "年" << this->m_month
			 << "月" << this->m_day << "日" << endl;
	}
	*/

private:
	int m_year;
	int m_month;
	int m_day;
};

typedef int STDataType;
class Stack
{
public:
	Stack(int n = 4)
	{
		m_arr = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == m_arr)
		{
			perror("malloc申请空间失败");
			return;
		}
		m_capacity = n;
		m_top = 0;
	}

	~Stack()
	{
		//若真的调用了析构函数，就打印"调用了析构函数"
		cout << "调用了析构函数" << endl;
		if (m_arr != nullptr)
		{
			free(m_arr);
			m_arr = nullptr;
		}

		m_capacity = m_top = 0;
	}

private:
	STDataType* m_arr;
	size_t m_capacity;
	size_t m_top;
};

// 两个Stack实现队列
class MyQueue
{
public:
	// 编译器默认⽣成MyQueue的构造函数调⽤了Stack的构造
	// 完成了两个成员的初始化
private:
	Stack pushst;
	Stack popst;
};

int main()
{
	Date date1(2025, 5, 2); // 构造函数
	Date date2(date1);      // 拷贝构造函数


	//MyQueue mq;
	//Stack st;

	/*Date date1();
	date1.DatePrint();*/

	/*date1.DatePrint(&date1);
	date2.DatePrint(&date2);*/
	
	/*Test tst;
	cout << sizeof(Test) << endl;
	cout << sizeof(tst) << endl;*/

	/*Date date1;
	Date date2;

	date1.m_day++;
	date2.m_day++;

	date1.DateInit(2025, 5, 4);
	date2.DateInit(2027, 6, 10);*/

	/*cout << sizeof(Date) << endl;
	cout << sizeof(date1) << endl;*/


	/*data1.DateInit();
	data1.DatePrint();*/

	////实例化出对象
	//Date date1;
	//Date date2;

	//date1.DatePrint();

	/*SListNode node;
	node.SLNodeInit();*/

	/*SListNode node;
	node.SLNodeInit();*/

	return 0;
}
