#include "SListNode.h"

// 开辟空间
SLTNode* SLTByCapacity(SLTDateType x)
{
	// 为新的结点开辟结点大小的内存空间
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->val = x;
	newnode->next = NULL;

	return newnode;
}

// 头插
void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	// 开辟结点空间
	SLTNode* newnode = SLTByCapacity(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

// 尾插
void SLTPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead != NULL);
	// 开辟结点空间
	SLTNode* newnode = SLTByCapacity(x);
	
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// 遍历，找尾结点
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

// 头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

// 尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// 找尾结点和尾结点的前一个结点
		SLTNode* pcur = NULL;
		SLTNode* ptail = *pphead;

		while (ptail->next != NULL)
		{
			pcur = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		pcur->next = NULL;
	}
}

// 打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d ->", pcur->val);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

// 在指定位置 pos 前插入数据
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pos != NULL);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		// 创建新的结点
		SLTNode* newnode = SLTByCapacity(x);
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		newnode->next = pos;
		pcur->next = newnode;
	}
}

// 在指定位置 pos 后插入数据
void SLTInsertBack(SLTNode* pos, SLTDateType x)
{
	assert(pos != NULL);
	// 创建新的结点
	SLTNode* newnode = SLTByCapacity(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 在指定位置 pos 删除数据
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos != NULL);
	// 只有一个结点
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

// 查找结点
SLTNode* SLTFind(SLTNode* phead, SLTDateType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		if (pcur->val == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	return NULL;
}

// 销毁
void SLTDestory(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);
	SLTNode* pcur = *pphead;
	while (pcur != NULL)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	// 将指向这个链表的指针置为空
	*pphead = NULL;
}