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

#pragma pack(2) // ����Ĭ�϶�����Ϊ2
struct Test3
{
	char charc1;
	int rint;
	char charc2;
};
#pragma pack() // ȡ�����õ�Ĭ�϶�����

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

//λ�ε�����
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

////�����������
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

//ö�����͵�����
enum Day
{
	//ö�����͵Ŀ���ȡֵ
	//��Щ����ȡֵ���ǳ������������Ƕ�����ֵ��
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
	//ö�����͵Ķ���
	enum Day day = Sun;

	//��ӡö������Day�����п���ȡֵ
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
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}*/


	//printf("%zd\n", sizeof(union Un1));

	////������Ķ���
	//union Un u;
	////��������Ĵ�С
	//printf("������Ĵ�СΪ��%zd�ֽ�\n", sizeof(union Un));

	////��ӡ���������ĵ�ַ�Լ����г�Ա�����ĵ�ַ
	//printf("���������u�ĵ�ַΪ�� %p\n", &u);
	//printf("�������Աcharac�ĵ�ַΪ�� %p\n", &(u.charac));
	//printf("�������Աrint�ĵ�ַΪ�� %p\n", &(u.rint)); 

	//struct Digital dig = { 0 };
	////���󷽷� ���� scanf("%d", &dig.m_a);

	////��ȷ����
	//int a = 0;
	//scanf("%d", &a);
	//dig.m_a = a;

	//printf("%zd\n", sizeof(struct Number));

	//struct A aa = { {1, 3, 5, 7, 9}, 10 };
	////�ṹ��Ĵ�ַ����
	//Print2(&aa);

	////�ṹ��Ĵ�ֵ����
	//Print1(aa);

	/*printf("%zd\n", sizeof(struct Test2));
	printf("%zd\n", sizeof(struct Test3));*/

	/*printf("%zd\n", sizeof(struct Test1));
	printf("%zd\n", sizeof(struct Test2));*/

	//struct book book5 = { "ppt", "ptr", { 'G', 68, 53.2 }, 9.9 };
	//book5.price = 99.9;
	//book5.ther.character = 'H';
	//strcpy(book5.name, "С���Ķ���");
	////��������
	//printf("%s\t", book5.name);
	//printf("%.2f\t", book5.price);
	//printf("%c\t", book5.ther.character);

	/*
	//һ�����
	printf("%s\t%s\t%.2f\n", book5.name, book5.author, book5.price);
	printf("%c\t%d\t%.2f", book5.ther.character, book5.ther.rint, book5.ther.rfloat);
	*/

	////�ֲ�����
	//struct book book1 = { "��ӥץС��", "��һ", 88.8 };
	//struct book book2 = { "С������ս", "��һ", 99.9 };
	//struct book book3 = { .author = "����з����", .name = "С������ӥ", .price = 77.7 };
	//struct book book4 = { .price = 109.8, .name = "С������ӥ", .author = "����з����" };
	return 0;
}