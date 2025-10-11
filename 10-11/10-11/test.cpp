#include <string>
#include <iostream>

using namespace std;

//class Person
//{
//public:
//	string m_name;
//	static int m_count;
//};
//
//int Person::m_count = 0;
//
//class Student : public Person
//{
//public:
//	int m_age;
//};

//class Person
//{
//public:
//	string m_name;
//};
//
//class Student : public Person
//{
//protected:
//	int m_stuid;
//};
//
//class Teacher : public Person
//{
//protected:
//	string m_title;
//};
//
//class AY : public Student, public Teacher
//{
//protected:
//	string m_blog;
//};


class Person
{
public:
    Person(const char* name)
        :m_name(name)
    {}
    string m_name; // 姓名
};

class Student : virtual public Person
{
public:
    Student(const char* name, int id)
        : Person(name)
        , m_stuid(id)
    {}
protected:
    int m_stuid; // 学号
};

class Teacher : virtual public Person
{
public:
    Teacher(const char* name, const string& title)
        :Person(name)
        , m_title(title)
    {}
protected:
    string m_title; // 职位
};

class AY : public Student, public Teacher
{
public:
    AY(const char* name1, const char* name2, const char* name3)
        :Person(name3)
        , Student(name1, 111111)
        , Teacher(name2, "讲师")
    {}

protected:
    string m_blog;
};

int main()
{
    AY ay("zhangsan", "lisi", "wangwu");

    return 0;
}

/*
class Base1 { public:  int m_b1; };
class Base2 { public:  int m_b2; };
class Derive : public Base1, public Base2 { public: int m_d; };

int main()
{
    Derive d;
    Base1* p1 = &d;
    Base2* p2 = &d;
    Derive* p3 = &d;

    return 0;
}
 */

void test()
{
	/*cout << &per.m_name << endl;
	cout << &stu.m_name << endl;

	cout << &per.m_count << endl;
	cout << &stu.m_count << endl;

	cout << &Person::m_count << endl;
	cout << &Student::m_count << endl;*/
}

//int main()
//{
//	AY ay;
//	ay.m_name; // 访问不明确，访问的是Student，还是Teacher？
//
//	ay.Student::m_name = "zhangsan";
//	ay.Teacher::m_name = "wangwu";
//
//	return 0;
//}