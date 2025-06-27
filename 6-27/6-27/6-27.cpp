#include "6-27.h"

/*
// ��ʼ��˳���
void SLTInit(SLTNode* psl)
{
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}

// ����
void SLTCheckCapacity(SLTNode* psl)
{
	if (psl->size == psl->capacity)
	{
		int newcapacity = psl->capacity == 0 ? 4 : 2 * psl->capacity;
		SLTDateType* tmp = (SLTDateType*)realloc(psl->arr, sizeof(SLTDateType) * newcapacity);

		if (tmp == NULL)
		{
			perror("tmp malloc fail!");
			exit(1);
		}

		psl->arr = tmp;
		psl->capacity = newcapacity;
	}
}

// ͷ��
void SLTPushFront(SLTNode* psl, SLTDateType x)
{
	assert(psl);
	SLTCheckCapacity(psl);

	for (int i = psl->size - 1; i >= 0; i--)
	{
		psl->arr[i + 1] = psl->arr[i];
	}

	psl->arr[0] = x;
	psl->size++;
}

// β��
void SLTPushBack(SLTNode* psl, SLTDateType x)
{
	assert(psl);
	SLTCheckCapacity(psl);

	psl->arr[psl->size++] = x;
}

// ͷɾ
void SLTPopFront(SLTNode* psl)
{
	assert(psl && psl->size != 0);

	for (int i = 0; i < psl->size - 1; i++)
	{
		psl->arr[i] = psl->arr[i + 1];
	}

	psl->size--;
}

// βɾ
void SLTPopBack(SLTNode* psl)
{
	assert(psl && psl->size != 0);

	psl->size--;
}

// ָ��λ�ò�������
void SLTInsert(SLTNode* psl, SLTDateType pos, SLTDateType x)
{
	assert(psl);
	assert(pos >= 0 && pos < psl->size);

	SLTCheckCapacity(psl);

	for (int i = psl->size - 1; i >= pos; i--)
	{
		psl->arr[i + 1] = psl->arr[i];
	}

	psl->arr[pos] = x;
	psl->size++;
}

// ָ��λ�ú��������
void SLTInsertBack(SLTNode* psl, SLTDateType pos, SLTDateType x)
{
	assert(psl);
	assert(pos >= 0 && pos < psl->size);

	SLTCheckCapacity(psl);

	for (int i = psl->size - 1; i >= pos + 1; i--)
	{
		psl->arr[i + 1] = psl->arr[i];
	}

	psl->arr[pos + 1] = x;
	psl->size++;
}

// ɾ��ָ��λ�õ�����
void SLTErase(SLTNode* psl, SLTDateType pos)
{
	assert(psl && psl->size != 0);
	assert(pos >= 0 && pos < psl->size);

	for (int i = pos; i < psl->size - 1; i++)
	{
		psl->arr[i] = psl->arr[i + 1];
	}

	psl->size--;
}

// ��������
int SLTFind(SLTNode* psl, SLTDateType val)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == val)
		{
			return i;
		}
	}

	return -1;
}

// ��ӡ����
void SLTPrint(SLTNode* psl)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
}

// ��������
void SLTDestory(SLTNode* psl)
{
	assert(psl);

	if (psl->arr != NULL)
	{
		free(psl->arr);
		psl->arr = NULL;
	}

	psl->size = psl->capacity = 0;
	psl = NULL;
}
*/

/*******************************************************************************/

/*
// �����ս��
SLNode* SLCreateNode(SLDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	
	if (newnode == NULL)
	{
		perror("newnode malloc fail!");
		exit(2);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

// ͷ��
void SLPushFront(SLNode** pphead, SLDataType x)
{
	assert(pphead != NULL);

	SLNode* newnode = SLCreateNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

// β��
void SLPushBack(SLNode** pphead, SLDataType x)
{
	assert(pphead != NULL);

	SLNode* newnode = SLCreateNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* pcur = *pphead;
		while (pcur->next != NULL)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}

// ͷɾ
void SLPopFront(SLNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);
	SLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

// βɾ
void SLPopBack(SLNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* pcur = NULL;
		SLNode* ptail = *pphead;
		
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

// ��ָ��λ�� pos ����������
void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x)
{
	assert(pphead != NULL && pos != NULL);

	SLNode* newnode = SLCreateNode(x);

	if (pos == *pphead)
	{
		SLPushFront(pphead, x);
	}
	else
	{
		SLNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}

		pcur->next = newnode;
		newnode->next = pos;
	}
}

// ��ָ��λ�� pos ���������
void SLInsertBack(SLNode* pos, SLDataType x)
{
	assert(pos != NULL);

	SLNode* newnode = SLCreateNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ɾ��ָ��λ�� pos ��������
void SLErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead != NULL && *pphead != NULL);
	assert(pos != NULL);

	if (pos == *pphead)
	{
		SLPopFront(pphead);
	}
	else
	{
		SLNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}

		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

// ɾ��ָ��λ�� pos �������
void SLEraseBack(SLNode* pos)
{
	assert(pos != NULL && pos->next != NULL);

	SLNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

// ��������
SLNode* SLFind(SLNode* phead, SLDataType x)
{
	assert(phead);

	SLNode* pcur = phead;
	while (pcur != NULL)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}

	return NULL;
}

// ��ӡ����
void SLPrint(SLNode* phead)
{
	SLNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d-> ", pcur->data);
		pcur = pcur->next;
	}

	printf("NULL");
}

// ��������
void SLDestory(SLNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);
	
	SLNode* pcur = *pphead;
	while (pcur != NULL)
	{
		SLNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}

	*pphead = NULL;
}
*/

/*******************************************************************************/

/*
// �����յĽ��
LTNode* LTCreateNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));

	if (newnode == NULL)
	{
		perror("newnode malloc fail!");
		exit(3);
	}

	newnode->data = x;
	newnode->prev = newnode->next = newnode;

	return newnode;
}

// ͷ���ĳ�ʼ��
LTNode* LTInit(LTDataType x)
{
	LTNode* phead = LTCreateNode(x);

	return phead;
}

// ͷ����
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = LTCreateNode(x);

	// phead newnode phead->next
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

// β����
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = LTCreateNode(x);

	// phead->pcur newnode phead
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

// ͷɾ���
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

// βɾ���
void LTPopBack(LTNode* phead)
{
	assert(!LTEmpty(phead));

	LTNode* del = phead->prev;
	// del->prev del phead
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}


// �ж������е������Ƿ�Ϊ0
bool LTEmpty(LTNode* phead)
{
	assert(phead);

	if (phead->next == phead)
	{
		return true;
	}

	return false;
}

// ��ָ��λ�� pos ����������
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos != NULL);

	LTNode* newnode = LTCreateNode(x);
	// pos->prev newnode pos 
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
}

// ��ָ��λ�� pos ���������
void LTInsertBack(LTNode* pos, LTDataType x)
{
	assert(pos != NULL);

	LTNode* newnode = LTCreateNode(x);
	// pos newnode pos->next
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

// ɾ��ָ��λ�� pos ��������
void LTErase(LTNode* pos)
{
	assert(pos != NULL);

	// pos->prev pos pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

// ���ҽ��
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(!LTEmpty(phead));

	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}

		pcur = pcur->next;
	}

	return NULL;
}


// ��ӡ��������
void LTPrint(LTNode* phead)
{
	assert(!LTEmpty(phead));

	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d-> ", pcur->data);
		pcur = pcur->next;
	}
}

// ���������е�����
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
*/

/*******************************************************************************/

/*
// ��ʼ��ջ
void STInit(ST* pst)
{
	assert(pst);

	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

// ��ջ
void STPushTop(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		STDataType* tmp = (STDataType*)realloc(pst->arr, sizeof(STDataType) * newcapacity);

		if (tmp == NULL)
		{
			perror("tmp realloc fail!");
			exit(4);
		}

		pst->arr = tmp;
		pst->capacity = newcapacity;
	}

	pst->arr[pst->top++] = x;
}

// ��ջ
void STPopTop(ST* pst)
{
	assert(!STEmpty(pst));

	pst->top--;
}

// ȡջ������
STDataType STGetTop(ST* pst)
{
	assert(!STEmpty(pst));

	return pst->arr[pst->top - 1];
}

// ��ȡջ����Ч���ݸ���
int STGetSize(ST* pst)
{
	assert(pst);

	return pst->top;
}

// �ж�ջ�������Ƿ�Ϊ 0
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// ��ӡջ�е�����
void STPrint(ST* pst)
{
	assert(pst);

	for (int i = 0; i < pst->top; i++)
	{
		printf("%d ", pst->arr[i]);
	}
}

// ����ջ�е�����
void STDestory(ST* pst)
{
	assert(pst);

	if (pst->arr != NULL)
	{
		free(pst->arr);
	}

	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}
*/

/*******************************************************************************/

/*
// ���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
}

// �����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));

	if (newnode == NULL)
	{
		perror("newnode malloc fail!");
		exit(5);
	}

	newnode->data = x;
	newnode->next = NULL;

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

// ������
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));

	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

// ȡ��ͷ������
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

// ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}

// ��ȡ�����е���Ч���ݸ���
int QueueGetSize(Queue* pq)
{
	int size = 0;
	
	QueueNode* pcur = pq->phead;
	while (pcur != NULL)
	{
		size++;
		pcur = pcur->next;
	}

	return size;
}

// �ж϶����е������Ƿ�Ϊ NULL
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->phead == NULL;
}

// ��ӡ�����е�����
void QueuePrint(Queue* pq)
{
	assert(pq);

	QueueNode* pcur = pq->phead;
	while(pcur != NULL)
	{
		printf("%d-> ", pcur->data);
		pcur = pcur->next;
	}

	printf("NULL");
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
*/
