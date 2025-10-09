#include <string>
#include <iostream>
using namespace std;

// int ����
void swap(int& px, int& py)
{
	int tmp = px;
	px = py;
	py = tmp;
}

// char ����
void swap(char& px, char& py)
{
	char tmp = px;
	px = py;
	py = tmp;
}

// double ����
void swap(double& px, double& py)
{
	double tmp = px;
	px = py;
	py = tmp;
}

template<class T>
void swap(T& left, T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}

void test1()
{
	/*int i = 10;
	int j = 20;
	double m = 3.14;
	double n = 1.99;

	Add(i, j);
	Add(m, n);
	Add(i, n);*/
}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//template<class T1, class T2>
//int Add(const int& left, const int& right)
//{
//	return left + right;
//}

//typedef int SLDataType;
//class SeqList
//{
//private:
//	SLDataType* m_arr;
//	int m_size;
//	int m_capacity;
//};

//template<typename T>
//class SeqList
//{
//public:
//	void push_back(const T& val) {}
//
//private:
//	T* m_arr;
//	int m_size;
//	int m_capacity;
//};
//
//// ����д��
//void SeqList<T>::push_back(const T& val)
//{}
//
//// ��ȷд��
//template<typename T>
//void SeqList<T>::push_back(const T& val)
//{}

//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//void Test()
//{
//	Add(10, 20);     // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(10, 3.14);   // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���
//}

//#define N 100
//
//template<class T>
//class Stack
//{
//private:
//	T m_arr[N];
//	int m_top;
//	int m_capacity;
//};


template<class T, size_t N>
class Stack
{
private:
	T m_arr[N];
	int m_top;
	int m_capacity;
};

// ����
template<class T = int, size_t N>
class Stack
{
private:
	T m_arr[N];
	int m_top;
	int m_capacity;
};

// ��ȷ
template<class T, size_t N = 100>
class Stack
{
private:
	T m_arr[N];
	int m_top;
	int m_capacity;
};

// ��ȷ
template<class T = int, size_t N = 100>
class Stack
{
private:
	T m_arr[N];
	int m_top;
	int m_capacity;
};

//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
//template<>
//bool Less<int*>(int* left, int* right)
//{
//	return *left < *right;
//}
//
//template<>
//bool Less<string*>(string* left, string* right)
//{
//	return *left < *right;
//}

template<class T>
bool Less(const T& left, const T& right)
{
	return left < right;
}

//template<>
//bool Less<int*>(const int*& left, const int*& right)
//{
//	return *left < *right;
//}

template<>
bool Less<int*>(int* const & left, int* const & right)
{
	return *left < *right;
}

bool Less(int* left, int* right)
{
	return *left < *right;
}

// ��ģ��
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }

private:
	T1 m_data1;
	T2 m_data2;
};

// ȫ�ػ�
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }

private:
	int m_data1;
	char m_data2;
};

// ƫ�ػ�
template<class T1>
class Data<T1, char>
{
public:
	Data() { cout << "Data<T1, char>" << endl; }

private:
	T1 m_data1;
	char m_data2;
};

template<class T2>
class Data<int, T2>
{
public:
	Data() { cout << "Data<int, T2>" << endl; }

private:
	int m_data1;
	T2 m_data2;
};

// �Բ�����һ������
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }

private:
	T1 m_data1;
	T2 m_data2;
};

int main()
{
	cout << Less(10, 100) << endl;

	int* p1 = new int(10);
	int* p2 = new int(100);
	cout << Less(p1, p2) << endl;

	string* ptr1 = new string("10");
	string* ptr2 = new string("100");
	cout << Less(ptr1, ptr2) << endl;


	/*Stack<int, 10> st1;
	Stack<int, 1000> st2;*/
	/*SeqList<int> SL1;
	SeqList<string> SL2;*/
	/*int i = 10;
	int j = 20;
	double m = 3.14;
	double n = 1.99;

	cout << Add<int>(i, j) << endl;
	cout << Add<double>(m, n) << endl;
	cout << Add<int>(i, m) << endl;
	cout << Add<double>(i, m) << endl;*/

	return 0;
}