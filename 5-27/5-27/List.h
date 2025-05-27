#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 双链表的结构
typedef int LTDateType;
typedef struct ListNode
{
	LTDateType val;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

// 创建新结点
LTNode* LTCreateNode(LTDateType x);

// 头插
void LTPushFront(LTNode* phead, LTDateType x);

// 尾插
void LTPushBack(LTNode* phead, LTDateType x);

// 头删
void LTPopFront(LTNode* phead);

// 尾删
void LTPopBack(LTNode* phead);

// 指定位置 pos 前插入数据
void LTInsertFront(LTNode* pos, LTDateType x);

// 指定位置 pos 后插入数据
void LTInsertBack(LTNode* pos, LTDateType x);

// 删除指定位置 pos 的数据
void LTErase(LTNode* pos);

// 查找数据
LTNode* LTFind(LTNode* phead, LTDateType x);

// 判断链表是否为空，即是否只有一个头结点
bool LTEmpty(LTNode* phead);

// 打印链表
void LTPrint(LTNode* phead);

// 销毁链表的数据
LTNode* LTDestory(LTNode* phead);