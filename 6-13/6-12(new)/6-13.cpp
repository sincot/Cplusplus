#include "string.h"

using namespace std;

namespace AY
{
	void func1()
	{
		/*string str1("hello world");
		string::iterator i1 = str1.begin();
		while (i1 != str1.end())
		{
			(*i1)++;
			cout << (*i1) << " ";
			i1++;
		}
		cout << endl;*/


		/*string str2("hello C++");
		for (char e : str2)
		{
			e++;
			cout << e << " ";
		}
		cout << endl;*/

		/*string str1("hello world");
		string::const_iterator i1 = str1.begin();
		while (i1 != str1.end())
		{
			(*i1)++;
			cout << (*i1) << " ";
			i1++;
		}
		cout << endl;

		string str2("hello C++");
		for (const auto& e : str2)
		{
			e++;
			cout << e << " ";
		}
		cout << endl;*/

		/*cout << str.c_str() << endl;
		cout << str.size() << endl;*/

		/*string str("hello Cplusplus");
		cout << "size = " << str.size() << endl;
		cout << "capacity = " << str.capacity() << endl;
		str.reserve(100);
		cout << "size = " << str.size() << endl;
		cout << "capacity = " << str.capacity() << endl;*/

		/*string str1("hello Cplusplus");
		cout << str1.c_str() << endl;
		str1.push_back('\0');
		str1.push_back('\0');
		str1.push_back('*');
		cout << str1 << endl;*/

		/*std::string str1("hello Cplusplus");
		cout << str1.c_str() << endl;
		str1.push_back('\0');
		str1.push_back('\0');
		str1.push_back('*');
		cout << str1 << endl;*/

		/*string str1("hello Cplusplus");
		cout << str1.c_str() << endl;
		str1.push_back('\0');
		str1.push_back('\0');
		str1.push_back('*');
		cout << str1 << endl;*/

		/*string str1("13579");
		cout << str1 << endl;
		str1.insert(2, '*');
		cout << str1 << endl;
		cout << endl;

		string str2("13579");
		cout << str2 << endl;
		str2.insert(0, '*');
		cout << str2 << endl;*/

		/*string str("hello Cplusplus");
		cout << str << endl;
		str.push_back('\0');
		str.push_back('\0');
		str.push_back('!');
		cout << str << endl;
		str += "yyyyyy";
		cout << str << endl;*/

		/*string str1("hello world");
		cout << str1 << endl;
		str1.insert(6, "space and ");
		cout << str1 << endl;
		cout << endl;

		string str2("hello Cplusplus");
		cout << str2 << endl;
		str2.insert(0, "***");
		cout << str2 << endl;*/

		/*string str1("hello world");
		cout << "删除前：> " << str1 << endl;
		str1.erase(0);
		cout << "删除后：> " << str1 << endl;
		cout << endl;

		string str2("hello Cplusplus");
		cout << "删除前：> " << str2 << endl;
		str2.erase(2, 5);
		cout << "删除后：> " << str2 << endl;*/
	}

	void func2()
	{
		/*string str("hello world");
		cout << str << endl;
		str.pop_back();
		cout << str << endl;*/

		/*string str("watergraphically");
		cout << str.find('f', 5) << endl;
		cout << str.find('c', 5) << endl;*/

		/*string str("watergraphically");
		cout << str.find("ra", 5) << endl;
		cout << str.find("la", 5) << endl;*/

		/*string str("watergraphically");
		string ret1 = str.substr(2, 5);
		cout << ret1 << endl;
		string ret2 = str.substr(8);
		cout << ret2 << endl;*/

		/*string str1("hello");
		string str2("hell");
		string str3("hello");
		string str4("hello");
		string str5("hello");
		string str6("hellox");
		cout << (str1 == str2) << endl;
		cout << (str3 == str4) << endl;
		cout << (str5 == str6) << endl;*/

		/*string str("hello");
		cout << "size = " << str.size() << endl;
		str.clear();
		cout << "size = " << str.size() << endl;*/

		/*string str1;
		cin >> str1;
		cout << str1 << endl;
		cout << endl;

		string str2("hello ");
		cin >> str2;
		cout << str2 << endl;*/


		/*std::string str1;
		cin >> str1;
		cout << str1 << endl;
		cout << endl;

		std::string str2("hello ");
		cin >> str2;
		cout << str2 << endl;*/

		/*string str("hello world");
		cout << str << endl;
		getline(cin, str);
		cout << str << endl;*/
		
		/*string str1("shell and linux");
		cout << "交换前 str1 的 size = " << str1.size() << endl;
		cout << str1 << endl;
		cout << endl;
		string str2("hello world");
		cout << "交换前 str2 的 size = " << str2.size() << endl;
		cout << str2 << endl;
		cout << endl;
		str1.swap(str2);
		cout << "交换后 str1 的 size = " << str1.size() << endl;
		cout << str1 << endl;
		cout << endl;
		cout << "交换后 str2 的 size = " << str2.size() << endl;
		cout << str2 << endl;
		cout << endl;*/

		string str1("hello world");
		string str2("hello linux");
		str2 = str1;
		cout << str2 << endl;
	}
}

int main()
{
	//AY::func1();
	AY::func2();

	return 0;
}