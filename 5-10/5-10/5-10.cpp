#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<typename T>
class SeqList
{
public:
	SeqList()
	{
		m_arr = new T[4];
		m_capacity = m_size = 0;
	}

private:
	T* m_arr;
	int m_size;
	int m_capacity;
};

/*
class string
{
public:

private:
	char* m_arr;
	size_t m_size;
	size_t m_capacity;
};
*/

int main()
{
	/*int arr[] = { 1, 2, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}*/

	/*
	int arr[] = { 1, 2, 3, 4, 5 };
	for (auto& e : arr)
	{
		cout << e << " ";
	}
	*/

	/*auto x = 10;
	auto y = 3.14;
	auto p1 = &x;
	auto* p2 = &x;*/

	/*
	string str("hello world");

	//�Զ�ȡ���������ݸ�ֵ��e
	//�Զ��жϽ���
	//�Զ�����
	for (auto& e : str)
	{
		e++;
	}
	cout << str << endl;
	*/

	/*for (auto e : str)
	{
		e++;
	}
	cout << str << endl;*/

	/*
	//auto x = 10;    //�Զ�ʶ��Ϊ int    ����
	//auto y = 3.14;  //�Զ�ʶ��Ϊ double ����
	//cout << x << endl;
	//cout << y << endl;

	//int& z = x;
	//auto m = z;
	//m++;
	*/

	/*for (size_t i = 0; i < str.size(); i++)
	{
		str[i]++;
	}

	cout << str << endl;*/

	/*string str("hello world");
	cout << str << endl;*/

	/*
	vector<int> v; //����ģ��ʵ����һ������
	//��˳�����β��5������
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		it++;
	}
	*/

	/*
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << endl;
		it++;
 	}
	*/

	/*string::iterator it = str.begin();
	while (it != str.end())
	{
		(*it)++;
		it++;
	}
	
	cout << str << endl;*/
	/*string::iterator it = str.begin(); 
	while (it != str.end())            
	{
		(*it)++;
		it++;
	}

	cout << str << endl;*/

	/*string str1;
	string str2("hello world");
	string str3(2, '*');
	string str4(str2);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;*/

	//string str1;                     // ��Ӧ1
	//string str2("hello world");
	//string str3(str2);               // ��Ӧ2
	//string str4(str2, 2, 7);         // ��Ӧ3
	//string str5(str2, 2);            // ��Ӧ3
	//string str6(str2, 2, 70);        // ��Ӧ3
	//const char* str = "hello world";  
	//string str7(str);                // ��Ӧ4
	//string str8(str, 2);             // ��Ӧ5
	//string str9(2, '*');             // ��Ӧ6

	//cout << str1 << endl;
	//cout << str2 << endl;
	//cout << str3 << endl;
	//cout << str4 << endl;
	//cout << str5 << endl;
	//cout << str6 << endl;
	//cout << str7 << endl;
	//cout << str8 << endl;
	//cout << str9 << endl;

	/*
	// ��ģ��ʵ����
	SeqList<int> SL1;
	SeqList<double> SL2;
	*/

	/*
	char str1[] = "hello";
	char str2[] = "���";
	str2[3]++;
	str2[3]++;
	str2[3]++;
	*/

	return 0;
}