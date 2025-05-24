#include "SeqList.h"

int main()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	//SLInsertFront(&sl, 10, 100);
	//SLInsert(&sl, 1, 100);
	//SLErase(&sl, 5);
	//SLPrint(&sl);
	int ret = SLFind(&sl, 4);
	if (ret >= 0)
	{
		printf("找到了,下标是%d", ret);
	}
	else
	{
		printf("未找到");
	}

	//SLDestory(&sl);

	return 0;
}
