#include "string.h"

using namespace std;

namespace AY
{
	void func1()
	{
		/*string str1;
		cout << str1.c_str() << endl;*/
		string str2("hello world");
		cout << str2.c_str() << endl;

		/*
		// ���� push_back ����
		str2.push_back('$');
		cout << str2.c_str() << endl << endl;
		*/

		/*
		// ���� append ����
		str2.append(" and space");
		cout << str2.c_str() << endl << endl;
		*/

		/*
		// ���� += �ַ�����
		str2 += '$';
		cout << str2.c_str() << endl << endl;
		*/

		/*
		// ���� += �ַ�������
		str2 += " and space";
		cout << str2.c_str() << endl << endl;
		*/

		/*
		// ���� << ����
		cout << str2 << endl << endl;
		*/

		/*
		str2 += '\0';
		str2 += '\0';
		str2 += '$';
		cout << str2;
		*/

		/*
		// ��Χ for
		for (auto ch : str1)
		{
			cout << ch << " ";
		}
		cout << endl << endl;

		// ��ͨ������
		string::iterator it1 = str1.begin();
		while (it1 != str1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		cout << endl << endl;

		// const ������
		string::const_iterator it2 = str2.begin();
		while (it2 != str2.end())
		{
			cout << *it2 << " ";
			it2++;
		}
		cout << endl << endl;
		*/
	}
}

int main()
{
	AY::func1();

	return 0;
}
