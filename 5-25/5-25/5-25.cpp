#include "vector.h"

void func1()
{
	AY::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (auto e : v)
	{
		cout << e << " ";
	}
}

int main()
{
	func1();
	return 0;
}

	
