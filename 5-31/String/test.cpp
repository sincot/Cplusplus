#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// ��ģ��
//template <typename T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		m_array = new T[m_capacity];
//		m_top = 0;
//		m_capacity = capacity;
//	}
//
//private:
//	T* m_array;
//	size_t m_top;
//	size_t m_capacity;
//};

// ����һ���ַ�����ֻ����һ�ε���ĸ
int firstUniqChar(string s)
{
	// �ü��������˼�루��ϣ��˼�룩
	int count[26] = { 0 };
	for (auto e : s)
	{
		count[e - 'a']++;
	}
	for (size_t i = 0; i < s.size(); i++)
	{
		if (count[s[i] - 'a'] == 1)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	//string str1;                  // ��Ӧ����1
	//string str2("hello world");   // ��Ӧ����2
	//string str3(10, '$');         // ��Ӧ����3
	//string str4(str3);            // ��Ӧ����4
	//
	//cout << "str1 = " << str1 << endl;
	//cout << "str2 = " << str2 << endl;
	//cout << "str3 = " << str3 << endl;
	//cout << "str4 = " << str4 << endl;
	
	/*string str1("hello cplusplus");
	string str2 = str1;
	string str3 = "hello world";
	
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;*/

	/*string str1("hello world");
	cout << "size = " << str1.size() << endl;
	cout << "length = " << str1.length() << endl;*/

	//string str("hello world");
	//// ����
	//for (size_t i = 0; i < str.size(); i++)
	//{
	//	cout << str[i] << " ";
	//}
	//cout << endl;
	//// �޸�
	//for (size_t i = 0; i < str.size(); i++)
	//{
	//	str[i] += 1;
	//	cout << str[i] << " ";
	//}
	//cout << endl;
	
	//string str("hello cplusplus");
	//string::iterator it1 = str.begin(); 	//ָ������
	//// ����
	//while (it1 != str.end())
	//{
	//	cout << *it1 << " ";
	//	// ������
	//	it1++;
	//}
	//cout << endl;
 //   // �޸�
	//it1 = str.begin();
	//while (it1 != str.end())
	//{
	//	(*it1)++;
	//	cout << *it1 << " ";
	//	it1++;
	//}
	//cout << endl;

	// ʹ�� begin �� end ����
	string str1("hello cplusplus");
	string::const_iterator it1 = str1.begin();
	while (it1 != str1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	// ʹ�� rbegin �� rend ����
	string str2("hello cplusplus");
	string::const_iterator it2 = str2.cbegin();
	while (it2 != str2.cend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;


	
	// string �Ĺ���
	// �������õĹ��캯��
	/*string str1;
	string str2("hello cplusplus");
	string str3(str2);*/

	/*string str4(str2, 2, 5);
	string str5(10, '&');
	string str6 = str5;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;*/

	// �޸� string ������е�ֵ
	// ����1������operator[]����
	/*for (size_t i = 0; i < str2.size(); i++)
	{
		str2[i]++;
	}
	cout << str2 << endl;*/

	// ������
	//string::iterator it1 = str2.begin();
	//while (it1 != str2.end())
	//{
	//	// �޸ĵ������е�ֵ
	//	(*it1)++;
	//	//�õ�����������
	//	it1++;
	//}
	//cout << str2 << endl;

	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	reverse(v.begin(), v.end());
	vector<int>::iterator it2 = v.begin();
	while (it2 != v.end())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;*/

	/*list<int> lt;
	lt.push_back(2);
	lt.push_back(4);
	lt.push_back(6);
	lt.push_back(8);
	reverse(lt.begin(), lt.end());
	list<int>::iterator it3 = lt.begin();
	while (it3 != lt.end())
	{
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;

	for (auto e : str2)
	{
		cout << e << " ";
	}
	cout << endl << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl << endl;*/

	//reverse(str2.begin(), str2.end());
	//string::iterator it1 = str2.begin();
	//while (it1 != str2.end())
	//{
	//	//�õ�����������
	//	it1++;
	//}
	//cout << str2 << endl;

	/*
	string str("123456");
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	// ������ Vs �������£�����ô���ݵ�
	string s;
	size_t old = s.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		s.push_back('%');
		if (s.capacity() != old)
		{
			old = s.capacity();
		}
	}
	cout << "old size = " << s.size() << endl;
	cout << "old capacity = " << s.capacity() << endl;
	s.clear();
	cout << endl;
	cout << "new size = " << s.size() << endl;
	cout << "new capacity = " << s.capacity() << endl;
	*/

	/*
	// ��������� ���� ��ͨ������
	string::iterator it1 = str.begin();
	while (it1 != str.end())
	{
		(*it1)++;
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	// ��������� ���� const������
	string::const_iterator it2 = str.cbegin();
	while (it2 != str.cend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;

	// ��������� ���� ��ͨ������
	string::reverse_iterator it3 = str.rbegin();
	while (it3 != str.rend())
	{
		(*it3)++;
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;

	//��������� ���� const������
	string::const_reverse_iterator it4 = str.crbegin();
	while (it4 != str.crend())
	{
		cout << *it4 << " ";
		it4++;
	}
	cout << endl;
	*/

	return 0;
}



