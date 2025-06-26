#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// ������Ľṹ
typedef int SLTDateType;

typedef struct SLTNode
{
	SLTDateType val;
	struct SLTNode* next;
}SLTNode;

// ͷ��
void SLTPushFront(SLTNode** pphead, SLTDateType x);

// β��
void SLTPushBack(SLTNode** pphead, SLTDateType x);

// ͷɾ
void SLTPopFront(SLTNode** pphead);

// βɾ
void SLTPopBack(SLTNode** pphead);

// ��ָ��λ�� pos ǰ��������
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDateType x);

// ��ָ��λ�� pos ���������
void SLTInsertBack(SLTNode* pos, SLTDateType x);

// ��ָ��λ�� pos ɾ������
void SLTErase(SLTNode** pphead, SLTNode* pos);

// ��ӡ
void SLTPrint(SLTNode* phead);

// ���ҽ��
SLTNode* SLTFind(SLTNode* phead, SLTDateType x);

// ����
void SLTDestory(SLTNode** pphead);