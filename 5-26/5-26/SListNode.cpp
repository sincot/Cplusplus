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