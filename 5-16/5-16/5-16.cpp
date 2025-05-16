#include <iostream>
#include <string>

using namespace std;

/*
void func1()
{
	/*
	string str1("hello world");
	// 获取空格以后的部分
	// 空格字符的下标为6，空格后面的字符串长度为5
	// 可以用size()函数 - 要求某字符后面的长度的下标
	string str2 = str1.substr(6, str1.size() - 6);
	cout << str1 << endl << endl;
	cout << str2 << endl;
	*/

	/*
	string str1("hello world");
	//获取空格字符以后的部分
	//也可以理解为直到字符串结束
	//那么substr的第二个参数可以不传实参，用缺省值npos
	string str2 = str1.substr(6);
	cout << str1 << endl << endl;
	cout << str2 << endl;
	
}
*/

/*
string findsuffix()
{
	string str1("Cplusplus.exe.rar");
	string str2("cpp");
	size_t i1 = str1.find(str2);        // 使用了函数1

	// 找到了 —— 返回下标为 i1 的后面字符串
	if (i1 != string::npos)
	{
		return str1.substr(i1);
	}
	else
	{
		// 未找到可以返回匿名对象 string()
		// 也可以返回空字符串""，之所以可以
		return string();
		//return "";
	}
}
*/

/*
string findsuffix()
{
	string str1("Cplusplus.exe.rar");
	string str2("exe");
	size_t i1 = str1.find(str2);        // 使用了函数1

	// 找到了 —— 返回下标为 i1 的后面字符串
	if (i1 != string::npos)
	{
		return str1.substr(i1);
	}
	else
	{
		// 未找到可以返回匿名对象 string()
		// 也可以返回空字符串""
		return string();
		//return "";
	}
}
*/

/*
string findsuffix()
{
	string str1("Cplusplus.exe.rar");
	size_t i1 = str1.find("exe");        // 使用了函数2

	// 找到了 —— 返回下标为 i1 的后面字符串
	if (i1 != string::npos)
	{
		return str1.substr(i1);
	}
	else
	{
		// 未找到可以返回匿名对象 string()
		// 也可以返回空字符串""
		return string();
		//return "";
	}
	
}
*/

/*
string findsuffix()
{
	string str1("Cplusplus.exe.rar");
	size_t i1 = str1.find('.');        // 使用了函数3

	// 找到了 —— 返回下标为 i1 的后面字符串
	if (i1 != string::npos)
	{
		return str1.substr(i1);
	}
	else
	{
		// 未找到可以返回匿名对象 string()
		// 也可以返回空字符串""
		return string();
		//return "";
	}
}
*/

/*
void func2()
{
	/*
	string str("Searches the string for the first character that matches");
	cout << str << endl << endl;

	size_t find = str.find_first_of("aeiou");
	//将在字符串中找到参数字符串里的的任意字符替换成'$'字符
	while (find != string::npos)
	{
		str[find] = '$';
		find = str.find_first_of("aeiou", find + 1);
	}
	cout << str << endl;
	*/
	
	/*
	string str("Searches the string for the first character that matches");
	cout << str << endl << endl;

	size_t find = str.find_first_not_of("aeiou");
	//将在字符串中找到不是参数字符串里的的任意字符替换成'$'字符
	while (find != string::npos)
	{
		str[find] = '$';
		find = str.find_first_not_of("aeiou", find + 1);
	}
	cout << str << endl;
	*/

	/*
	//求一串单词的最后一个单词的长度
	string str;
	getline(cin, str);
	size_t pos = str.rfind(' ');

	if (pos != string::npos)
	{
		cout << str.size() - 1 - pos << endl;
	}
	else
	{
		cout << str.size() << endl;
	}
}
*/

/*
int main()
{
	//cout << findsuffix() << endl;
	func2();

	return 0;
}
*/