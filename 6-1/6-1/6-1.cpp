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
	//// ʹ�� rbegin �� rend
	//string::const_reverse_iterator it1 = str.rbegin();
	//while (it1 != str.rend())
	//{
	//	cout << *it1 << " ";
	//	it1++;
	//}
	//cout << endl;

	//// ʹ�� rbegin �� rend
	//string::const_reverse_iterator it2 = str.crbegin();
	//while (it2 != str.crend())
	//{
	//	cout << *it2 << " ";
	//	it2++;
	//}
	//cout << endl;

	/*string str1("hello world");
	cout << "����ǰ�� ";
	for (size_t i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;

	str1.push_back('$');
	cout << "����� ";
	for (size_t i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;


	string str2("hello cplusplus");
	cout << "ɾ��ǰ�� ";
	for (size_t i = 0; i < str2.size(); i++)
	{
		cout << str2[i] << " ";
	}
	cout << endl;

	str2.pop_back();
	cout << "ɾ���� ";
	for (size_t i = 0; i < str2.size(); i++)
	{
		cout << str2[i] << " ";
	}
	cout << endl;*/
	
	//string str("gon");
	//cout << "old caapcity: " << str.capacity() << endl;
	//size_t old = str.capacity();
	//
	//// ���ϵ��� str �в���100������
	//for (size_t i = 0; i < 100; i++)
	//{
	//	str.push_back('*');
	//	// �ж��Ƿ���Ҫ����
	//	// �� old �Ĵ�С�뵱ǰ�ַ�����capacity�Ĵ�С����ʱ
	//	// �ͻᴥ�����ݻ���
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

	//// ���� clear ����
	//str.clear();
	//cout << "size: " << str.size() << endl;
	//cout << "capacity: " << str.capacity() << endl;
	
    // ����ʧ��
	//string str;
	//size_t old = str.capacity();
	//cout << "******����ʧ��******" << endl;
	//// ���ϵ��� str �в���100������
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

	//// ���ݳɹ�
	//cout << "******���ݳɹ�******" << endl;
	////βɾ 50 ���ַ�
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
	// ����
	str.reserve(100);
	cout << "size = " << str.size() << endl;
	cout << "capacity = " << str.capacity() << endl;
	*/

	/*
	// ����
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
	// append ����
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

	// operator += ����
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
    // ����������ʹ��ȱʡֵ
	str1.erase();
	cout << str1 << endl << endl;

	string str2("hello world");
	cout << str2 << endl;
	// len ʹ��ȱʡֵ
	str2.erase(5);
	cout << str2 << endl << endl;

	string str3("hello world");
	cout << str3 << endl;
	// ������
	str3.erase(5, 1);
	cout << str3 << endl << endl;
	*/

	/*
	// replace ����
	string str("hello world");
	cout << str << endl;
	str.replace(5, 2, "%&*");
	cout << str << endl;
	*/

	// ���ַ����еĿո��滻��"%%"
	/*
	//����1�� ʹ�� replace ����
	string str("water geogra phically @ g . mail");
	cout << str << endl;
	// Ѱ�ҿո��ַ���λ��
	size_t pos = str.find(' ');
	// �����ַ���
	while (pos != string::npos)
	{
		str.replace(pos, 1, "%%");
		// �ӵ�ǰposλ�� +2 �ĵط���ʼ�����ҿո��ַ���λ��
		pos = str.find(' ', pos + 2);
	}
	cout << str << endl;
	*/

	/*
	// ����2�� ʹ�� += ����
	string str("water geogra phically @ g . mail");
	cout << str << endl;
	// �ٴ���һ��string���͵Ķ����������滻����ַ���
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

	// substr ����
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
	// reserve ����
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

	// resize ����
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
	//str.append(str);          // ԭ��1
	//cout << str << endl;
	//str.append("and space");  // ԭ��2
	//cout << str << endl;    
	//str.append(10, '@');      // ԭ��3
	//cout << str << endl;

	/*
	string str("hello world ");
	cout << str << endl;
	str += str;            // ԭ��1
	cout << str << endl;
	str += " and space";   // ԭ��2
	cout << str << endl;
	str += '@';            // ԭ��3
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
	cout << "ɾ��ǰ�� " << str1 << endl;
	str1.erase();
	cout << "ɾ���� " << str1 << endl;
	cout << endl;
	
	string str2("cplusplus");
	cout << "ɾ��ǰ�� " << str2 << endl;
	str2.erase(4);
	cout << "ɾ���� " << str2 << endl;
	cout << endl;

	string str3("watergraphiclaly");
	cout << "ɾ��ǰ�� " << str3 << endl;
	str3.erase(4, 5);
	cout << "ɾ���� " << str3 << endl;
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

	// ��ȡ�ո�֮�󲿷ֵ��ַ���
	/*string str("hello world");
	cout << str << endl;
	cout << "size = " << str.size() << endl;
	cout << endl;
	string ret = str.substr(6, str.size() - 6);
	cout << ret << endl;
	cout << "size = " << ret.size() << endl;*/

	// ���ַ����еĿո��ַ��滻��"%%"
	string str("water geographically @ g . mail");
	cout << str << endl;
	// Ĭ�ϴ��±�Ϊ 0 ��λ�ÿ�ʼ��
	size_t pos = str.find(' ');
	while (pos != string::npos)
	{
		str.replace(pos, 1, "%%");
		// ���������ң�����Ҫ�ٴ��±�Ϊ 0 ��λ�ÿ�ʼ����
		// ���±�Ϊ pos + 2 ��λ�ÿ�ʼ��
		pos = str.find(' ', pos + 2);
	}

	cout << str << endl;
}

void test5()
{
	// ��һ���ַ����������һ�����ʵĳ���
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

	cout << "���� a ����������Ϊ�� " << typeid(a).name() << endl;
	cout << "���� b ����������Ϊ�� " << typeid(b).name() << endl;
	cout << "���� c ����������Ϊ�� " << typeid(c).name() << endl;
	cout << "���� d ����������Ϊ�� " << typeid(d).name() << endl;
	*/

	/*auto x = 10;
	auto y = 3.14;
	auto px = &x;
	auto* py = &y;

	cout << "���� px ����������Ϊ�� " << typeid(px).name() << endl;
	cout << "���� py ����������Ϊ�� " << typeid(py).name() << endl;*/

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