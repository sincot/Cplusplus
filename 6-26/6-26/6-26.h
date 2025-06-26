#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 单链表的结构
typedef int SLTDateType;

typedef struct SLTNode
{
	SLTDateType val;
	struct SLTNode* next;
}SLTNode;

// 头插
void SLTPushFront(SLTNode** pphead, SLTDateType x);

// 尾插
void SLTPushBack(SLTNode** pphead, SLTDateType x);

// 头删
void SLTPopFront(SLTNode** pphead);

// 尾删
void SLTPopBack(SLTNode** pphead);

// 在指定位置 pos 前插入数据
void SLTInsertFront(SLTNode** pphead, SLTNode* pos, SLTDateType x);

// 在指定位置 pos 后插入数据
void SLTInsertBack(SLTNode* pos, SLTDateType x);

// 在指定位置 pos 删除数据
void SLTErase(SLTNode** pphead, SLTNode* pos);

// 打印
void SLTPrint(SLTNode* phead);

// 查找结点
SLTNode* SLTFind(SLTNode* phead, SLTDateType x);

// 销毁
void SLTDestory(SLTNode** pphead);