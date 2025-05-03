#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct other
{
	char character;
	int rint;
	float rfloat;
};

struct book
{
	char name[20];
	char author[20];
	struct other ther;
	double price;
};

struct
{
	int id;
	int name[20];
	int age;
	double high;
}stu1, stu2;

typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SLNode;

struct Test1
{
	char charc1;
	char charc2;
	int rint;
};

struct Test2
{
	char charc1;
	int rint;
	char charc2;
};

#pragma pack(2) // 设置默认对齐数为2
struct Test3
{
	char charc1;
	int rint;
	char charc2;
};
#pragma pack() // 取消设置的默认对齐数

struct A
{
	int arr[5];
	int a;
};

void Print1(struct A aa)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", aa.arr[i]);
	}
	printf("\n");
}

void Print2(struct A* paa)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", paa->arr[i]);
	}
	printf("\n");
}

//位段的声明
struct Digital
{
	int m_a : 2;
	int m_b : 5;
	int m_c : 10;
	int m_d : 30;
};

struct Number
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

////联合体的声明
//union Un
//{
//	char charac;
//	int rint;
//};
//
//union Un1
//{
//	char ch[5];
//	int a1;
//};

/*
union Un
{
	char c;
	int i;
};
*/

//枚举类型的声明
enum Day
{
	//枚举类型的可能取值
	//这些可能取值都是常量，并且它们都是有值的
	Mon = 4,
	Tues = 3,
	Wed = 6,
	Thur = 9,
	Fri = 13,
	Sat = 17,
	Sun = 1
};

int main()
{
	//枚举类型的定义
	enum Day day = Sun;

	//打印枚举类型Day的所有可能取值
	printf("%d\t", Mon);
	printf("%d\t", Tues);
	printf("%d\t", Wed);
	printf("%d\t", Thur);
	printf("%d\t", Fri);
	printf("%d\t", Sat);
	printf("%d\t", Sun);

	/*union Un un;
	un.i = 1;
	if (un.c == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}*/


	//printf("%zd\n", sizeof(union Un1));

	////联合体的定义
	//union Un u;
	////求联合体的大小
	//printf("联合体的大小为：%zd字节\n", sizeof(union Un));

	////打印联合体对象的地址以及其中成员变量的地址
	//printf("联合体对象u的地址为： %p\n", &u);
	//printf("联合体成员charac的地址为： %p\n", &(u.charac));
	//printf("联合体成员rint的地址为： %p\n", &(u.rint)); 

	//struct Digital dig = { 0 };
	////错误方法 —— scanf("%d", &dig.m_a);

	////正确方法
	//int a = 0;
	//scanf("%d", &a);
	//dig.m_a = a;

	//printf("%zd\n", sizeof(struct Number));

	//struct A aa = { {1, 3, 5, 7, 9}, 10 };
	////结构体的传址传参
	//Print2(&aa);

	////结构体的传值传参
	//Print1(aa);

	/*printf("%zd\n", sizeof(struct Test2));
	printf("%zd\n", sizeof(struct Test3));*/

	/*printf("%zd\n", sizeof(struct Test1));
	printf("%zd\n", sizeof(struct Test2));*/

	//struct book book5 = { "ppt", "ptr", { 'G', 68, 53.2 }, 9.9 };
	//book5.price = 99.9;
	//book5.ther.character = 'H';
	//strcpy(book5.name, "小鸡的独立");
	////单独访问
	//printf("%s\t", book5.name);
	//printf("%.2f\t", book5.price);
	//printf("%c\t", book5.ther.character);

	/*
	//一起访问
	printf("%s\t%s\t%.2f\n", book5.name, book5.author, book5.price);
	printf("%c\t%d\t%.2f", book5.ther.character, book5.ther.rint, book5.ther.rfloat);
	*/

	////局部变量
	//struct book book1 = { "老鹰抓小鸡", "初一", 88.8 };
	//struct book book2 = { "小鸡自卫战", "初一", 99.9 };
	//struct book book3 = { .author = "埃伊蟹黄面", .name = "小鸡吃老鹰", .price = 77.7 };
	//struct book book4 = { .price = 109.8, .name = "小鸡变老鹰", .author = "埃伊蟹黄面" };
	return 0;
}