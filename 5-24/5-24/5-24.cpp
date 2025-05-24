/*
#include "vector.h"

using namespace std;

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
*/

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Test
{
	char ch;
	int i;
	double d;
	char arr[20];
}Test;


int cmp_by_char(const void* e1, const void* e2)
{
	return  ((Test*)e1)->ch - ((Test*)e2)->ch;
}

int cmp_by_int(const void* e1, const void* e2)
{
	return  ((Test*)e1)->i - ((Test*)e2)->i;
}

int cmp_by_double(const void* e1, const void* e2)
{
	double ret =  ((Test*)e1)->d - ((Test*)e2)->d;
	return ret < 0 ? -1 : 1;
}

int cmp_by_string(const void* e1, const void* e2)
{
	return strcmp(((Test*)e1)->arr, ((Test*)e2)->arr);
}

int main()
{
	Test test[] = { {'c', 20, 3.14, "lihua"}, {'h', 28, 6.98, "zhangye"},
				   {'g', 27, 5.18, "huangyan"} };
	int size = sizeof(test) / sizeof(test[0]);
	
	printf("排序前：");

	// 排序字符串类型
	for (int i = 0; i < size; i++)
	{
		printf("%s ", test[i].arr);
	}
	printf("\n");

	// 排序 double 类型
	/*
	for (int i = 0; i < size; i++)
	{
		printf("%.2f ", test[i].d);
	}
	printf("\n");
	*/
	// 排序 char 类型
	/*
	for (int i = 0; i < size; i++)
	{
		printf("%c ", test[i].ch);
	}
	printf("\n");
	*/
	
	// 排序 int 类型
	/*
	for (int i = 0; i < size; i++)
	{
		printf("%d ", test[i].i);
	}
	printf("\n");
	*/
/*
	//qsort(test, size, sizeof(test[0]), cmp_by_char);    // 排序 char 类型
	//qsort(test, size, sizeof(test[0]), cmp_by_int);     // 排序 int 类型
	//qsort(test, size, sizeof(test[0]), cmp_by_double);  // 排序 double 类型
	qsort(test, size, sizeof(test[0]), cmp_by_string); 

	printf("排序后：");
	// 排序字符串类型
	for (int i = 0; i < size; i++)
	{
		printf("%s ", test[i].arr);
	}
	printf("\n");
	// 排序 double 类型
	/*
	for (int i = 0; i < size; i++)
	{
		printf("%.2f ", test[i].d);
	}
	printf("\n");
	*/
	// 排序 int 类型
	/*
	for (int i = 0; i < size; i++)
	{
		printf("%d ", test[i].i);
	}
	printf("\n");
	*/

	// 排序 char 类型
	/*
	for (int i = 0; i < size; i++)
	{
		printf("%c ", test[i].ch);
	}
	printf("\n");
	
	return 0;
}
*/

#include <stdio.h>
#include <string.h>

/*
struct Test
{
	char ch;
	int i;
	double d;
	char name[20];
};
*/

/*
int compare(const void* e1, const void* e2)
{
	return ((Test*)e1)->ch - ((Test*)e2)->ch;
}
*/

/*
int compare(const void* e1, const void* e2)
{
	return ((Test*)e1)->i - ((Test*)e2)->i;
}
*/

/*
int compare(const void* e1, const void* e2)
{
	double ret = ((Test*)e1)->d - ((Test*)e2)->d;
	return ret > 0 ? 1 : -1;
}
*/

/*
int compare(const void* e1, const void* e2)
{
	return strcmp(((Test*)e1)->name, ((Test*)e2)->name);
}

void Swap(char* base1, char* base2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *base1;
		*base1 = *base2;
		*base2 = tmp;
		base1++;
		base2++;
	}
}

void BubbleSort(void* base, int n, int width,
	            int (*compare)(const void* e1, const void* e2))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

int main()
{
	Test test[] = { {'g', 24, 50.96, "liye"}, {'d', 20, 60.93, "wusan"},
		{'h', 28, 59.67, "tangqu"}, {'p', 25, 70.96, "xuqi"} };
	int size = sizeof(test) / sizeof(test[0]);
	printf("排序前：");

	for (int i = 0; i < size; i++)
	{
		printf("%s ", test[i].name);
	}
	printf("\n");

	BubbleSort(test, size, sizeof(test[0]), compare);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%s ", test[i].name);
	}
	printf("\n");
	
	return 0;
}
*/

/*
// 判断当前机器是大端还是小端
union Un
{
	char ch;
	int i;
};
int main()
{
	union Un un;
	un.i = 1;
	if (un.ch == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;
}
*/
