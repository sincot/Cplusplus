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
//ȫ�ֱ���
using std::cout;

/*
int main()
{
	//int arr[] = { 4, 6, 3, 8, 5 };
	////����
	//std::list<int> lt;

	////����
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

	////�Զ�������
	//std::string str("��� C++");
	//std::cout << str << std::endl;

	return 0;
}
*/

//ȫȱʡ
void Func(int i = 10, int j = 20, int k = 30)
{
	std::cout << "i = " << i << ' ' << "j = " << j 
		      << ' ' << "k = " << k << std::endl;
}

int main()
{
	//������i,j,k��ʹ�õ���ȱʡֵ
	Func();

	//ֻ��һ��������iʹ�õ��Ǵ������Ĳ�����j,kʹ�õ���ȱʡֵ
	Func(1);

	//������������i,jʹ�õ��Ǵ������Ĳ�����kʹ�õ���ȱʡֵ
	Func(1, 2);

	//������������i,j,kʹ�õĶ��Ǵ������Ĳ���
	Func(1, 2, 3);


	////��������
	//Func(1, , 3);
	//Func(, 2, 3);

	return 0;
}