#include <iostream>

using namespace std;

void func1()
{
	/*
	string str1("hello world");

	// 普通迭代器
	string::iterator it1 = str1.begin();
	while (it1 != str1.end())
	{
		(*it1)++;
		cout << *it1 << "\t";
		it1++;
	}
	cout << endl;
	cout << str1 << endl << endl;
	*/

	/*
	const string str2("hello Cplusplus");
	
	// const 迭代器
	string::const_iterator it2 = str2.begin();
	while (it2 != str2.end())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
	cout << str2 << endl << endl;
	*/

	/*
	const string str2("hello Cplusplus");

	// const 迭代器
	string::const_iterator it2 = str2.cbegin();
	while (it2 != str2.cend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl << endl;
	cout << str2 << endl << endl;
	*/
}

void func2()
{
	/*
	string str3("13579");
	cout << str3 << endl << endl;

	string::reverse_iterator it3 = str3.rbegin();
	while (it3 != str3.rend())
	{
		(*it3)++;
		cout << *it3 << " ";
		it3++;
	}
	cout << endl << endl;
	cout << str3 << endl << endl;
	*/

	/*
	const string str4("24680");
	cout << str4 << endl << endl;

	string::const_reverse_iterator it4 = str4.rbegin();
	while (it4 != str4.rend())
	{
		cout << *it4 << " ";
		it4++;
	}
	cout << endl << endl;
	cout << str4 << endl << endl;
	*/

	/*
	const string str4("24680");
	cout << str4 << endl << endl;

	string::const_reverse_iterator it4 = str4.crbegin();
	while (it4 != str4.crend())
	{
		cout << *it4 << " ";
		it4++;
	}
	cout << endl << endl;
	cout << str4 << endl << endl;
	*/
}

void func3()
{
	/*
	string str1("hello world");
	cout << "max_size：" << str1.max_size() << endl << endl;
	cout << "    size：" << str1.size() << endl << endl;
	cout << "capacity：" << str1.capacity() << endl << endl;
	*/

	/*
	string str;
	cout << "    size：" << str.size() << endl << endl;
	cout << "capacity：" << str.capacity() << endl << endl;
	//获取当前串的capacity的大小
	size_t old = str.capacity();

	//往str中插入100个字符
	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('*');

	    //判断是否扩容了 —— 只需要比较当前串的capacity与old的大小
		//若不相等，就表明扩容了，并将当前的capacity打印出来
		if (str.capacity() != old)
		{
			cout << "capacity：" << str.capacity() << endl;
			old = str.capacity();
		}
	}
	*/

	/*
	string str;
	//获取当前串的capacity的大小
	size_t old = str.capacity();

	//往str中插入100个字符
	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('*');

		//判断是否扩容了 —— 只需要比较当前串的capacity与old的大小
		//若不相等，就表明扩容了，并将当前的capacity打印出来
		if (str.capacity() != old)
		{
			old = str.capacity();
		}
	}
	cout << "    size：" << str.size() << endl << endl;
	cout << "capacity：" << str.capacity() << endl << endl;

	for (size_t i = 0; i < 50; i++)
	{
		str.pop_back(); // 尾删
	}
	//缩容
	str.shrink_to_fit();
	cout << "    size：" << str.size() << endl << endl;
	cout << "capacity：" << str.capacity() << endl << endl;
	*/

	/*
	string str;
	//获取当前串的capacity的大小
	size_t old = str.capacity();
	//提前开辟好空间
	str.reserve(100);

	//往str中插入100个字符
	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('*');

		//判断是否扩容了 —— 只需要比较当前串的capacity与old的大小
		//若不相等，就表明扩容了，并将当前的capacity打印出来
		if (str.capacity() != old)
		{
			cout << "capacity：" << str.capacity() << endl << endl;
			old = str.capacity();
		}
	}
	cout << "    size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl << endl;
	*/

	/*
	string str2("hello cplusplus");
	cout << "size：" << str2.size() << endl;
	cout << "capacity：" << str2.capacity() << endl << endl;
	str2.clear();
	cout << "size：" << str2.size() << endl;
	cout << "capacity：" << str2.capacity() << endl << endl;
	*/
}

void func4()
{
	/*
	string str3("hello C++");
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl << endl;
	str3.reserve(50);
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl << endl;
	*/

	/*
	// size < n < capacity
	string str3("hello C++");
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl << endl;
	str3.reserve(12);
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl << endl;
	*/

	/*
	// n < size
	string str3("hello C++");
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	str3.resize(5);
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	*/

	/*
	// n > size 明确传递了参数c
	string str3("hello C++");
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	str3.resize(20, '*');
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	*/

	/*
	// n > size 未明确传递了参数c
	string str3("hello C++");
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	str3.resize(20);
	cout << "    size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	*/

	/*
	string str4("02468");
	//下面越界访问了，编译器会报错，为什么
	//因为这里的越界行为是函数来检查的
	//检查到越界行为后，函数中的assert断言就会执行，使程序中断
	cout << str4[6] << endl;
	
	// 也可以用at函数来检查是否存在越界行为
	// 与 [ ] 不同的是，at检查到越界行为后会抛异常
	

	//下面越界访问了，编译器不会报错，为什么
	//因为这里的越界行为是编译器来检查的
	//编译器对于数组的越界行为是一种抽查行为
	int array[] = { 0, 2, 4, 6, 8 };
	cout << array[6] << endl;
	*/
}

void func5()
{
	/*
	string str5("hello world");
	str5.push_back(' ');
	cout << str5 << endl;
	str5.append("and space"); // 使用了函数3
	cout << str5 << endl << endl;

	string str6("hello world");
	cout << str6 << endl;
	str6.append(str6);        // 使用了函数1
	cout << str6 << endl << endl;

	string str7("hello world");
	cout << str7 << endl;
	str7.append(10, '$');    // 使用了函数5
	cout << str7 << endl << endl;
	*/
}


void func6()
{
	/*
	string str1("hello world");
	str1.push_back(' ');
	cout << str1 << endl;
	str1 += str1;           // 使用了函数1
	cout << str1 << endl << endl;

	string str2("hello world");
	str2.push_back(' ');
	cout << str2 << endl;
	str2 += "and space";   // 使用了函数2
	cout << str2 << endl << endl;

	string str3("hello world");
	str3.push_back(' ');
	cout << str3 << endl;
	str3 += '*';           // 使用了函数3
	cout << str3 << endl << endl;
	*/
}

void func7()
{
	/*
	string str1("hello world");
	cout << str1 << endl;
	str1.insert(6, str1);                  // 使用了函数1
	cout << str1 << endl << endl;

	string str2("hello world");
	str2.insert(6, "space and ");          // 使用了函数2
	cout << str2 << endl << endl;

	string str3("hello world");
	str3.insert(6, 10, '*');               // 使用了函数3
	cout << str3 << endl << endl;          

	string str4("hello world");
	str4.insert(str4.begin(), 10, '*');    // 使用了函数3       
	cout << str4 << endl << endl;
	*/
}

void func8()
{
	/*
	string str1("hello world");
	cout << str1 << endl;
	str1.erase(5, 1);            // 从下标为5的位置开始删除1个字符
	cout << str1 << endl << endl;

	string str2("hello world");
	str2.erase(5);               // 从下标为5的位置开始删除npos个字符
	cout << str2 << endl << endl;

	string str3("hello world");
	str3.erase(5, 20);           // 从下标为5的位置开始删除20个字符
	cout << str3 << endl << endl;
	*/

	/*
	string str1("hello  world");
	cout << str1 << endl;
	str1.replace(5, 1, str1);              // 使用了函数1
	cout << str1 << endl << endl;

	string str2("hello  world");
	str2.replace(5, 1, " space and ");    // 使用了函数2
	cout << str2 << endl << endl;

	string str3("hello  world");
	str3.replace(5, 1, 1, '*');           // 使用了函数3
	cout << str3 << endl << endl;

	string str4("hello world");
	str4.replace(5, 1, 10, '*');          // 使用了函数3
	cout << str4 << endl << endl;
	*/

	/*
	//方法1：使用 replace 函数
	string str("   water graphically @ g mail com   ");
	cout << str << endl;
	//使用find函数 —— 寻找空字符串
	size_t pos = str.find(' ');

	//npos为string类中的成员变量
	while (pos != string::npos)
	{
		str.replace(pos, 1, "%%");

		// 继续去找 —— 让 find 从 pos + 2 位置往后查找
		pos = str.find(' ', pos + 2);
	}
	cout << str << endl;
	*/


	//方法2：使用 operator+= 函数
	string str("   water graphically @ g mail com   ");
	cout << str << endl << endl;

	// 定义一个新的字符串
	string s;

	//用范围 for 遍历字符串
	for (auto ch : str)
	{
		// 若遍历到的字符为 ' ' 字符，那么新字符串就 += "%%"
		if (ch == ' ')
		{
			s += "%%";
		}
        // 若遍历到的字符不为 ' ' 字符，那么新字符串就 += ch
		else
		{
			s += ch;
		}
	}
	cout << s << endl;
}

int main()
{
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	//func6();
	//func7();
	func8();

	return 0;
}