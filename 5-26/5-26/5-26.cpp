#include "SListNode.h"

int main()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 1);
	/*SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 5);*/
	SLTNode* pfind = SLTFind(plist, 1);
	//SLTInsertFront(&plist, pfind, 100);
	SLTErase(&plist, pfind);
    
	/*SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);*/
	//SLTPushBack(&plist, 100);
	/*SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);*/
	//SLTPopFront(&plist);
	//SLTDestory(&plist);
	
	SLTPrint(plist);

	return 0;
}