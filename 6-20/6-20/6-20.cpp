#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// 初始化
void StackInit(Stack* pst)
{
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}

// 入栈 —— 尾插
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

// 出栈
void StackPop(Stack* pst)
{
	assert(!StackEmpty(pst));
	pst->top--;
}

// 获取当前栈中的数据个数
int StackSize(Stack* pst)
{
	return pst->top;
}

// 取栈顶数据
STDateType StackTop(Stack* pst)
{
	assert(!StackEmpty(pst));
	return pst->arr[pst->top - 1];
}

// 销毁
void StackDestory(Stack* pst)
{
	if (pst->arr != NULL)
	{
		free(pst->arr);
		pst->arr = NULL;
	}
	pst->top = pst->capacity = 0;
}

// 判断栈中数据是否为0
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}

// 打印栈数据
void StackPrint(Stack* pst)
{
	assert(!StackEmpty(pst));
	for (size_t i = 0; i < pst->top; i++)
	{
		printf("%d ", pst->arr[i]);
	}
	printf("\n");
}


//**************** 以上是栈的相关函数的声明 ****************

// 队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}

// 创建新的结点
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

// 入队列 —— 队尾
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

// 出队列 —— 队头
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

// 取队头的数据
QDateType QueueTop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->val;
}

// 取队尾的数据
QDateType QueueFoot(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->val;
}

// 判断队列中的数据是否为0
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

// 打印队列的数据
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

// 获取队列中的有效数据个数
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
