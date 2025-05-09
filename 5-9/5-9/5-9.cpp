#include <iostream>
#include <new>

using namespace std;

class Test
{
public:
	//有参的默认构造函数
	Test(int test)
		: m_test(test)
	{
		cout << "调用了有参的构造函数" << endl;
	}

	//无参的默认构造函数
	Test()
		: m_test(1)
	{
		cout << "调用了无参的构造函数" << endl;
	}

	/*
	~Test()
	{
		cout << "调用了析构函数" << endl;
	}
	*/

private:
	int m_test;
};

typedef int STDataType;
class Stack
{
public:
	Stack(int n = 4)
	{
		m_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == m_a)
		{
			perror("malloc申请空间失败");
			return;
		}
		m_capacity = n;
		m_top = 0;
	}

	Stack(const Stack& st)
	{
		// 需要对_a指向资源创建同样⼤的资源再拷⻉值
		m_a = (STDataType*)malloc(sizeof(STDataType) * st.m_capacity);
		if (nullptr == m_a)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		memcpy(m_a, st.m_a, sizeof(STDataType) * st.m_top);
		m_top = st.m_top;
		m_capacity = st.m_capacity;
	}

	void Push(STDataType x)
	{
		if (m_top == m_capacity)
		{
			int newcapacity = m_capacity * 2;
			STDataType* tmp = (STDataType*)realloc(m_a, newcapacity *
				sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			m_a = tmp;
			m_capacity = newcapacity;
		}
		m_a[m_top++] = x;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;
		free(m_a);
		m_a = nullptr;
		m_top = m_capacity = 0;
	}
private:
	STDataType* m_a;
	size_t m_capacity;
	size_t m_top;
};

/*
//int 类型
void Swap(int& px, int& py)
{
	int tmp = px;
	px = py;
	py = tmp;
}

//double类型
void Swap(double& px, double& py)
{
	double tmp = px;
	px = py;
	py = tmp;
}

//char类型
void Swap(char& px, char& py)
{
	char tmp = px;
	px = py;
	py = tmp;
}
*/

/*
template<typename T>
void Swap(T& left, T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}
*/

template<typename T>
T Add(const T& left, const T& right)
{
	return left + right;
}

char Add(const char& left, const char& right)
{
	return left + right;
}

/*
template<typename T1, typename T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}

template<typename T1, typename T2>
T2 Add(const T1& left, const T2& right)
{
	return left + right;
}
*/

/*
typedef int SLDateType;
class SeqList
{
private:
	SLDateType* m_arr;
	int m_capacity;
	int m_size;
};
*/

template<typename T>
class SeqList
{
private:
	T* m_arr;
	int m_capacity;
	int m_size;
};

int main()
{
	//类模板的实例化
	SeqList<int> SL1;
	SeqList<double>SL2;

	/*int i = 10;
	int j = 20;
	double m = 3.14;
	double n = 1.76;
	char ch1 = 'A';
	char ch2 = 'P';

	cout << Add<int>(i, j) << endl;
	cout << Add<double>(m, n) << endl;
	cout << Add<int>(i, m) << endl;
	cout << Add<double>(i, m) << endl;*/


	/*
	cout << Add(i, j) << endl;
	cout << Add(m, n) << endl;
	cout << Add(i, m) << endl;
	*/

	/*int m = 10;
	int n = 10;
	double p = 3.14;
	double q = 1.79;
	Swap(m, n);
	Swap(p, q);*/

	/*Test* ptr1 = new Test[10];
	delete[] ptr1;*/

	/*Stack* pst1 = new Stack(1);
	delete pst1;*/

	/*
	for (int i = 0; i < 10000; i++)
	{
		//一次开辟4KB大小的内存空间
		int* p1 = (int*)malloc(sizeof(int*) * 1024 * 1024); 
		if (p1 != NULL)
		{
			cout << i << ":\t" << p1 << endl;
		}
		else
		{
			break;
		}
	}
	*/
	
	/*
	try //抛异常
	{
		for (int i = 0; i < 100000; i++)
		{
			//一次开辟4MB大小的内存空间
			int* p2 = new int[1024 * 1024];
			cout << i << " \t" << p2 << endl;
		}
	}
	catch(const exception& e) // 捕获异常
	{
		cout << e.what() << endl;
	}
	*/

	/*
	for (int i = 0; i < 100000; i++)
	{
		//一次开辟4KB大小的内存空间
		int* p2 = new int[1024 * 1024];
		if (p2 != NULL)
		{
			cout << i << ":\t" << p2 << endl;
		}
		else
		{
			break;
		}
	}
	*/

	/*Test* ptr1 = new Test(10);
	delete ptr1;
	Test* ptr3 = new Test[5]{ 1, 2, 3, 4, 5 };
	delete[] ptr3;*/

	return 0;
}