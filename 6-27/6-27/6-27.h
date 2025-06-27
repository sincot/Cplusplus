#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// ˳����ʵ��

/*
// ˳���ĵײ�ṹ
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType* arr;
	int size;
	int capacity;
}SLTNode;

// ��ʼ��˳���
void SLTInit(SLTNode* psl);

// ����
void SLTCheckCapacity(SLTNode* psl);

// ͷ��
void SLTPushFront(SLTNode* psl, SLTDateType x);

// β��
void SLTPushBack(SLTNode* psl, SLTDateType x);

// ͷɾ
void SLTPopFront(SLTNode* psl);

// βɾ
void SLTPopBack(SLTNode* psl);

// ָ��λ�ò�������
void SLTInsert(SLTNode* psl, SLTDateType pos, SLTDateType x);

// ָ��λ�ú��������
void SLTInsertBack(SLTNode* psl, SLTDateType pos, SLTDateType x);

// ɾ��ָ��λ�õ�����
void SLTErase(SLTNode* psl, SLTDateType pos);

// ��������
int SLTFind(SLTNode* psl, SLTDateType val);

// ��ӡ����
void SLTPrint(SLTNode* psl);

// ��������
void SLTDestory(SLTNode* psl);
*/

/*******************************************************************************/

// �������ʵ��

/*
// ������ĵײ�ṹ
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

// �����ս��
SLNode* SLCreateNode(SLDataType x);

// ͷ��
void SLPushFront(SLNode** pphead, SLDataType x);

// β��
void SLPushBack(SLNode** pphead, SLDataType x);

// ͷɾ
void SLPopFront(SLNode** pphead);

// βɾ
void SLPopBack(SLNode** pphead);

// ��ָ��λ�� pos ����������
void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x);

// ��ָ��λ�� pos ���������
void SLInsertBack(SLNode* pos, SLDataType x);

// ɾ��ָ��λ�� pos ��������
void SLErase(SLNode** pphead, SLNode* pos);

// ɾ��ָ��λ�� pos �������
void SLEraseBack(SLNode* pos);

// ��������
SLNode* SLFind(SLNode* phead, SLDataType x);

// ��ӡ����
void SLPrint(SLNode* phead);

// ��������
void SLDestory(SLNode** pphead);
*/

/*******************************************************************************/

// ˫�����ʵ��

/*
// ˫����ĵײ�ṹ
typedef int LTDataType;
typedef struct LTNode
{
	LTDataType data;
	struct LTNode* prev;
	struct LTNode* next;
}LTNode;

// �����յĽ��
LTNode* LTCreateNode(LTDataType x);

// ͷ�ڵ�ĳ�ʼ��
LTNode* LTInit(LTDataType x);

// ͷ����
void LTPushFront(LTNode* phead, LTDataType x);

// β����
void LTPushBack(LTNode* phead, LTDataType x);

// ͷɾ���
void LTPopFront(LTNode* phead);

// βɾ���
void LTPopBack(LTNode* phead);

// ��ָ��λ�� pos ����������
void LTInsert(LTNode* pos, LTDataType x);

// ��ָ��λ�� pos ���������
void LTInsertBack(LTNode* pos, LTDataType x);

// ɾ��ָ��λ�� pos ��������
void LTErase(LTNode* pos);

// �ж������е������Ƿ�Ϊ0
bool LTEmpty(LTNode* phead);

// ���ҽ��
LTNode* LTFind(LTNode* phead, LTDataType x);

// ��ӡ��������
void LTPrint(LTNode* phead);

// ���������е�����
LTNode* LTDestory(LTNode* phead);
*/

/*******************************************************************************/

// ջ��ʵ��

/*
// ջ�ĵײ�ṹ
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}ST;

// ��ʼ��ջ
void STInit(ST* pst);

// ����ջ������
void STDestory(ST* pst);

// ��ջ
void STPushTop(ST* pst, STDataType x);

// ��ջ
void STPopTop(ST* pst);

// ȡջ������
STDataType STGetTop(ST* pst);

// ��ȡջ����Ч���ݸ���
int STGetSize(ST* pst);

// �ж�ջ�������Ƿ�Ϊ 0
bool STEmpty(ST* pst);

// ��ӡջ�е�����
void STPrint(ST* pst);
*/

/*******************************************************************************/

// ���е�ʵ��

/*
// ���н���ʵ��
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

// ���нṹ��ʵ��
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

// ���еĳ�ʼ��
void QueueInit(Queue* pq);

// �����
void QueuePush(Queue* pq, QDataType x);

// ������
void QueuePop(Queue* pq);

// ȡ��ͷ������
QDataType QueueFront(Queue* pq);

// ȡ��β����
QDataType QueueBack(Queue* pq);

// ��ȡ�����е���Ч���ݸ���
int QueueGetSize(Queue* pq);

// �ж϶����е������Ƿ�Ϊ NULL
bool QueueEmpty(Queue* pq);

// ��ӡ�����е�����
void QueuePrint(Queue* pq);

// ���ٶ����е�����
void QueueDestory(Queue* pq);
*/
