#include <string>
#include <iostream>

using namespace std;

//class Teacher
//{
//public:
//	void identity()
//	{}
//
//	void teaching()
//	{}
//private: 
//	string m_name;      // ����
//	string m_address;   // ��ַ
//	string m_tel;       // �绰
//	int m_age;          // ����
//
//	string m_title;     // ְλ
//};
//
//class Student
//{
//public:
//	void identity()
//	{}
//
//	void learning()
//	{}
//private:
//	string m_name;      // ����
//	string m_address;   // ��ַ
//	string m_tel;       // �绰
//	int m_age;          // ����
//
//	string m_stuid;     // ѧ��
//};

//class Person
//{
//public:
//	void identity()
//	{}
//
//protected:
//	string m_name;      // ����
//	string m_address;   // ��ַ
//	string m_tel;       // �绰
//	int m_age;          // ����
//};
//
//class Teacher : public Person
//{
//public:
//	void teaching()
//	{}
//
//protected:
//	string m_title;     // ְλ
//};
//
//class Student : public Person
//{
//public:
//	void learning()
//	{}
//
//protected:
//	string m_stuid;     // ѧ��
//};

//// ջ�̳� vector
//template<class T>
//class Stack : public vector<T>
//{
//public:
//	void push_back(const T& val)
//	{
//		vector<T>::push_back(val);
//	}
//};

//class Person
//{
//protected:
//	int m_age = 10;
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << Person::m_age << endl;
//	}
//protected:
//	int m_age = 20;
//};
//
//int main()
//{
//	Student stu;
//	stu.Print();
//
//	return 0;
//}

//class Basic
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class Derive : public Basic
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//int main()
//{
//	Derive b;
//	b.fun(10);
//	b.fun();
//
//	return 0;
//};

/*
class Person
{
public:
	// ���캯��
	Person(int age = 10)
		: m_age(age)
	{
		cout << "Person()" << endl;
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

	// ��������
	~Person()
	{
		cout << "~Person()" << endl;
	}

protected:
	int m_age;
};

class Student : public Person
{
public:
	// ���캯��
	Student(const string& name, int age = 18)
		//: m_age(age)
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
			Person::operator=(rs);
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
	string m_name;
};
*/

//class Person final
//{
//protected:
//	int m_age;
//};

/*
class Student;

class Person
{
public:
	friend void Display(const Person& rp, const Student& rs);
protected:
	string m_name; // ����
};

class Student : public Person
{
public:
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
	Student stu;
	Person per;
	Display(per, stu);

	return 0;
}
*/

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
//protected:
//	int m_stuid;
//};

//int main()
//{
//	Person per;
//	Student stu;
//
//	// m_name
//	cout << &per.m_name << endl;
//	cout << &stu.m_name << endl;
//
//	// m_count
//	cout << &per.m_count << endl;
//	cout << &stu.m_count << endl;
//
//	cout << Person::m_count << endl;
//	cout << Student::m_count << endl;
//
//	return 0;
//}

void test()
{
	//int a = 10;
	//double& d1 = a;		   // ����
	//const double& d2 = a;  // ��ȷ

	//string& str1 = "10";		// ����
	//const string& str2 = "10";  // ��ȷ
	/*Teacher tea;
	Student stu;

	tea.identity();
	stu.identity();*/

	/*Student stu1("lisi", 20);
	Student stu2(stu1);*/

	//Student stu;
	/*Student stu1("zhangsan", 20);
	Student stu2("lisi", 35);
	stu1 = stu2;*/
}

//class Person
//{
//public:
//	string m_name;
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	string m_title;
//};
//
//class Student : virtual public Person
//{ 
//protected:
//	string m_stuid;
//};
//
//class AY : public Teacher, public Student
//{
//protected:
//	string m_blog;
//};

/*
class Person
{
public:
	Person(const string& name)
		: m_name(name)
	{}

	string m_name; // ����
};

class Student : virtual public Person
{
public:
	Student(const string& name, const string& id)
		: Person(name)
		, m_stuid(id)
	{}

protected:
	string m_stuid; // ѧ��
};

class Teacher : virtual public Person
{
public:
	Teacher(const string& name, const string& title)
		: Person(name)
		, m_title(title)
	{}

protected:
	string m_title; // ְ��
};

class AY : public Student, public Teacher
{
public:
	AY(const string& name1, const string& name2, const string& name3)
		: Person(name3)
		, Student(name1, "111111")
		, Teacher(name3, "��ʦ")
	{ }

protected:
	string m_blog;
};

int main()
{
	AY ay("zhangsan", "lisi", "wangwu");

	return 0;
}
*/

//class Base1 { public:  int m_b1; };
//class Base2 { public:  int m_b2; };
//class Derive : public Base1, public Base2 { public: int m_d; };
//
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//
//	return 0;
//}


class Base1 { public:  int m_b1; };
class Base2 { public:  int m_b2; };
class Derive : public Base2, public Base1 { public: int m_d; };

int main()
{
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;

	return 0;
}

//int main()
//{
//	AY ay;
//	ay.m_name;  // ���ʲ���ȷ����֪�����ʵ�Student������Teacher
//
//	ay.Student::m_name = "zhangsan";
//	ay.Person::m_name = "wangwu";
//
//	return 0;
//}