#define  _CRT_SECURE_NO_WARNINGS
#include "string.h"

using namespace std;

namespace AY
{
	void func1()
	{
		string str1("11111");
		string str2("11111111111");
		cout << sizeof(str1) << endl;
		cout << sizeof(str2) << endl;
	}
}

int main()
{
	AY::func1();

	return 0;
}