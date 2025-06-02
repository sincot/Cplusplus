#define  _CRT_SECURE_NO_WARNINGS
#include "string.h"

using namespace std;

namespace AY
{
	void func1()
	{
		string str1("hello world");
		string str2(" and space");
		str2 = str1;
		cout << str2 << endl;

		/*string str1("13579");
		string str2("24680");
		getline(cin, str1);
		cout << str1;*/

		/*string str1("hello");
		string str2("hell");
		string str3("hellox");
		cout << (str1 < str2) << endl;
		cout << (str2 < str1) << endl;
		cout << (str1 < str3) << endl;
		cout << (str3 < str1) << endl;
		cout << (str2 < str3) << endl;
		cout << (str3 < str2) << endl;*/

		/*string str("watergraphically");
		string ret = str.substr(5);
		cout << ret << endl;*/

		/*string str("hello world");
		size_t find = str.find('f');
		cout << find << endl;*/

		/*string str("hello world");
		str.pop_back();
		cout << str << endl;*/

		/*cout << str << endl;
		str.erase(1);
		cout << str << endl;*/
		/*string str("hello world");
		str.insert(6, "%%%");
		cout << str << endl;*/

		/*str.insert(0, '$');
		cout << str << endl;*/

		/*string str1("hello world");
		str1 += '\0';
		str1 += '\0';
		str1 += '!';
		str1 += "xxxxxxxxx";
		cout << str1.c_str() << endl;
		cout << str1 << endl;*/

		/*string str1("hello world");
		str1.push_back('\0');
		str1.push_back('\0');
		str1.push_back('&');
		cout << str1 << endl;*/

		
		/*std::string str1("hello world");
		str1 += '\0';
		str1 += '\0';
		str1 += '!';
		str1 += "yyyyyyyyy";
		cout << str1.c_str() << endl;
		cout << str1 << endl;*/
		

		/*str1.push_back('x');
		str1.append(" and space");
		str1 += "&";
		str1 += " newcow";
		cout << str1.c_str() << endl;
		cout << "size = " << str1.size() << endl;*/

		/*
		const string str2("hello cplusplus");
		string::const_iterator it2 = str2.begin();
		while (it2 != str2.end())
		{
			(*it2)++;
			cout << *it2 << " ";
		}
		*/

		/*
		// ·¶Î§ for
		for (auto& e : str1)
		{
			e++;
			cout << e << " ";
		}
		*/
		/*
		string::iterator it1 = str1.begin();
		while (it1 != str1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		*/

		/*
		for (size_t i = 0; i < str1.size(); i++)
		{
			str1[i]++;
		}
		cout << str1.c_str() << endl;
		*/
	}
}

int main()
{
	AY::func1();

	return 0;
}