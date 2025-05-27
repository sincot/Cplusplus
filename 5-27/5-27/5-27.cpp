#include "List.h"

int main()
{
	// 头结点
	LTNode* plist = LTCreateNode(-1);
	/*LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);*/
	//LTPushBack(plist, 100);
	LTPushFront(plist, 100);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	//LTNode* pfind = LTFind(plist, 4);
	//LTInsertFront(pfind, 200);
	//LTInsertBack(pfind, 20);
	//LTInsertFront(plist, pfind, 200);
	/*if (pfind != NULL)
	{
		printf("找到了！\n");
	}
	else
	{
		printf("未找到！\n");
	}*/
	//LTPopFront(plist);
	//LTPopBack(plist);
	LTDestory(plist);
	plist = NULL;

	//LTPrint(plist);

	return 0;
}