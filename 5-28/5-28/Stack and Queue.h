#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// ����ջ�Ľṹ ���� �ײ�������
typedef int STDateType;
typedef struct Stack
{
	STDateType* arr;
	int top;
	int capacity;
}Stack;

// ��ʼ��
void StackInit(Stack* pst);

// ����
void StackDestory(Stack* pst);

// ��ջ
void StackPush(Stack* pst, STDateType x);

// ��ջ
void StackPop(Stack* pst);

// ȡջ������
STDateType StackTop(Stack* pst);

// ��ȡ��ǰջ�е����ݸ���
int StackSize(Stack* pst);

// �ж�ջ�������Ƿ�Ϊ0
bool StackEmpty(Stack* pst);

// ��ӡջ����
void StackPrint(Stack* pst);

//**************** ������ջ����غ����Ķ��� ****************


typedef int QDateType;
// ������Ľṹ
typedef struct QueueNode
{
	QDateType val;
	struct QueueNode* next;
}QueueNode;

// ������еĽṹ
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

// ���еĳ�ʼ��
void QueueInit(Queue* pq);

// �����µĽ��
QueueNode* QueueCreateNode(QDateType x);

// ����� ���� ��β
void QueuePush(Queue* pq, QDateType x);

// ������ ���� ��ͷ
void QueuePop(Queue* pq);

// ȡ��ͷ������
QDateType QueueTop(Queue* pq);

// ȡ��β������
QDateType QueueFoot(Queue* pq);

// �ж϶����е������Ƿ�Ϊ0
bool QueueEmpty(Queue* pq);

// ��ӡ���е�����
void QueuePrint(Queue* pq);

// ��ȡ�����е���Ч���ݸ���
int QueueSize(Queue* pq);

// ���ٶ����е�����
void QueueDestory(Queue* pq);
