#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int SLDateType;
typedef struct SeqList
{
	int* arr;
	int size;
	int capacity;
}SL;

// ��ʼ��
void SLInit(SL* psl);

// ����
void SLByCapacity(SL* psl);

// ͷ��
void SLPushFront(SL* psl, SLDateType x);

// β��
void SLPushBack(SL* psl, SLDateType x);

// �ж�˳����Ƿ�Ϊ��
bool SLEmpty(SL* psl);

// ͷɾ
void SLPopFront(SL* psl);

// βɾ
void SLPopBack(SL* psl);

// ָ��λ�� pos ǰ��������
void SLInsertFront(SL* psl, int pos, SLDateType x);

// ָ��λ�� pos ���������
void SLInsertBack(SL* psl, int pos, SLDateType x);

// ָ��λ�� pos ��������
void SLInsert(SL* psl, int pos, SLDateType x);

// ָ��λ�� pos ɾ������
void SLErase(SL* psl, int pos);

// ��������
SLDateType SLFind(SL* psl, SLDateType x);

// ��ӡ
void SLPrint(SL* psl);

// ����
void SLDestory(SL* psl);