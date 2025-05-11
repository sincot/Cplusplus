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
//�������� Add �������ɺ������� ���� �������Ͳ�ͬ
int Add(int x, int y)
{
	return x + y;
}

double Add(double x, double y)
{
	return x + y;
}

//�������� Add �������ɺ������� ���� ����������ͬ
short Add(short x, short y)
{
	return x + y;
}

short Add(short x, short y, short z)
{
	return x + y + z;
}

//�������� Add �������ɺ������� ���� ����˳��ͬ
long Add(int x, long y)
{
	return x + y;
}

int Add(long x, int y)
{
	return x + y;
}

//�������� Func �������ɺ������� ���� �����ĸ�����ͬ
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
// ȫȱʡ����
void Func(int x = 10, int y = 20, int z = 30)
{
	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
}

//��ȱʡ����
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
	const int& r1 = a;          //������ȡ����
	const int& r2 = b;          //������ȡ����
	const int& r3 = 30;         //������ȡ���� 
	const int& r4 = c;          //����ת���м�ֵ
	//�����ʽ������Ϻ������һ��������������洢����ʱ������
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
	cout << "����ǰ��px = " << px << "\tpy = " << py << endl;
	Swap(px, py);
	cout << "������px = " << px << "\tpy = " << py << endl;
	*/

	/*Test tst;
	Func(tst);*/

	/*
	int x = 10;
	int y = 20;
	cout << "����ǰ��x = " << x << "\ty = " << y << endl;
	Swap(x, y);
	cout << "������x = " << x << "\ty = " << y << endl;
	*/

	/*int x = 20;
	int& rx = x;
	int y = 30;
	rx = y;*/

	/*
	int a = 10;
	int& ra = a;    // ��ͬһ������ȡ�������
	int& rb = a;
	int& rra = ra;  // �������ı���ȡ����
	int& rrb = ra;

	cout << "a = " << a << "  \t" << &a << endl;
	cout << "ra = " << ra << "  \t" << &ra << endl;
	cout << "rb = " << rb << "  \t" << &rb << endl;
	cout << "rra = " << rra << "\t" << &rra << endl;
	cout << "rrb = " << rrb << "\t" << &rrb << endl;
	*/

	//Func(1, 2);

	/*
	//������ x y z ʹ�õĶ���ȱʡֵ
	Func(); 

	//ֻ��һ��ʵ�Σ���ô x ��ʹ��ָ����ʵ�Σ�y z ʹ�õ���ȱʡֵ
	Func(1);

	//������ʵ�Σ���ô x y ��ʹ��ָ����ʵ�Σ�z ʹ�õ���ȱʡֵ
	Func(1, 2);

	//ȫ������ʵ�Σ���ô x y z ����ʹ��ָ����ʵ��
	Func(1, 2, 3);
    */

	return 0;
}
