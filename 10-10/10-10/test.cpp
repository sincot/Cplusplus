#include <string>
#include <iostream>
#include <vector>

using namespace std;

//// Person ��
//class Person
//{
//public:
//	void identity()
//	{}
//
//protected:
//	string m_name;        // ����
//	string m_address;     // סַ
//	string m_tel;         // �绰
//	int m_age;            // ����
//};
//
//// ��ʦ��
//class Teacher : public Person
//{
//public:
//	void teaching()
//	{}
//
//protected:
//	string m_title;       // ְ��
//};
//
//// ѧ����
//class Student : public Person
//{
//public:
//	void learning()
//	{}
//
//protected:
//	string m_stuid;       // ѧ��
//};

//template<class T>
//class Stack : public vector<T>
//{
//public:
//	void push_back(const T& val)
//	{
//		vector<T>::push_back(val);
//	}
//};

//class Basic
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class Derive : public Basic
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//
//int main()
//{
//	Derive d;
//	d.fun(10);
//	d.fun();
//
//	return 0;
//};

void test()
{
	//Student stu("lisi");
	/*Student stu;
	stu.Print();*/

	//int a = 10;
	//double& ra1 = a;	   // ����
	//const double& ra2 = a; // ��ȷ

	//string& str1 = "10";		// ����
	//const string& str2 = "10";  // ��ȷ
	/*Teacher tea;
	Student stu;

	tea.identity();
	stu.identity();*/
}

/*
// Person ��
class Person
{
public:
	// ���캯��
	Person(int age = 18)
		: m_age(age)
	{
		cout << "Person()" << endl;
	}

	// ��������
	~Person()
	{
		cout << "~Person" << endl;
	}

	// �������캯��
	Person(const Person& rp)
		: m_age(rp.m_age)
	{
		cout << "Person(const Person& rp)" << endl;
	}

	// ��ֵ���غ���
	Person& operator=(const Person& rp)
	{
		if (this != &rp)
		{
			m_age = rp.m_age;
		}

		cout << "Person& operator=(const Person& rp)" << endl;

		return *this;
	}

protected:
	int m_age;       // ����
};

// Student ��
class Student : public Person
{
public:
	// ���캯��
	Student(const string& name = "zhangsan", int age = 20)
		: Person(age)
		, m_name(name) 
	{
		cout << "Student()" << endl;
	}

	// �������캯��
	Student(const Student& rs)
		: Person(rs)
		, m_name(rs.m_name)
	{
		cout << "Student(const Student& rs)" << endl;
	}

	// ��ֵ���غ���
	Student& operator=(const Student& rs)
	{
		if (this != &rs)
		{
			Person::operator=(rs); // �������ĳ�Ա����
			m_name = rs.m_name;
		}

		cout << "Student& operator=(const Student& rs)" << endl;

		return *this;
	}

	// ��������
	~Student()
	{
		//Person::~Person();
	}

protected:
	string m_name ;  // ����
};
*/

// ǰ������
class Student;

class Person
{
public:
	// ��Ԫ����������
	friend void Display(const Person& rp, const Student& rs);

protected:
	string m_name; // ����
};

class Student : public Person
{
public:
	// ��Ԫ����������
	friend void Display(const Person& rp, const Student& rs);

protected:
	int m_stuid; // ѧ��
};

void Display(const Person& rp, const Student& rs)
{
	cout << rp.m_name << endl;
	cout << rs.m_stuid << endl;
}

int main()
{
	//Person per(20);
	/*Student stu1("lisi", 18);
	Student stu2(stu1);*/
	/*Student stu3("wangwu", 35);
	stu1 = stu3;*/

	return 0;
}
