#include <iostream>

using namespace std;

/*
class Test
{
public:
	//友元类的声明
	friend class Work;

private:
	int m_test1;
	int m_test2;
};

class Work
{
public:
	void TotalPrint(const Test& test)
	{
		cout << test.m_test1 << " " << test.m_test2 << endl;
		cout << m_work1 << " " << m_work2 << endl;
	}

private:
	int m_work1;
	int m_work2;
};
*/

/*
class Test
{
public:
	Test(int test)
		:m_test1(test)
	{

	}

	Test()
		: m_test1(7)
	{

	}

	~Test()
	{
		cout << "调用了~Test析构函数" << endl;
	}

	class Work
	{
	public:
		Work(int work1, int work2)
			: m_work1(work1)
			, m_work2(work2)
		{

		}

		Work()
			: m_work1(6)
			, m_work2(10)
		{

		}

		~Work()
		{
			cout << "调用了~Work析构函数" << endl;
		}

		void TotalPrint(const Test& test)
		{
			cout << m_work1 << " " << m_work2 << endl;
		}

	private:
		int m_work1;
		int m_work2;
	};

private:
	int m_test1;
	static int s_test2;
};

static int s_test2 = 2;

int main()
{
	Test test;
	cout << sizeof(Test) << endl;
	cout << sizeof(test) << endl;

	//有名对象
	Test test1;
	Test test2(5);
	//匿名对象
	Work();
	Work(5, 7);

	return 0;
}
*/

/*
//内存管理分析
int globalVar = 1; 
static int staticGlobalVar = 1;
void Test()
{
	static int staticVar = 1; 
	int localVar = 1;         
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	const char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}
*/

class Test
{
public:
	~Test()
	{
		cout << "~Test()" << endl;
	}

	Test(int test1)
		: m_test1(test1)
	{

	}

private:
	int m_test1;
};

int main()
{
	Test* ptr1 = new Test(1);
	delete ptr1;

	Test* ptr2 = new Test[10]{ 1, 2, 3, 4 };
	delete[] ptr2;

	/*Test* ptr1 = new Test;
	delete ptr1;

	Test* ptr2 = new Test[10];
	delete [] ptr2;*/

	return 0;
}