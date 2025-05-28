#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义栈的结构 —— 底层是数组
typedef int STDateType;
typedef struct Stack
{
	STDateType* arr;
	int top;
	int capacity;
}Stack;

// 初始化
void StackInit(Stack* pst);

// 销毁
void StackDestory(Stack* pst);

// 入栈
void StackPush(Stack* pst, STDateType x);

// 出栈
void StackPop(Stack* pst);

// 取栈顶数据
STDateType StackTop(Stack* pst);

// 获取当前栈中的数据个数
int StackSize(Stack* pst);

// 判断栈中数据是否为0
bool StackEmpty(Stack* pst);

// 打印栈数据
void StackPrint(Stack* pst);

//**************** 以上是栈的相关函数的定义 ****************


typedef int QDateType;
// 定义结点的结构
typedef struct QueueNode
{
	QDateType val;
	struct QueueNode* next;
}QueueNode;

// 定义队列的结构
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

// 队列的初始化
void QueueInit(Queue* pq);

// 创建新的结点
QueueNode* QueueCreateNode(QDateType x);

// 入队列 —— 队尾
void QueuePush(Queue* pq, QDateType x);

// 出队列 —— 队头
void QueuePop(Queue* pq);

// 取队头的数据
QDateType QueueTop(Queue* pq);

// 取队尾的数据
QDateType QueueFoot(Queue* pq);

// 判断队列中的数据是否为0
bool QueueEmpty(Queue* pq);

// 打印队列的数据
void QueuePrint(Queue* pq);

// 获取队列中的有效数据个数
int QueueSize(Queue* pq);

// 销毁队列中的数据
void QueueDestory(Queue* pq);
