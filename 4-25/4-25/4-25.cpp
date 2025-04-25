#include <iostream>

////半缺省
//void Func(int a = 10, int b = 20, int c)
//{
//	std::cout << "a = " << a << " b = " << b
//		<< " c = " << c << std::endl;
//}

//半缺省
//void Func(int a = 10, int b, int c = 30)
//{
//	std::cout << "a = " << a << " b = " << b
//			  << " c = " << c << std::endl;
//}

////以下两个Add函数构成重载 —— 参数类型不同
//int Add(int x, int y)
//{
//	x + y;
//}
//
//int Add(double x, double y)
//{
//	x + y;
//}
//
////以下两个Add函数构成函数重载 —— 参数个数不同
//int Add(int x, int y, int z)
//{
//	x + y + z;
//}
//
//int Add(int x, int y)
//{
//	x + y;
//}
//
////以下两个Add函数构成函数重载 —— 参数类型的顺序不同
//int Add(int x, double y)
//{
//	x + y;
//}
//
//int Add(double x, int y)
//{
//	x + y;
//}
//
////函数的返回值不同不能作为构成重载的条件
//int Add(int x, int y)
//{
//	return x + y;
//}
//double Add(int x, int y)
//{
//	return x + y;
//}

/*
int main()
{
	int a = 1;
	int& b = a; //对变量a取别名，b就是变量a的别名

	int g = 10;
	b = g;

	return 0;
}
*/

/*
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void Swap(int& x, int& y) //x是m的别名，y是n的别名
{
	int tmp = x;
	x = y;
	y = tmp;
}
*/


struct Stu
{
	int id;
	int name[20];
	int age;
	int sex[20];
	//……
};

void Func1(struct Stu* pstu)
{ }

void Func1(struct Stu& stu)
{ }

/*
//使用二级指针作为函数的参数
void Swap(int** ppx, int** ppy)
{
	int* tmp = *ppx;
	*ppx = *ppy;
	*ppy = tmp;
}
*/

/*
typedef struct SList
{
	int arr[100];
}SL;
*/

/*
//使用引用作为函数的参数
void Swap(int*& rpx, int*& rpy)
{
	int* tmp = rpx;
	rpx = rpy;
	rpy = tmp;
}

int Func1()
{
	int ret = 1;

	return ret;
}

int Func2(SL& sl, int i)
{
	sl.arr[i] = 0;
	return sl.arr[i];
}

int& Func3(SL& sl, int i)
{
	sl.arr[i] = 0;
	return sl.arr[i];
}
*/

/*
int& Func()
{
	int ret = 1;

	return ret;
}

int& Func1()
{
	int ret1 = 20;

	return ret1;
}

int main()
{   
	int& x = Func();
	std::cout << x << std::endl;
	Func1();
	std::cout << x << std::endl;
*/
	//SL sl;

	/*int x = 1;
	int y = 2;
	int* px = &x;
	int* py = &y;

	std::cout << "交换前：" << " x的地址 " << px
		<< " y的地址 " << py << std::endl;
	Swap(px, py);
	std::cout << "交换后：" << " x的地址 " << px
		<< " y的地址 " << py << std::endl;*/

	/*int a = 1;
	int b = 2;
	std::cout << "交换前：" << " a = " << a
		<< " b = " << b << std::endl;
	Swap(&a, &b);
	std::cout << "交换后：" << " a = " << a
		<< " b = " << b << std::endl;

	int m = 10;
	int n = 20;
	std::cout << "交换前：" << " m = " << m
		<< " n = " << n << std::endl;
	Swap(m, n);
	std::cout << "交换后：" << " m = " << m
		<< " n = " << n << std::endl;*/

	//int*& rpx = px; //对指针变量px取别名，叫rpx
	//int*& rpy = py; //对指针变量py取别名，叫rpy

	//return 0;
//}


void Func(const int& rx)
{ }

int main()
{
	int a = 10;
	const int b = 20;
	double d = 3.14;

	const int& r1 = a;
	const int& r2 = b;
	const int& r3 = 10;   
	const int& r4 = a * 4;

	Func(a);
	Func(b);
	Func(10);
	Func(a * 4);
	Func(d);
	

	/*const int a = 10;
	int& ra = a;*/

	/*int b = 0;
	int& rb = b;
	const int& rrb = b;

	const int c = 30;
	const int& rc = c;
	int z = c;*/
	return 0;
}


