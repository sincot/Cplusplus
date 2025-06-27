#include "6-27.h"

void test1()
{
	/*SLTNode sl;
	SLTInit(&sl);
	SLTPushFront(&sl, 1);
	SLTPushFront(&sl, 2);
	SLTPushFront(&sl, 3);
	SLTPushFront(&sl, 4);
	SLTPushFront(&sl, 5);*/
	//SLTPushBack(&sl, 100);
	/*SLTPopFront(&sl);
	SLTPopFront(&sl);*/
	/*SLTPopBack(&sl);
	SLTPopBack(&sl);*/
	//SLTDestory(&sl);
	//SLTInsertBack(&sl, 4, 200);
	//SLTErase(&sl, 0);
	/*int ret = SLTFind(&sl, 3);
	if (ret >= 0)
	{
		printf("找到了，下标是%d", ret);
	}
	else
	{
		printf("未找到");
	}*/

	//SLTPrint(&sl);

	/*for (size_t i = 0; i < sl.size; i++)
	{
		printf("%d ", sl.arr[i]);
	}*/

}

void test2()
{
	//SLNode* sl = NULL;
	
	/*SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);*/
	/*SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);*/
	//SLPopFront(&sl);
	/*SLPopBack(&sl);
	SLPopBack(&sl);*/
	//SLNode* pfind = SLFind(sl, 5);
	/*if (pfind != NULL)
	{
		printf("找到了");
	}
	else
	{
		printf("未找到");
	}*/
	//SLInsert(&sl, pfind, 200);
	//SLInsertBack(pfind, 200);
	//SLErase(&sl, pfind);
	//SLEraseBack(pfind);

	//SLPrint(sl);
	//SLDestory(&sl);
}

void test3()
{
	/*LTNode* plist = LTInit(-1);
	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPushFront(plist, 5);
	LTPushBack(plist, 400);*/
	//LTPopFront(plist);
	/*LTPopBack(plist);
	LTPopBack(plist);*/
	//LTNode* pfind = LTFind(plist, 400);
	//LTInsert(pfind, 300);
	//LTInsertBack(pfind, 300);
	//LTErase(pfind);

	//LTPrint(plist);
	/*LTDestory(plist);
	plist = NULL;*/
}

void test4()
{
	//ST st;
	//STInit(&st);
	//STPushTop(&st, 1);
	//STPushTop(&st, 2);
	//STPushTop(&st, 3);
	//STPushTop(&st, 4);
	//STPushTop(&st, 5);
	////STPopTop(&st);

	//printf("%d ", STGetTop(&st));
	//printf("%d ", STGetSize(&st));
	////STPrint(&st);

	//STDestory(&st);
}

void test5()
{
	/*Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	//QueuePop(&q);
	QueueDestory(&q);*/
	
	/*printf("%d ", QueueFront(&q));
	printf("%d ", QueueBack(&q));
	printf("%d ", QueueGetSize(&q));
	printf("\n");*/

	//QueuePrint(&q);
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();

	return 0;
}