#include "Func.h"
#include <iostream>
using namespace std;

template<class T>
void FuncT(const T& val)
{
	cout << "FuncT(const T& val)" << endl;
}

// ��ʾʵ����
template
void FuncT(const int& val);