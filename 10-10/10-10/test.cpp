#include <string>
#include <iostream>
#include <vector>

using namespace std;

//// Person 类
//class Person
//{
//public:
//	void identity()
//	{}
//
//protected:
//	string m_name;        // 姓名
//	string m_address;     // 住址
//	string m_tel;         // 电话
//	int m_age;            // 年龄
//};
//
//// 老师类
//class Teacher : public Person
//{
//public:
//	void teaching()
//	{}
//
//protected:
//	string m_title;       // 职称
//};
//
//// 学生类
//class Student : public Person
//{
//public:
//	void learning()
//	{}
//
//protected:
//	string m_stuid;       // 学号
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
	//double& ra1 = a;	   // 错误
	//const double& ra2 = a; // 正确

	//string& str1 = "10";		// 错误
	//const string& str2 = "10";  // 正确
	/*Teacher tea;
	Student stu;

	tea.identity();
	stu.identity();*/
}

/*
// Person 类
class Person
{
public:
	// 构造函数
	Person(int age = 18)
		: m_age(age)
	{
		cout << "Person()" << endl;
	}

	// 析构函数
	~Person()
	{
		cout << "~Person" << endl;
	}

	// 拷贝构造函数
	Person(const Person& rp)
		: m_age(rp.m_age)
	{
		cout << "Person(const Person& rp)" << endl;
	}

	// 赋值重载函数
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
	int m_age;       // 年龄
};

// Student 类
class Student : public Person
{
public:
	// 构造函数
	Student(const string& name = "zhangsan", int age = 20)
		: Person(age)
		, m_name(name) 
	{
		cout << "Student()" << endl;
	}

	// 拷贝构造函数
	Student(const Student& rs)
		: Person(rs)
		, m_name(rs.m_name)
	{
		cout << "Student(const Student& rs)" << endl;
	}

	// 赋值重载函数
	Student& operator=(const Student& rs)
	{
		if (this != &rs)
		{
			Person::operator=(rs); // 处理基类的成员变量
			m_name = rs.m_name;
		}

		cout << "Student& operator=(const Student& rs)" << endl;

		return *this;
	}

	// 析构函数
	~Student()
	{
		//Person::~Person();
	}

protected:
	string m_name ;  // 名字
};
*/

// 前置声明
class Student;

class Person
{
public:
	// 友元函数的声明
	friend void Display(const Person& rp, const Student& rs);

protected:
	string m_name; // 姓名
};

class Student : public Person
{
public:
	// 友元函数的声明
	friend void Display(const Person& rp, const Student& rs);

protected:
	int m_stuid; // 学号
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
