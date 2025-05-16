#include "string.h"

using namespace std;

namespace AY
{
	void func1()
	{
		string str1;
		cout << str1.c_str() << endl;
		string str2("hello world");
		cout << str2.c_str() << endl;

		// ·¶Î§ for
		for (auto ch : str1)
		{
			cout << ch << " ";
		}
		cout << endl << endl;

		// µü´úÆ÷
		string::iterator it1 = str1.begin();
		while (it1 != str1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		cout << endl << endl;
	}
}

int main()
{
	AY::func1();

	return 0;
}



