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