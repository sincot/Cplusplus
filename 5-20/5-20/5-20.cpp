#include "string.h"

using namespace std;

namespace AY
{
	void func1()
	{	
		string str1("hello world");
		cout << str1.c_str() << endl;

		// ²âÊÔ insert ¡ª¡ª²åÈë×Ö·ûº¯Êý
		/*
		str1.insert(6, '$');
		cout << str1 << endl;
		*/
		/*
		str1.insert(0, '$');
		cout << str1 << endl;
		*/

		// ²âÊÔ insert ¡ª¡ª ²åÈë×Ö·û´®º¯Êý
		/*
		str1.insert(6, "$$$");
		cout << str1 << endl;
		*/
		/*
		str1.insert(0, "$$$");
		cout << str1 << endl;
		*/

		// ²âÊÔ erase º¯Êý
		/*
		str1.erase(7, 30);
		cout << str1 << endl;
		*/
		/*
		str1.erase(7, 3);
		cout << str1 << endl;
		*/

		// ²âÊÔ pop_back º¯Êý
		/*
		str1.pop_back();
		str1.pop_back();
		cout << str1 << endl;
		*/
		/*
		string str2 = "";
		str2.pop_back();
		*/
	}

	void func2()
	{
		//string str2("hello cplusplus");
		// ²âÊÔ find º¯Êý
		/*
		cout << str2.find(' ') << endl;
		cout << str2.find("ello") << endl;
		*/

		// ²âÊÔ substr º¯Êý
		/*
		size_t it1 = str2.find(' ');
		if (it1 != string::npos)
		{
			cout << str2.substr(0, it1) << endl;
		}

		cout << str2.substr(it1 + 1) << endl;
		*/
	}

	void func3()
	{
		string str2("hello cplusplus");
		string str3("hello cplusplusx");
		string str4("hello cplusplus");
		string str5("hello cplusplu");

        /*
		// ²âÊÔ < º¯Êý
		cout << (str2 < str3) << endl << endl;
		cout << (str2 < str4) << endl << endl;
		cout << (str2 < str5) << endl << endl;
		*/
		
		/*
		// ²âÊÔ <= º¯Êý
		cout << (str2 <= str3) << endl << endl;
		cout << (str2 <= str4) << endl << endl;
		cout << (str2 <= str5) << endl << endl;
		*/
	}
}

int main()
{
	//AY::func1();
	//AY::func2();
	AY::func3();

	return 0;
}
