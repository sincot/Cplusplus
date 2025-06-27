#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// 顺序表的实现

/*
// 顺序表的底层结构
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType* arr;
	int size;
	int capacity;
}SLTNode;

// 初始化顺序表
void SLTInit(SLTNode* psl);

// 扩容
void SLTCheckCapacity(SLTNode* psl);

// 头插
void SLTPushFront(SLTNode* psl, SLTDateType x);

// 尾插
void SLTPushBack(SLTNode* psl, SLTDateType x);

// 头删
void SLTPopFront(SLTNode* psl);

// 尾删
void SLTPopBack(SLTNode* psl);

// 指定位置插入数据
void SLTInsert(SLTNode* psl, SLTDateType pos, SLTDateType x);

// 指定位置后插入数据
void SLTInsertBack(SLTNode* psl, SLTDateType pos, SLTDateType x);

// 删除指定位置的数据
void SLTErase(SLTNode* psl, SLTDateType pos);

// 查找数据
int SLTFind(SLTNode* psl, SLTDateType val);

// 打印数据
void SLTPrint(SLTNode* psl);

// 销毁数据
void SLTDestory(SLTNode* psl);
*/

/*******************************************************************************/

// 单链表的实现

/*
// 单链表的底层结构
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

// 创建空结点
SLNode* SLCreateNode(SLDataType x);

// 头插
void SLPushFront(SLNode** pphead, SLDataType x);

// 尾插
void SLPushBack(SLNode** pphead, SLDataType x);

// 头删
void SLPopFront(SLNode** pphead);

// 尾删
void SLPopBack(SLNode** pphead);

// 在指定位置 pos 处插入数据
void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x);

// 在指定位置 pos 后插入数据
void SLInsertBack(SLNode* pos, SLDataType x);

// 删除指定位置 pos 处的数据
void SLErase(SLNode** pphead, SLNode* pos);

// 删除指定位置 pos 后的数据
void SLEraseBack(SLNode* pos);

// 查找数据
SLNode* SLFind(SLNode* phead, SLDataType x);

// 打印数据
void SLPrint(SLNode* phead);

// 销毁数据
void SLDestory(SLNode** pphead);
*/

/*******************************************************************************/

// 双链表的实现

/*
// 双链表的底层结构
typedef int LTDataType;
typedef struct LTNode
{
	LTDataType data;
	struct LTNode* prev;
	struct LTNode* next;
}LTNode;

// 创建空的结点
LTNode* LTCreateNode(LTDataType x);

// 头节点的初始化
LTNode* LTInit(LTDataType x);

// 头插结点
void LTPushFront(LTNode* phead, LTDataType x);

// 尾插结点
void LTPushBack(LTNode* phead, LTDataType x);

// 头删结点
void LTPopFront(LTNode* phead);

// 尾删结点
void LTPopBack(LTNode* phead);

// 在指定位置 pos 处插入数据
void LTInsert(LTNode* pos, LTDataType x);

// 在指定位置 pos 后插入数据
void LTInsertBack(LTNode* pos, LTDataType x);

// 删除指定位置 pos 处的数据
void LTErase(LTNode* pos);

// 判断链表中的数据是否为0
bool LTEmpty(LTNode* phead);

// 查找结点
LTNode* LTFind(LTNode* phead, LTDataType x);

// 打印结点的数据
void LTPrint(LTNode* phead);

// 销毁链表中的数据
LTNode* LTDestory(LTNode* phead);
*/

/*******************************************************************************/

// 栈的实现

/*
// 栈的底层结构
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}ST;

// 初始化栈
void STInit(ST* pst);

// 销毁栈的数据
void STDestory(ST* pst);

// 入栈
void STPushTop(ST* pst, STDataType x);

// 出栈
void STPopTop(ST* pst);

// 取栈顶数据
STDataType STGetTop(ST* pst);

// 获取栈中有效数据个数
int STGetSize(ST* pst);

// 判断栈中数据是否为 0
bool STEmpty(ST* pst);

// 打印栈中的数据
void STPrint(ST* pst);
*/

/*******************************************************************************/

// 队列的实现

/*
// 队列结点的实现
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

// 队列结构的实现
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

// 队列的初始化
void QueueInit(Queue* pq);

// 入队列
void QueuePush(Queue* pq, QDataType x);

// 出队列
void QueuePop(Queue* pq);

// 取队头的数据
QDataType QueueFront(Queue* pq);

// 取队尾数据
QDataType QueueBack(Queue* pq);

// 获取队列中的有效数据个数
int QueueGetSize(Queue* pq);

// 判断队列中的数据是否为 NULL
bool QueueEmpty(Queue* pq);

// 打印队列中的数据
void QueuePrint(Queue* pq);

// 销毁队列中的数据
void QueueDestory(Queue* pq);
*/
