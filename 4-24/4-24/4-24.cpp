/*
using namespace std;

int main()
{
	cout << "hello world" << endl;
	return 0;
}
*/

/*
#include <iostream>

using std::cout;

int main()
{
	cout << "hello world" << std::endl;
	return 0;
}
*/


#include <iostream>
#include <list>
#include <algorithm>
//全局变量
using std::cout;

/*
int main()
{
	//int arr[] = { 4, 6, 3, 8, 5 };
	////函数
	//std::list<int> lt;

	////类型
	//std::sort(arr, arr + 5);

	int i = 0;
	double d = 0.0;
	std::cin >> i >> d;
    std::cout << i << std::endl;
	std::cout << d << std::endl;

	int i = 0;
	double d = 0.0;
	std::cin >> i >> d;
	std::cout << i << ' ' << d << std::endl;
	std::cout << i << ' ' << d << '\n';

	////自定义类型
	//std::string str("你好 C++");
	//std::cout << str << std::endl;

	return 0;
}
*/

//全缺省
void Func(int i = 10, int j = 20, int k = 30)
{
	std::cout << "i = " << i << ' ' << "j = " << j 
		      << ' ' << "k = " << k << std::endl;
}

int main()
{
	//不传参i,j,k都使用的是缺省值
	Func();

	//只传一个参数，i使用的是传过来的参数，j,k使用的是缺省值
	Func(1);

	//传两个参数，i,j使用的是传过来的参数，k使用的是缺省值
	Func(1, 2);

	//传三个参数，i,j,k使用的都是传过来的参数
	Func(1, 2, 3);


	////不能这样
	//Func(1, , 3);
	//Func(, 2, 3);

	return 0;
}