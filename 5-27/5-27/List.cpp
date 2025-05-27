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