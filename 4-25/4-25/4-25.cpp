#include <iostream>

////��ȱʡ
//void Func(int a = 10, int b = 20, int c)
//{
//	std::cout << "a = " << a << " b = " << b
//		<< " c = " << c << std::endl;
//}

//��ȱʡ
//void Func(int a = 10, int b, int c = 30)
//{
//	std::cout << "a = " << a << " b = " << b
//			  << " c = " << c << std::endl;
//}

////��������Add������������ ���� �������Ͳ�ͬ
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
////��������Add�������ɺ������� ���� ����������ͬ
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
////��������Add�������ɺ������� ���� �������͵�˳��ͬ
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
////�����ķ���ֵ��ͬ������Ϊ�������ص�����
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
	int& b = a; //�Ա���aȡ������b���Ǳ���a�ı���

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

void Swap(int& x, int& y) //x��m�ı�����y��n�ı���
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
	//����
};

void Func1(struct Stu* pstu)
{ }

void Func1(struct Stu& stu)
{ }

/*
//ʹ�ö���ָ����Ϊ�����Ĳ���
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
//ʹ��������Ϊ�����Ĳ���
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

	std::cout << "����ǰ��" << " x�ĵ�ַ " << px
		<< " y�ĵ�ַ " << py << std::endl;
	Swap(px, py);
	std::cout << "������" << " x�ĵ�ַ " << px
		<< " y�ĵ�ַ " << py << std::endl;*/

	/*int a = 1;
	int b = 2;
	std::cout << "����ǰ��" << " a = " << a
		<< " b = " << b << std::endl;
	Swap(&a, &b);
	std::cout << "������" << " a = " << a
		<< " b = " << b << std::endl;

	int m = 10;
	int n = 20;
	std::cout << "����ǰ��" << " m = " << m
		<< " n = " << n << std::endl;
	Swap(m, n);
	std::cout << "������" << " m = " << m
		<< " n = " << n << std::endl;*/

	//int*& rpx = px; //��ָ�����pxȡ��������rpx
	//int*& rpy = py; //��ָ�����pyȡ��������rpy

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


