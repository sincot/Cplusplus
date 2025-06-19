#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// ������Ľṹ
typedef int SLTDateType;

typedef struct SLTNode
{
	SLTDateType val;
	struct SLTNode* next;
}SLTNode;


#include "SListNode.h"

// ���ٿռ�
SLTNode* SLTByCapacity(SLTDateType x)
{
	// Ϊ�µĽ�㿪�ٽ���С���ڴ�ռ�
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

// ͷ��
void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	// ���ٽ��ռ�
	SLTNode* newnode = SLTByCapacity(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

// β��
void SLTPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead != NULL);
	// ���ٽ��ռ�
	SLTNode* newnode = SLTByCapacity(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// ��������β���
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

// ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

// βɾ
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
		// ��β����β����ǰһ�����
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

// ��ӡ
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

// ��ָ��λ�� pos ǰ��������
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pos != NULL);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		// �����µĽ��
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

// ��ָ��λ�� pos ���������
void SLTInsertBack(SLTNode* pos, SLTDateType x)
{
	assert(pos != NULL);
	// �����µĽ��
	SLTNode* newnode = SLTByCapacity(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ��ָ��λ�� pos ɾ������
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos != NULL);
	// ֻ��һ�����
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

// ���ҽ��
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

// ����
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
	// ��ָ����������ָ����Ϊ��
	*pphead = NULL;
}


// ˫����Ľṹ
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType val;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;


#include "List.h"

// �����½��
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

// ͷ��
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

// β��
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

// �ж������Ƿ�Ϊ�գ����Ƿ�ֻ��һ��ͷ���
bool LTEmpty(LTNode* phead)
{
	assert(phead != NULL);
	return phead->next == phead;
}

// ͷɾ
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

// βɾ
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

// ָ��λ�� pos ǰ��������
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

// ָ��λ�� pos ���������
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

// ɾ��ָ��λ�� pos ������
void LTErase(LTNode* pos)
{
	assert(pos != NULL);

	// pos->prev pos pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

// ��������
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

// ��ӡ����
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

// �������������
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