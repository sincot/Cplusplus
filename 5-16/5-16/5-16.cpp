#include <iostream>
#include <string>

using namespace std;

/*
void func1()
{
	/*
	string str1("hello world");
	// ��ȡ�ո��Ժ�Ĳ���
	// �ո��ַ����±�Ϊ6���ո������ַ�������Ϊ5
	// ������size()���� - Ҫ��ĳ�ַ�����ĳ��ȵ��±�
	string str2 = str1.substr(6, str1.size() - 6);
	cout << str1 << endl << endl;
	cout << str2 << endl;
	*/

	/*
	string str1("hello world");
	//��ȡ�ո��ַ��Ժ�Ĳ���
	//Ҳ�������Ϊֱ���ַ�������
	//��ôsubstr�ĵڶ����������Բ���ʵ�Σ���ȱʡֵnpos
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
	size_t i1 = str1.find(str2);        // ʹ���˺���1

	// �ҵ��� ���� �����±�Ϊ i1 �ĺ����ַ���
	if (i1 != string::npos)
	{
		return str1.substr(i1);
	}
	else
	{
		// δ�ҵ����Է����������� string()
		// Ҳ���Է��ؿ��ַ���""��֮���Կ���
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
	size_t i1 = str1.find(str2);        // ʹ���˺���1

	// �ҵ��� ���� �����±�Ϊ i1 �ĺ����ַ���
	if (i1 != string::npos)
	{
		return str1.substr(i1);
	}
	else
	{
		// δ�ҵ����Է����������� string()
		// Ҳ���Է��ؿ��ַ���""
		return string();
		//return "";
	}
}
*/

/*
string findsuffix()
{
	string str1("Cplusplus.exe.rar");
	size_t i1 = str1.find("exe");        // ʹ���˺���2

	// �ҵ��� ���� �����±�Ϊ i1 �ĺ����ַ���
	if (i1 != string::npos)
	{
		return str1.substr(i1);
	}
	else
	{
		// δ�ҵ����Է����������� string()
		// Ҳ���Է��ؿ��ַ���""
		return string();
		//return "";
	}
	
}
*/

/*
string findsuffix()
{
	string str1("Cplusplus.exe.rar");
	size_t i1 = str1.find('.');        // ʹ���˺���3

	// �ҵ��� ���� �����±�Ϊ i1 �ĺ����ַ���
	if (i1 != string::npos)
	{
		return str1.substr(i1);
	}
	else
	{
		// δ�ҵ����Է����������� string()
		// Ҳ���Է��ؿ��ַ���""
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
	//�����ַ������ҵ������ַ�����ĵ������ַ��滻��'$'�ַ�
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
	//�����ַ������ҵ����ǲ����ַ�����ĵ������ַ��滻��'$'�ַ�
	while (find != string::npos)
	{
		str[find] = '$';
		find = str.find_first_not_of("aeiou", find + 1);
	}
	cout << str << endl;
	*/

	/*
	//��һ�����ʵ����һ�����ʵĳ���
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