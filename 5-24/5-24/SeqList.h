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

// 初始化
void SLInit(SL* psl);

// 扩容
void SLByCapacity(SL* psl);

// 头插
void SLPushFront(SL* psl, SLDateType x);

// 尾插
void SLPushBack(SL* psl, SLDateType x);

// 判断顺序表是否为空
bool SLEmpty(SL* psl);

// 头删
void SLPopFront(SL* psl);

// 尾删
void SLPopBack(SL* psl);

// 指定位置 pos 前插入数据
void SLInsertFront(SL* psl, int pos, SLDateType x);

// 指定位置 pos 后插入数据
void SLInsertBack(SL* psl, int pos, SLDateType x);

// 指定位置 pos 插入数据
void SLInsert(SL* psl, int pos, SLDateType x);

// 指定位置 pos 删除数据
void SLErase(SL* psl, int pos);

// 查找数据
SLDateType SLFind(SL* psl, SLDateType x);

// 打印
void SLPrint(SL* psl);

// 销毁
void SLDestory(SL* psl);