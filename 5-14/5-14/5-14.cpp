#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1("hello world");  // 直接给字符串
	const string str2("hello Cpp");
	string str3("13579");
	const string str4("24680");

	/*
	//迭代器
	// 用迭代器定义一个对象 it1，指向字符串的首字符   
	string::iterator it1 = str1.begin();
	while (it1 != str1.end())
	{
		(*it1)++;
		cout << *it1 << "\t";
		it1++;
	}
	cout << endl;
	cout << str1 << endl;

	// const 迭代器 —— 指向的内容不能修改，即*it2不能修改
	string::const_iterator it2 = str2.cbegin();
	while (it2 != str2.cend())
	{
		cout << *it2 << "\t";
		it2++;
	}
	cout << endl;
	cout << str2 << endl;

	//反向迭代器 —— 倒着遍历
	string::reverse_iterator it3 = str3.rbegin();
	while (it3 != str3.rend())
	{
		(*it3)++;
		cout << *it3 << "\t";
		it3++;
	}
	cout << endl;
	cout << str3 << endl;

	//const 反向迭代器
	string::const_reverse_iterator it4 = str4.crbegin();
	while (it4 != str4.crend())
	{
		cout << *it4 << "\t";
		it4++;
	}
	cout << endl;
	cout << str4 << endl;
	*/

	/*
	// 范围for
	// 如果是普通的迭代器就转换为普通版本
	// 如果是const的迭代器就转换为const版本
	for (auto ch : str1)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

	for (auto ch : str2)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

	for (auto ch : str3)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

	for (auto ch : str4)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;
	*/

	/*
	//无意义接口 —— max_size
	// 不同的编译器下器结果不一样
	cout << str1.max_size() << endl;
	cout << str2.max_size() << endl;
	cout << str3.max_size() << endl;
	cout << str4.max_size() << endl;
	*/

	// 对比字符串的size，capacity
	// size 和 capacity 求出的大小均不包含尾字符 \0 
	/*
	cout << str1.size() << endl;
	cout << str1.capacity() << endl;
	cout << endl;

	cout << str2.size() << endl;
	cout << str2.capacity() << endl;
	cout << endl;

	cout << str3.size() << endl;
	cout << str3.capacity() << endl;
	cout << endl;

	cout << str4.size() << endl;
	cout << str4.capacity() << endl;
	cout << endl;
	*/
    
	// 扩容的方式C++ 并没有定标准，不同的编译器标准不一样
    // 观察在Vs编译器下，扩容标准
	string str;
	size_t old = str.capacity(); // 保存扩容前的capacity值
	cout << "capacity" << old << endl;

	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('c');  // 尾插


		if (str.capacity() != old)
		{
			old = str.capacity();
			cout << "capacity：" << old << endl;
		}
	}
	cout << endl;
	//由结果可知，除了第一次扩容，后续的扩容都是1.5倍扩容

	/*
	//clear —— 只是将字符串的size置为0（将字符串的数据清空）
	cout << "size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl;
	str.clear();
	cout << "size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl;
	*/

	/*
    // shrink_to_fit —— 缩容
	//缩 str
	cout << "size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl;
	str.shrink_to_fit();
	cout << "size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl;
	cout << endl;

	// 缩 str3
	cout << "size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	str3.shrink_to_fit();
	cout << "size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	*/

	/*
	// reserve 接口 
	// 提前知道自己需要多大的空间，将空间开好，避免扩容，提高了效率
	//增容
	cout << "size：" << str1.size() << endl;
	cout << "capacity：" << str1.capacity() << endl;
	str1.reserve(50);
	cout << "size：" << str1.size() << endl;
	cout << "capacity：" << str1.capacity() << endl;
	cout << endl;

	//缩容 —— 缩容失败，用reserve缩容不靠谱，用shrink_to_fit缩容
	cout << "size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	str3.reserve(4);
	cout << "size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << endl;
	*/

	/*
	// resize 接口
	cout << str3 << endl;
	cout << "size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << endl;

	// n > capacity > size —— 插入数据，让size增加到 n 个
	str3.resize(17, '*');
	cout << str3 << endl;
	cout << "size：" << str3.size() << endl;
	cout << "capacity：" << str3.capacity() << endl;
	cout << endl;
	
	// ***************************************************
	cout << str1 << endl;
	cout << "size：" << str1.size() << endl;
	cout << "capacity：" << str1.capacity() << endl;
	cout << endl;

	// capacity > n > size —— 插入数据，让size增加到 n 个
	str1.resize(11, '*');
	cout << str1 << endl;
	cout << "size：" << str1.size() << endl;
	cout << "capacity：" << str1.capacity() << endl;
	cout << endl;
	
	// ***************************************************
	cout << str << endl;
	cout << "size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl;
	cout << endl;

	// n < size —— 删除数据，将 size 减少至 n 
	str.resize(10);
	cout << str << endl;
	cout << "size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl;
	cout << endl;

	// ***************************************************
	cout << str << endl;
	cout << "size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl;
	cout << endl;

	// 未传参，默认插入的是 '\0'
	str.resize(20);
	cout << str << endl;
	cout << "size：" << str.size() << endl;
	cout << "capacity：" << str.capacity() << endl;
	cout << endl;
	*/
    
    /*
	// operator[]
	str1[0]++;
	cout << str1[0] << endl;

	//下面的越界了，编译器会报错，为什么？
	//因为这里是用函数检查的
	//这里的str1[14]实际上转化为str1.operator[](14)
	str1[14]++;
	cout << str1[14] << endl;

	//下面的数组越界了，但是编译器未报错，为什么？
	//因为这里的检查是用编译器来检查的
	//而编译器对于数组的下标越界是一种抽查行为
	int arr[10];
	arr[14] = 1;
	*/
    
    /*
    // append —— 追加
	str1.push_back(' '); // 尾插
	str1.append("and earth"); // 往后追加括号中的字符串
	cout << str1 << endl << endl;
	str1.append(30, '*');
	cout << str1 << endl << endl;
	*/
    
    /*
    // operator += 
	cout << str1 << endl << endl;
	str1 += " and earth";
	cout << str1 << endl << endl;
	str1 += ' ';
	str1 += str2;
	cout << str1 << endl << endl;
	*/
    
    /*
    // insert 接口
    // insert 需要谨慎使用，因为底层涉及数据的挪动，效率低下
	cout << str1 << endl << endl;
    str1.insert(0, "new ");
	cout << str1 << endl << endl;
	str1.insert(0, 1, ' ');
	str1.insert(0, 8, '*');
	cout << str1 << endl << endl;
	str1.insert(str1.begin(), '*');
	cout << str1 << endl << endl;
	*/
    
    /*
    // erase 接口 —— 删除字符数据
	cout << str1 << endl << endl;
    str1.erase(5, 1); //将下标为5的字符删除
	cout << str1 << endl << endl;
	str1.erase(5);   // 将下标为5的字符及以后的字符都删除
	cout << str1 << endl << endl;
	*/
    
    // replace 接口
    // replace 需要谨慎使用，因为底层涉及数据的挪动，效率低下
    /*
    string str5("hello   world");
	cout << str5 << endl << endl;
	str5.replace(5, 3, "$");
	cout << str5 << endl << endl;
	*/

	string str5("water graphically @ g .mail .com");
	cout << str5 << endl << endl;
	//将字符串str5中的空格全部替换成%%
	//找到字符串str5中的空格
	
	/*
	// 以下的方法效率有点低
	size_t pos = str5.find(' ');

	// npos 为 string 类中的成员变量
	while (pos != string::npos)
	{
		str5.replace(pos, 1, "%%");

		// pos + 2 就不必每次都要从头开始找
		pos = str5.find(' ', pos + 2);
	}
	cout << str5 << endl << endl;
	*/

	// 改进方案
	string str6;
	for (auto ch : str5)
	{
		if (ch == ' ')
		{
			str6 += "%%";
		}
		else
		{
			str6 += ch;
		}
	}

	cout << str6 << endl << endl;

	return 0;
}