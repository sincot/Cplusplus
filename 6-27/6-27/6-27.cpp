#include "6-27.h"

/*
// 初始化顺序表
void SLTInit(SLTNode* psl)
{
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}

// 扩容
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

// 头插
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

// 尾插
void SLTPushBack(SLTNode* psl, SLTDateType x)
{
	assert(psl);
	SLTCheckCapacity(psl);

	psl->arr[psl->size++] = x;
}

// 头删
void SLTPopFront(SLTNode* psl)
{
	assert(psl && psl->size != 0);

	for (int i = 0; i < psl->size - 1; i++)
	{
		psl->arr[i] = psl->arr[i + 1];
	}

	psl->size--;
}

// 尾删
void SLTPopBack(SLTNode* psl)
{
	assert(psl && psl->size != 0);

	psl->size--;
}

// 指定位置插入数据
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

// 指定位置后插入数据
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

// 删除指定位置的数据
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

// 查找数据
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

// 打印数据
void SLTPrint(SLTNode* psl)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
}

// 销毁数据
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
// 创建空结点
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

// 头插
void SLPushFront(SLNode** pphead, SLDataType x)
{
	assert(pphead != NULL);

	SLNode* newnode = SLCreateNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

// 尾插
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

// 头删
void SLPopFront(SLNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);
	SLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

// 尾删
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

// 在指定位置 pos 处插入数据
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

// 在指定位置 pos 后插入数据
void SLInsertBack(SLNode* pos, SLDataType x)
{
	assert(pos != NULL);

	SLNode* newnode = SLCreateNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 删除指定位置 pos 处的数据
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

// 删除指定位置 pos 后的数据
void SLEraseBack(SLNode* pos)
{
	assert(pos != NULL && pos->next != NULL);

	SLNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

// 查找数据
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

// 打印数据
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

// 销毁数据
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
// 创建空的结点
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

// 头结点的初始化
LTNode* LTInit(LTDataType x)
{
	LTNode* phead = LTCreateNode(x);

	return phead;
}

// 头插结点
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

// 尾插结点
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

// 头删结点
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

// 尾删结点
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


// 判断链表中的数据是否为0
bool LTEmpty(LTNode* phead)
{
	assert(phead);

	if (phead->next == phead)
	{
		return true;
	}

	return false;
}

// 在指定位置 pos 处插入数据
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

// 在指定位置 pos 后插入数据
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

// 删除指定位置 pos 处的数据
void LTErase(LTNode* pos)
{
	assert(pos != NULL);

	// pos->prev pos pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

// 查找结点
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


// 打印结点的数据
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

// 销毁链表中的数据
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
// 初始化栈
void STInit(ST* pst)
{
	assert(pst);

	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

// 入栈
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

// 出栈
void STPopTop(ST* pst)
{
	assert(!STEmpty(pst));

	pst->top--;
}

// 取栈顶数据
STDataType STGetTop(ST* pst)
{
	assert(!STEmpty(pst));

	return pst->arr[pst->top - 1];
}

// 获取栈中有效数据个数
int STGetSize(ST* pst)
{
	assert(pst);

	return pst->top;
}

// 判断栈中数据是否为 0
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// 打印栈中的数据
void STPrint(ST* pst)
{
	assert(pst);

	for (int i = 0; i < pst->top; i++)
	{
		printf("%d ", pst->arr[i]);
	}
}

// 销毁栈中的数据
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
// 队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
}

// 入队列
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

// 出队列
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));

	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

// 取队头的数据
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

// 取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}

// 获取队列中的有效数据个数
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

// 判断队列中的数据是否为 NULL
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->phead == NULL;
}

// 打印队列中的数据
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

// 销毁队列中的数据
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
