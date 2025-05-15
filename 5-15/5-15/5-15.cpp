#include <iostream>

using namespace std;

void func1()
{
	/*
	string str1("hello world");

	// ��ͨ������
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
	
	// const ������
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

	// const ������
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
	cout << "max_size��" << str1.max_size() << endl << endl;
	cout << "    size��" << str1.size() << endl << endl;
	cout << "capacity��" << str1.capacity() << endl << endl;
	*/

	/*
	string str;
	cout << "    size��" << str.size() << endl << endl;
	cout << "capacity��" << str.capacity() << endl << endl;
	//��ȡ��ǰ����capacity�Ĵ�С
	size_t old = str.capacity();

	//��str�в���100���ַ�
	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('*');

	    //�ж��Ƿ������� ���� ֻ��Ҫ�Ƚϵ�ǰ����capacity��old�Ĵ�С
		//������ȣ��ͱ��������ˣ�������ǰ��capacity��ӡ����
		if (str.capacity() != old)
		{
			cout << "capacity��" << str.capacity() << endl;
			old = str.capacity();
		}
	}
	*/

	/*
	string str;
	//��ȡ��ǰ����capacity�Ĵ�С
	size_t old = str.capacity();

	//��str�в���100���ַ�
	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('*');

		//�ж��Ƿ������� ���� ֻ��Ҫ�Ƚϵ�ǰ����capacity��old�Ĵ�С
		//������ȣ��ͱ��������ˣ�������ǰ��capacity��ӡ����
		if (str.capacity() != old)
		{
			old = str.capacity();
		}
	}
	cout << "    size��" << str.size() << endl << endl;
	cout << "capacity��" << str.capacity() << endl << endl;

	for (size_t i = 0; i < 50; i++)
	{
		str.pop_back(); // βɾ
	}
	//����
	str.shrink_to_fit();
	cout << "    size��" << str.size() << endl << endl;
	cout << "capacity��" << str.capacity() << endl << endl;
	*/

	/*
	string str;
	//��ȡ��ǰ����capacity�Ĵ�С
	size_t old = str.capacity();
	//��ǰ���ٺÿռ�
	str.reserve(100);

	//��str�в���100���ַ�
	for (size_t i = 0; i < 100; i++)
	{
		str.push_back('*');

		//�ж��Ƿ������� ���� ֻ��Ҫ�Ƚϵ�ǰ����capacity��old�Ĵ�С
		//������ȣ��ͱ��������ˣ�������ǰ��capacity��ӡ����
		if (str.capacity() != old)
		{
			cout << "capacity��" << str.capacity() << endl << endl;
			old = str.capacity();
		}
	}
	cout << "    size��" << str.size() << endl;
	cout << "capacity��" << str.capacity() << endl << endl;
	*/

	/*
	string str2("hello cplusplus");
	cout << "size��" << str2.size() << endl;
	cout << "capacity��" << str2.capacity() << endl << endl;
	str2.clear();
	cout << "size��" << str2.size() << endl;
	cout << "capacity��" << str2.capacity() << endl << endl;
	*/
}

void func4()
{
	/*
	string str3("hello C++");
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl << endl;
	str3.reserve(50);
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl << endl;
	*/

	/*
	// size < n < capacity
	string str3("hello C++");
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl << endl;
	str3.reserve(12);
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl << endl;
	*/

	/*
	// n < size
	string str3("hello C++");
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	str3.resize(5);
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	*/

	/*
	// n > size ��ȷ�����˲���c
	string str3("hello C++");
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	str3.resize(20, '*');
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	*/

	/*
	// n > size δ��ȷ�����˲���c
	string str3("hello C++");
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	str3.resize(20);
	cout << "    size��" << str3.size() << endl;
	cout << "capacity��" << str3.capacity() << endl;
	cout << str3 << endl << endl;
	*/

	/*
	string str4("02468");
	//����Խ������ˣ��������ᱨ��Ϊʲô
	//��Ϊ�����Խ����Ϊ�Ǻ���������
	//��鵽Խ����Ϊ�󣬺����е�assert���Ծͻ�ִ�У�ʹ�����ж�
	cout << str4[6] << endl;
	
	// Ҳ������at����������Ƿ����Խ����Ϊ
	// �� [ ] ��ͬ���ǣ�at��鵽Խ����Ϊ������쳣
	

	//����Խ������ˣ����������ᱨ��Ϊʲô
	//��Ϊ�����Խ����Ϊ�Ǳ�����������
	//���������������Խ����Ϊ��һ�ֳ����Ϊ
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
	str5.append("and space"); // ʹ���˺���3
	cout << str5 << endl << endl;

	string str6("hello world");
	cout << str6 << endl;
	str6.append(str6);        // ʹ���˺���1
	cout << str6 << endl << endl;

	string str7("hello world");
	cout << str7 << endl;
	str7.append(10, '$');    // ʹ���˺���5
	cout << str7 << endl << endl;
	*/
}


void func6()
{
	/*
	string str1("hello world");
	str1.push_back(' ');
	cout << str1 << endl;
	str1 += str1;           // ʹ���˺���1
	cout << str1 << endl << endl;

	string str2("hello world");
	str2.push_back(' ');
	cout << str2 << endl;
	str2 += "and space";   // ʹ���˺���2
	cout << str2 << endl << endl;

	string str3("hello world");
	str3.push_back(' ');
	cout << str3 << endl;
	str3 += '*';           // ʹ���˺���3
	cout << str3 << endl << endl;
	*/
}

void func7()
{
	/*
	string str1("hello world");
	cout << str1 << endl;
	str1.insert(6, str1);                  // ʹ���˺���1
	cout << str1 << endl << endl;

	string str2("hello world");
	str2.insert(6, "space and ");          // ʹ���˺���2
	cout << str2 << endl << endl;

	string str3("hello world");
	str3.insert(6, 10, '*');               // ʹ���˺���3
	cout << str3 << endl << endl;          

	string str4("hello world");
	str4.insert(str4.begin(), 10, '*');    // ʹ���˺���3       
	cout << str4 << endl << endl;
	*/
}

void func8()
{
	/*
	string str1("hello world");
	cout << str1 << endl;
	str1.erase(5, 1);            // ���±�Ϊ5��λ�ÿ�ʼɾ��1���ַ�
	cout << str1 << endl << endl;

	string str2("hello world");
	str2.erase(5);               // ���±�Ϊ5��λ�ÿ�ʼɾ��npos���ַ�
	cout << str2 << endl << endl;

	string str3("hello world");
	str3.erase(5, 20);           // ���±�Ϊ5��λ�ÿ�ʼɾ��20���ַ�
	cout << str3 << endl << endl;
	*/

	/*
	string str1("hello  world");
	cout << str1 << endl;
	str1.replace(5, 1, str1);              // ʹ���˺���1
	cout << str1 << endl << endl;

	string str2("hello  world");
	str2.replace(5, 1, " space and ");    // ʹ���˺���2
	cout << str2 << endl << endl;

	string str3("hello  world");
	str3.replace(5, 1, 1, '*');           // ʹ���˺���3
	cout << str3 << endl << endl;

	string str4("hello world");
	str4.replace(5, 1, 10, '*');          // ʹ���˺���3
	cout << str4 << endl << endl;
	*/

	/*
	//����1��ʹ�� replace ����
	string str("   water graphically @ g mail com   ");
	cout << str << endl;
	//ʹ��find���� ���� Ѱ�ҿ��ַ���
	size_t pos = str.find(' ');

	//nposΪstring���еĳ�Ա����
	while (pos != string::npos)
	{
		str.replace(pos, 1, "%%");

		// ����ȥ�� ���� �� find �� pos + 2 λ���������
		pos = str.find(' ', pos + 2);
	}
	cout << str << endl;
	*/


	//����2��ʹ�� operator+= ����
	string str("   water graphically @ g mail com   ");
	cout << str << endl << endl;

	// ����һ���µ��ַ���
	string s;

	//�÷�Χ for �����ַ���
	for (auto ch : str)
	{
		// �����������ַ�Ϊ ' ' �ַ�����ô���ַ����� += "%%"
		if (ch == ' ')
		{
			s += "%%";
		}
        // �����������ַ���Ϊ ' ' �ַ�����ô���ַ����� += ch
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