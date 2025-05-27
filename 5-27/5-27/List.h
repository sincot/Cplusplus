#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// ˫����Ľṹ
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType val;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

// �����½��
LTNode* LTCreateNode(LTDateType x);

// ͷ��
void LTPushFront(LTNode* phead, LTDateType x);

// β��
void LTPushBack(LTNode* phead, LTDateType x);

// ͷɾ
void LTPopFront(LTNode* phead);

// βɾ
void LTPopBack(LTNode* phead);

// ָ��λ�� pos ǰ��������
void LTInsertFront(LTNode* pos, LTDateType x);

// ָ��λ�� pos ���������
void LTInsertBack(LTNode* pos, LTDateType x);

// ɾ��ָ��λ�� pos ������
void LTErase(LTNode* pos);

// ��������
LTNode* LTFind(LTNode* phead, LTDateType x);

// �ж������Ƿ�Ϊ�գ����Ƿ�ֻ��һ��ͷ���
bool LTEmpty(LTNode* phead);

// ��ӡ����
void LTPrint(LTNode* phead);

// �������������
LTNode* LTDestory(LTNode* phead);