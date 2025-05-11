#include <iostream>
#include "5-11.h"

using namespace std;

void STInit(ST* pst, int n)
{
	pst->arr = nullptr;
	pst->size = 0;
	pst->capacity = n;
}

void STPush(ST* pst, STDateType x)
{
	pst->arr[pst->size] = x;
	pst->size++;
}

/*
int Add(int x, int y)
{
	return x + y;
}

double Add(double x, double y)
{
	return x + y;
}

short Add(short x, short y)
{
	return x + y;
}
*/

/*
//以下两个 Add 函数构成函数重载 —— 参数类型不同
int Add(int x, int y)
{
	return x + y;
}

double Add(double x, double y)
{
	return x + y;
}

//以下两个 Add 函数构成函数重载 —— 参数个数不同
short Add(short x, short y)
{
	return x + y;
}

short Add(short x, short y, short z)
{
	return x + y + z;
}

//以下两个 Add 函数构成函数重载 —— 参数顺序不同
long Add(int x, long y)
{
	return x + y;
}

int Add(long x, int y)
{
	return x + y;
}

//以下两个 Func 函数构成函数重载 —— 参数的个数不同
void Func()
{
	cout << "Func( )" << endl;
}

void Func(int n = 4)
{
	cout << "Func( int n )" << endl;
}
*/

/*
// 全缺省函数
void Func(int x = 10, int y = 20, int z = 30)
{
	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
}

//半缺省函数
void Func(int x, int y = 20, int z = 30)
{
	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
}

void Func(int x, int y, int z = 30)
{
	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
}
*/

/*
void Func(int x = 10, int y = 20, int z)
{
	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
}
*/

/*
void Func(int x, int y = 20, int z = 30)
{
	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
}
*/

/*
void Swap(int& rx, int& ry)
{
	int tmp = rx;
	rx = ry;
	ry = tmp;
}

struct Test
{
	int arr[100000];
	int size = 0;
	int capacity = 0;
};

void Func(struct Test& rtst)
{}

void Swap(int*& rpx, int*& rpy)
{
	int* tmp = rpx;
	rpx = rpy;
	rpy = tmp;
}
*/

/*
int Func1()
{
	int ret = 1;

	return ret;
}

int Func2(ST& st, int i)
{
	return st.arr[i];
}

int& Func(ST& st, int i)
{
	st.arr[i] = 0;
	return st.arr[i];
}
*/

void Func(const int& r)
{
	cout << r << endl;
}

int main()
{
	int a = 1;
	int& ra = a;
	ra = 2;

	int* pa = &a;
	*pa = 3;
	
	/*
	* 
	int a = 10;
	int b = 20;
	double c = 3.14;
	const int& r1 = a;         
	const int& r2 = b;                         

	Func(r1);
	Func(r2);
	Func(10);
	Func(c);
	Func(a * 4);
	*/

	/*
	int a = 10;
	int b = 20;
	double c = 3.14;
	const int& r1 = a;          //给变量取别名
	const int& r2 = b;          //给变量取别名
	const int& r3 = 30;         //给常量取别名 
	const int& r4 = c;          //类型转换中间值
	//当表达式运算完毕后会计算出一个结果，这个结果存储在临时对象中
	const int& r5 = a * 4;    
	*/

	/*
	int a = 1;
	int& ra = a;
	int b = a;
	*/

	/*
	int x = 10;
	int& rx = x;
	const int& r = x;
	*/

	/*
	int x = 10;
	int& rx = x;

	const int y = 20;
	const int& ry = y;
	*/
	
	/*
	ST st;
	for (int i = 0; i < 4; i++)
	{
		cout << (Func(st, i) += 1) << "\t" << endl;
	}
	*/

	/*
	int x = 10;
	int y = 20;
	int* px = &x;
	int* py = &y;
	cout << "交换前：px = " << px << "\tpy = " << py << endl;
	Swap(px, py);
	cout << "交换后：px = " << px << "\tpy = " << py << endl;
	*/

	/*Test tst;
	Func(tst);*/

	/*
	int x = 10;
	int y = 20;
	cout << "交换前：x = " << x << "\ty = " << y << endl;
	Swap(x, y);
	cout << "交换后：x = " << x << "\ty = " << y << endl;
	*/

	/*int x = 20;
	int& rx = x;
	int y = 30;
	rx = y;*/

	/*
	int a = 10;
	int& ra = a;    // 给同一个变量取多个别名
	int& rb = a;
	int& rra = ra;  // 给别名的别名取别名
	int& rrb = ra;

	cout << "a = " << a << "  \t" << &a << endl;
	cout << "ra = " << ra << "  \t" << &ra << endl;
	cout << "rb = " << rb << "  \t" << &rb << endl;
	cout << "rra = " << rra << "\t" << &rra << endl;
	cout << "rrb = " << rrb << "\t" << &rrb << endl;
	*/

	//Func(1, 2);

	/*
	//不传参 x y z 使用的都是缺省值
	Func(); 

	//只传一个实参，那么 x 会使用指定的实参，y z 使用的是缺省值
	Func(1);

	//传两个实参，那么 x y 会使用指定的实参，z 使用的是缺省值
	Func(1, 2);

	//全部都传实参，那么 x y z 都会使用指定的实参
	Func(1, 2, 3);
    */

	return 0;
}
