#include <iostream>

using namespace std;

//class Animal
//{
//public:
//	virtual void call()
//	{
//		cout << "动物叫" << endl;
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	virtual void call()
//	{
//		cout << "小狗叫" << endl;
//	}
//};

/*
class Animal
{
public:
	virtual Animal* call()
	{
		cout << "动物叫" << endl;
		return nullptr;
	}
};

class Dog : public Animal
{
public:
	virtual Dog* call()
	{
		cout << "小狗叫" << endl;
		return nullptr;
	}
};

void Func(Animal* ptr)
{
	ptr->call();
}
*/

//int main()
//{
//	Animal animal;
//	Dog dog;
//	Func(&animal);
//	Func(&dog);
//
//	return 0;
//}

//void Func(Animal& ptr)
//{
//	ptr.call();
//}

//void Func(Animal& ptr)
//{
//	ptr.call();
//}
//


//class A
//{
//public:
//	virtual void func(int val = 1)
//	{ 
//		cout << "A->" << val << endl; 
//	}
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(long val = 0) override
//	{ 
//		cout << "B->" << val << endl; 
//	}
//};

//class A
//{
//public:
//	virtual void func(int val = 1) final
//	{
//		cout << "A->" << val << endl;
//	}
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0)
//	{
//		cout << "B->" << val << endl;
//	}
//};


//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->func();
//
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}

//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B : public A {
//public:
//	~B()
//	{
//		cout << "~B()->delete:" << m_p << endl;
//		delete m_p;
//	}
//protected:
//	int* m_p = new int[10];
//};
//
//int main()
//{
//	/*A a;
//	B b;*/
//
//	A* p1 = new A;
//	A* p2 = new B;
//
//	delete p1;
//	delete p2;
//
//	return 0;
//}

//int main()
//{
//
//	A* p1 = new A;
//	A* p2 = new B;
//
//	delete p1;
//	delete p2;
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1) 
//	{ 
//		std::cout << "A->" << val << std::endl; 
//	}
//
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(long val = 0) override
//	{ 
//		std::cout << "B->" << val << std::endl; 
//	}
//};

//class A
//{
//public:
//	virtual void func(int val = 1) final
//	{
//		std::cout << "A->" << val << std::endl;
//	}
//
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0)
//	{
//		std::cout << "B->" << val << std::endl;
//	}
//};

void test()
{
	/*int i = 18;
	double d = 3.14;

	cout << i;
	cout << d;*/
}

void test2()
{
	/*int a = 10;
	double b = 3.14;
	func(a);
	func(b);
	func(a, b);*/
	/*cout << a;
	cout << b;*/

	//Dog dog;
	//Animal animal;
}
//class Animal
//{
//public:
//	virtual void call() = 0;
//};
//
//class Dog : public Animal
//{
//public:
//};

/*
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Func2()" << endl;
	}

	virtual void Func3()
	{
		cout << "Func3()" << endl;
	}

protected:
	int m_a = 18;
	char m_ch = 'a';
};
*/


//class Animal
//{
//public:
//	void call()
//	{
//		cout << "动物叫" << endl;
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	virtual void call()
//	{
//		cout << "汪汪叫" << endl;
//	}
//};
//
//class Cat : public Animal
//{
//public:
//	virtual void call()
//	{
//		cout << "喵喵叫" << endl;
//	}
//};
//
//void Display(Animal& ptr)
//{
//	ptr.call();
//}


//
//int main()
//{
//	Animal animal1;
//	Animal animal2;
//
//	return 0;
//}

//class Person
//{
//public:
//	virtual void identity()
//	{
//		cout << "Person" << endl;
//	}
//
//	virtual void func1()
//	{}
//
//	virtual void func2()
//	{}
//
//protected:
//	string m_name;
//	int m_age;
//};
//
//class Student : public Person
//{
//public:
//	virtual void identity()
//	{
//		cout << "Studnet" << endl;
//	}
//
//	virtual void func1()
//	{}
//
//	virtual void fun3()
//	{}
//
//protected:
//	string m_stuid;
//};

//class Teacher
//{
//public:
//	virtual void teaching()
//	{
//		cout << "teaching" << endl;
//	}
//};
//
//class Student
//{
//public:
//	virtual void learning()
//	{
//		cout << "learning" << endl;
//	}
//};
//
//class AY : public Teacher, public Student
//{
//public:
//	virtual void teaching()
//	{}
//
//	virtual void learning()
//	{}
//};

//int main()
//{
//	/*Person per1;
//	Person per2;*/
//
//	//AY ay;
//
//	return 0;
//}


class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
	void func5() { cout << "Base::func5" << endl; }
protected:
	int a = 1;
};

class Derive : public Base
{
public:
	// 重写基类的func1
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func1" << endl; }
	void func4() { cout << "Derive::func4" << endl; }
protected:
		int b = 2;
};

int main()
{
	int i = 0;
	static int j = 1;
	int* p1 = new int;
	const char* p2 = "xxxxxxxx";
	printf("栈: % p\n", &i);
	printf("静态区: % p\n", &j);
	printf("堆: % p\n", p1);
	printf("常量区: % p\n", p2);
	cout << endl;

	Base b;
	Derive d;
	Base * p3 = &b;
	Derive * p4 = &d;
	printf("Base虚表地址: % p\n", *(int*)p3);
	printf("Derive虚表地址: % p\n", *(int*)p4);
	printf("虚函数地址: % p\n", &Base::func1);
	printf("普通函数地址: % p\n", &Base::func5);

	return 0;
}


//int main()
//{
//	/*Person per1;
//	Person per2;*/
//
//	Person per;
//	Student stu;
//
//	return 0;
//}

//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//	return 0;
//}

//void func(int i);
//void func(double d);
//void func(int i, double d);


//class Animal
//{
//public:
//	virtual Animal* call()
//	{
//		cout << "动物叫" << endl;
//		return nullptr;
//	}
//};
//
//class Dog : public Animal
//{
//private:
//	virtual Dog* call()
//	{
//		cout << "小狗叫" << endl;
//		return nullptr;
//	}
//};

//class Animal
//{
//public:
//	virtual Animal* call() = 0;
//};
//
//class Dog : public Animal
//{
//private:
//	virtual Dog* call()
//	{
//		cout << "小狗叫" << endl;
//		return nullptr;
//	}
//};

//class Animal
//{
//public:
//	virtual void call() = 0;
//};
//
//class Dog : public Animal
//{
//public:	
//};
//
//void Func(Animal& ptr)
//{
//	ptr.call();
//}

/*Animal animal;
	Dog dog;

	Func(animal);
	Func(dog);*/

//void func(int i);
//void func(double d);
//
//int main()
//{
//	int i;
//	double d;
//	func(i);
//	func(d);
//
//	return 0;
//}

//void func(int i, double d);
//
//int main()
//{
//	int i = 18;
//	double d = 3.14;
//	func(i, d);
//
//	return 0;
//}

//void Func(Animal& ptr)
//{
//	ptr.call();
//}

//void Func(Animal* ptr)
//{
//	ptr->call();
//}

//class A
//{
//public:
//	virtual void func(int val = 1)
//	{
//		std::cout << "A->" << val << std::endl;
//	}
//	
//	virtual void test() { func(); }
//};
//	
//class B : public A
//{
//public:
//	virtual void func(int val = 0)
//	{
//		std::cout << "B->" << val << std::endl;
//	}
//};
//
//int main()
//{
//	B* p = new B;
//	p->func();
//
//	return 0;
//}

//int main()
//{
//	B* p = new B;
//	p->test();
//
//	return 0;
//}


//class Basic
//{
//public:
//	virtual void func1()
//	{
//		cout << "func1()" << endl;
//	}
//
//	virtual void func2()
//	{
//		cout << "func2()" << endl;
//	}
//
//	virtual void func3()
//	{
//		cout << "func3()" << endl;
//	}
//
//protected:
//	int m_a;
//	char m_ch;
//};
//
//int main()
//{
//	Basic b;
//	cout << sizeof(b) << endl;
//
//	return 0;
//}