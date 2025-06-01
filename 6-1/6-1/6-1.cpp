#include <iostream>
#include <string>

using namespace std;

/*
int main()
{
	/*string str("24680");
	string::reverse_iterator it1 = str.rbegin();
	while (it1 != str.rend())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	string::reverse_iterator it2 = str.rbegin();
	while (it2 != str.rend())
	{
		(*it2)++;
		cout << *it2 << " ";
		it2++;
	}*/

	
	//string str("13579");
	//// 使用 rbegin 和 rend
	//string::const_reverse_iterator it1 = str.rbegin();
	//while (it1 != str.rend())
	//{
	//	cout << *it1 << " ";
	//	it1++;
	//}
	//cout << endl;

	//// 使用 rbegin 和 rend
	//string::const_reverse_iterator it2 = str.crbegin();
	//while (it2 != str.crend())
	//{
	//	cout << *it2 << " ";
	//	it2++;
	//}
	//cout << endl;

	/*string str1("hello world");
	cout << "插入前： ";
	for (size_t i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;

	str1.push_back('$');
	cout << "插入后： ";
	for (size_t i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;


	string str2("hello cplusplus");
	cout << "删除前： ";
	for (size_t i = 0; i < str2.size(); i++)
	{
		cout << str2[i] << " ";
	}
	cout << endl;

	str2.pop_back();
	cout << "删除后： ";
	for (size_t i = 0; i < str2.size(); i++)
	{
		cout << str2[i] << " ";
	}
	cout << endl;*/
	
	//string str("gon");
	//cout << "old caapcity: " << str.capacity() << endl;
	//size_t old = str.capacity();
	//
	//// 不断的往 str 中插入100个数据
	//for (size_t i = 0; i < 100; i++)
	//{
	//	str.push_back('*');
	//	// 判断是否需要扩容
	//	// 当 old 的大小与当前字符串的capacity的大小不等时
	//	// 就会触发扩容机制
	//	if (str.capacity() != old)
	//	{
	//		cout << "new capacity: " << str.capacity() << endl;
	//	}
	//	old = str.capacity();
	//}

	/*string str1;
	string str2("");
	string str3(" ");
	string str4("hello");

	cout << str1.empty() << endl;
	cout << str2.empty() << endl;
	cout << str3.empty() << endl;
	cout << str4.empty() << endl;

	//string str("hello world");
	//cout << "size: " << str.size() << endl;
	//cout << "capacity: " << str.capacity() << endl;
	//cout << endl;

	//// 调用 clear 函数
	//str.clear();
	//cout << "size: " << str.size() << endl;
	//cout << "capacity: " << str.capacity() << endl;
	
    // 缩容失败
	//string str;
	//size_t old = str.capacity();
	//cout << "******缩容失败******" << endl;
	//// 不断的往 str 中插入100个数据
	//for (size_t i = 0; i < 100; i++)
	//{
	//	str.push_back('*');
	//}
	//cout << "size = " << str.size() << endl;
	//cout << "capacity = " << str.capacity() << endl;
	//cout << endl;

	//str.shrink_to_fit();
	//cout << "size = " << str.size() << endl;
	//cout << "capacity = " << str.capacity() << endl;
	//cout << endl;

	//// 缩容成功
	//cout << "******缩容成功******" << endl;
	////尾删 50 个字符
	//for (size_t i = 0; i < 50; i++)
	//{
	//	str.pop_back();
	//}
	//cout << "size = " << str.size() << endl;
	//cout << "capacity = " << str.capacity() << endl;
	//cout << endl;

	//str.shrink_to_fit();
	//cout << "size = " << str.size() << endl;
	//cout << "capacity = " << str.capacity() << endl;
    

	return 0;
}
*/

void func1()
{
	string str("24680");
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;

	/*
	// 扩容
	str.reserve(100);
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	// 缩容
	str.reserve(3);
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/
}

void func2()
{
	string str("hello world");
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << endl;

	/*
	str.resize(5);
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	str.resize(20);
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	// n > size
	str.resize(12);
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	str.resize(20, '$');
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

}

void func3()
{
	/*
	string str1("hello world");
	for (size_t i = 0; i < str1.size(); i++)
	{
		str1[i]++;
	}
	cout << str1 << endl;

	string str2("hello world");
	for (size_t i = 0; i < str2.size(); i++)
	{
		str2.at(i)++;
	}
	cout << str2 << endl;
	*/

	/*
	string str("hello world");
	str.at(12);
	*/
}

void func4()
{
	// append 函数
	/*
	string str(" hello world");
	cout << str << endl;
	str.append(str);
	cout << str << endl;
	str.append(" and space");
	cout << str << endl;
	str.append(10, '*');
	cout << str << endl;
	*/

	// operator += 函数
	/*
	string str(" hello world");
	cout << str << endl;
	str += str;
	cout << str << endl;
	str += " and space";
	cout << str << endl;
	str += '%';
	cout << str << endl;
	*/
}

void func5()
{
	/*
	string str("hello world");
	cout << str << endl;
	str.insert(6, "space and ");
	cout << str << endl;
	str.insert(0, 10, '*');
	cout << str << endl;
	*/

	/*
	string str1("hello world");
	cout << str1 << endl;
    // 两个参数都使用缺省值
	str1.erase();
	cout << str1 << endl << endl;

	string str2("hello world");
	cout << str2 << endl;
	// len 使用缺省值
	str2.erase(5);
	cout << str2 << endl << endl;

	string str3("hello world");
	cout << str3 << endl;
	// 都传参
	str3.erase(5, 1);
	cout << str3 << endl << endl;
	*/

	/*
	// replace 函数
	string str("hello world");
	cout << str << endl;
	str.replace(5, 2, "%&*");
	cout << str << endl;
	*/

	// 将字符串中的空格替换成"%%"
	/*
	//方法1： 使用 replace 函数
	string str("water geogra phically @ g . mail");
	cout << str << endl;
	// 寻找空格字符的位置
	size_t pos = str.find(' ');
	// 遍历字符串
	while (pos != string::npos)
	{
		str.replace(pos, 1, "%%");
		// 从当前pos位置 +2 的地方开始继续找空格字符的位置
		pos = str.find(' ', pos + 2);
	}
	cout << str << endl;
	*/

	/*
	// 方法2： 使用 += 函数
	string str("water geogra phically @ g . mail");
	cout << str << endl;
	// 再创建一个string类型的对象，来保存替换后的字符串
	string str1;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			str1 += "%%";
		}
		else
		{
			str1 += str[i];
		}
	}
	cout << str1 << endl;
	*/
}

void func6()
{
	/*string str("hello world");
	cout << str.c_str() << endl;*/

	// substr 函数
	/*
	string str1("hello world");
	string str2 = str1.substr();
	cout << str2 << endl;
	string str3 = str1.substr(4);
	cout << str3 << endl;
	string str4 = str1.substr(4, 3);
	cout << str4 << endl;
	*/
}

void test1()
{
	// reserve 函数
	// size < n < capacity
	/*
	string str("hello world");
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << endl;
	str.reserve(13);
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	// n > capacity
	string str("hello world");
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << endl;
	str.reserve(20);
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	string str("hello world");
	cout << "old caapcity: " << str.capacity() << endl;
	size_t old = str.capacity();
	str.reserve(100);

	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('*');
		if (str.capacity() != old)
		{
			cout << "new capacity: " << str.capacity() << endl;
		}
		old = str.capacity();
	}
	*/

	// resize 函数
	string str("hello world");
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << endl;
	/*
	str.resize(20, '@');
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << str << endl;
	*/

	/*
	str.resize(14, '@');
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << str << endl;
	*/

	/*
	// size < n < capacity
	str.resize(14);
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	str.resize(20);
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	cout << str << endl;
	*/

	/*
	// n < size
	str.resize(7);
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/
}

void test2()
{
	/*char arr[12] = "hello world";
	cout << arr[13] << endl;*/
	/*string str("hello world");
	cout << str[13] << endl;*/

	//string str("hello world ");
	//cout << str << endl;
	//str.append(str);          // 原型1
	//cout << str << endl;
	//str.append("and space");  // 原型2
	//cout << str << endl;    
	//str.append(10, '@');      // 原型3
	//cout << str << endl;

	/*
	string str("hello world ");
	cout << str << endl;
	str += str;            // 原型1
	cout << str << endl;
	str += " and space";   // 原型2
	cout << str << endl;
	str += '@';            // 原型3
	cout << str << endl;
	*/
}

void test3()
{
	/*
	string str("hello world");
	cout << str << endl;
	str.insert(6, "space and ");
	cout << str << endl;
	str.insert(6, 10, '*');
	cout << str << endl;
	*/

	/*
	string str1("hello world");
	cout << "删除前： " << str1 << endl;
	str1.erase();
	cout << "删除后： " << str1 << endl;
	cout << endl;
	
	string str2("cplusplus");
	cout << "删除前： " << str2 << endl;
	str2.erase(4);
	cout << "删除后： " << str2 << endl;
	cout << endl;

	string str3("watergraphiclaly");
	cout << "删除前： " << str3 << endl;
	str3.erase(4, 5);
	cout << "删除后： " << str3 << endl;
	cout << endl;
	*/

	/*string str1("hello world");
	cout << str1 << endl;
	str1.replace(6, 3, "$");
	cout << str1 << endl;
	cout << endl;

	string str2("hello world");
	cout << str2 << endl;
	str2.replace(6, 3, "abcdef");
	cout << str2 << endl;*/
}

void test4()
{
	/*string str("hello world");
	cout << str.c_str() << endl;*/

	// 获取空格之后部分的字符串
	/*string str("hello world");
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << endl;
	string ret = str.substr(6, str.size() - 6);
	cout << ret << endl;
	cout << "size = " << ret.size() << endl;*/

	// 将字符串中的空格字符替换成"%%"
	string str("water geographically @ g . mail");
	cout << str << endl;
	// 默认从下标为 0 的位置开始找
	size_t pos = str.find(' ');
	while (pos != string::npos)
	{
		str.replace(pos, 1, "%%");
		// 继续往后找，不需要再从下标为 0 的位置开始找了
		// 从下标为 pos + 2 的位置开始找
		pos = str.find(' ', pos + 2);
	}

	cout << str << endl;
}

void test5()
{
	// 求一个字符长串中最后一个单词的长度
	/*string str;
	getline(cin, str);
	size_t pos = str.rfind(' ');
	if (pos != string::npos)
	{
		cout << str.size() - pos - 1 << endl;
	}
	else
	{
		cout << str.size() << endl;
	}*/

	/*
	auto a = 10;
	auto b = 3.14;
	auto c = 'c';
	auto d = 2.1f;

	cout << "变量 a 的数据类型为： " << typeid(a).name() << endl;
	cout << "变量 b 的数据类型为： " << typeid(b).name() << endl;
	cout << "变量 c 的数据类型为： " << typeid(c).name() << endl;
	cout << "变量 d 的数据类型为： " << typeid(d).name() << endl;
	*/

	/*auto x = 10;
	auto y = 3.14;
	auto px = &x;
	auto* py = &y;

	cout << "变量 px 的数据类型为： " << typeid(px).name() << endl;
	cout << "变量 py 的数据类型为： " << typeid(py).name() << endl;*/

	/*string str("hello world");
	for (auto e : str)
	{
		cout << e << " ";
	}*/

	/*string str("hello world");
	for (auto& e : str)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : str)
	{
		e++;
		cout << e << " ";
	}*/
}

int main()
{
	//func1();
	//func2();
	//func3();
	//func4();
	//func5();
	//func6();

	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	/*
	try
	{
		func3();
	}
	catch(const exception& e)
	{
		cout << e.what() << endl;
	}
	*/

	return 0;
}