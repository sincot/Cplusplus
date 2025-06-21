#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// ��ʼ��
void StackInit(Stack* pst)
{
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

// ��ջ ���� β��
void StackPush(Stack* pst, STDateType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		STDateType* tmp = (STDateType*)realloc(pst->arr, sizeof(STDateType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc fail!");
			exit(1);
		}
		pst->arr = tmp;
		pst->capacity = newcapacity;
	}

	pst->arr[pst->top++] = x;
}

// ��ջ
void StackPop(Stack* pst)
{
	assert(!StackEmpty(pst));
	pst->top--;
}

// ��ȡ��ǰջ�е����ݸ���
int StackSize(Stack* pst)
{
	return pst->top;
}

// ȡջ������
STDateType StackTop(Stack* pst)
{
	assert(!StackEmpty(pst));
	return pst->arr[pst->top - 1];
}

// ����
void StackDestory(Stack* pst)
{
	if (pst->arr != NULL)
	{
		free(pst->arr);
		pst->arr = NULL;
	}
	pst->top = pst->capacity = 0;
}

// �ж�ջ�������Ƿ�Ϊ0
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}

// ��ӡջ����
void StackPrint(Stack* pst)
{
	assert(!StackEmpty(pst));
	for (size_t i = 0; i < pst->top; i++)
	{
		printf("%d ", pst->arr[i]);
	}
	printf("\n");
}


//**************** ������ջ����غ��������� ****************

// ���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}

// �����µĽ��
QueueNode* QueueCreateNode(QDateType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(2);
	}
	newnode->val = x;
	newnode->next = NULL;

	return newnode;
}

// ����� ���� ��β
void QueuePush(Queue* pq, QDateType x)
{
	assert(pq);
	QueueNode* newnode = QueueCreateNode(x);

	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

// ������ ���� ��ͷ
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

// ȡ��ͷ������
QDateType QueueTop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->val;
}

// ȡ��β������
QDateType QueueFoot(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->val;
}

// �ж϶����е������Ƿ�Ϊ0
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

// ��ӡ���е�����
void QueuePrint(Queue* pq)
{
	assert(!QueueEmpty(pq));
	QueueNode* pcur = pq->phead;
	while (pcur != NULL)
	{
		printf("%d -> ", pcur->val);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

// ��ȡ�����е���Ч���ݸ���
int QueueSize(Queue* pq)
{
	int count = 0;
	QueueNode* pcur = pq->phead;
	while (pcur != NULL)
	{
		count++;
		pcur = pcur->next;
	}

	return count;
}

// ���ٶ����е�����
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur != NULL)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
}
