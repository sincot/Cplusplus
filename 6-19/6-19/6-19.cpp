#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 单链表的结构
typedef int SLTDateType;

typedef struct SLTNode
{
	SLTDateType val;
	struct SLTNode* next;
}SLTNode;


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


// 双链表的结构
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType val;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;


#include "List.h"

// 创建新结点
LTNode* LTCreateNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->val = x;
	newnode->prev = newnode->next = newnode;

	return newnode;
}

// 头插
void LTPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newnode = LTCreateNode(x);

	// phead newnode phead->next
	newnode->next = phead->next;
	newnode->prev = phead;

	phead->next->prev = newnode;
	phead->next = newnode;

}

// 尾插
void LTPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newnode = LTCreateNode(x);
	// phead newnode phead->prev
	newnode->prev = phead->prev;
	newnode->next = phead;

	phead->prev->next = newnode;
	phead->prev = newnode;
}

// 判断链表是否为空，即是否只有一个头结点
bool LTEmpty(LTNode* phead)
{
	assert(phead != NULL);
	return phead->next == phead;
}

// 头删
void LTPopFront(LTNode* phead)
{
	assert(!LTEmpty(phead));
	LTNode* del = phead->next;
	// phead del del->next
	phead->next = del->next;
	del->next->prev = phead;
	free(del);
	del = NULL;
}

// 尾删
void LTPopBack(LTNode* phead)
{
	assert(!LTEmpty(phead));
	LTNode* del = phead->prev;
	// phead del del->prev
	phead->prev = del->prev;
	del->prev->next = phead;
	free(del);
	del = NULL;
}

// 指定位置 pos 前插入数据
void LTInsertFront(LTNode* pos, LTDateType x)
{
	assert(pos != NULL);

	LTNode* newnode = LTCreateNode(x);
	// pos->prev newnode pos
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
}

// 指定位置 pos 后插入数据
void LTInsertBack(LTNode* pos, LTDateType x)
{
	assert(pos != NULL);
	LTNode* newnode = LTCreateNode(x);
	// pos newnode pos->next
	newnode->next = pos->next;
	newnode->prev = pos;

	pos->next->prev = newnode;
	pos->next = newnode;
}

// 删除指定位置 pos 的数据
void LTErase(LTNode* pos)
{
	assert(pos != NULL);

	// pos->prev pos pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

// 查找数据
LTNode* LTFind(LTNode* phead, LTDateType x)
{
	assert(!LTEmpty(phead));
	LTNode* prev = phead->next;
	while (prev != phead)
	{
		if (prev->val == x)
		{
			return prev;
		}
		prev = prev->next;
	}

	return NULL;
}

// 打印链表
void LTPrint(LTNode* phead)
{
	assert(!LTEmpty(phead));
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d -> ", pcur->val);
		pcur = pcur->next;
	}
}

// 销毁链表的数据
LTNode* LTDestory(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;

	return phead;
}