#include "SeqList.h"

// 初始化
void SLInit(SL* psl)
{
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}

// 扩容
void SLByCapacity(SL* psl)
{
	if (psl->size == psl->capacity)
	{
		int newcapacity = psl->capacity == 0 ? 4 : 2 * psl->capacity;
		SLDateType* tmp = (SLDateType*)realloc(psl->arr, sizeof(SLDateType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc fail!");
			exit(1);
		}

		psl->arr = tmp;
		psl->capacity = newcapacity;
	}
}

// 头插
void SLPushFront(SL* psl, SLDateType x)
{
	assert(psl);
	SLByCapacity(psl);
	
	for (int i = psl->size; i > 0; i--)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[0] = x;
	psl->size++;
}

// 尾插
void SLPushBack(SL* psl, SLDateType x)
{
	assert(psl);
	SLByCapacity(psl);
	psl->arr[psl->size++] = x;
}

// 判断顺序表是否为空
bool SLEmpty(SL* psl)
{
	assert(psl);
	return psl->size == 0;
}

// 头删
void SLPopFront(SL* psl)
{
	assert(!SLEmpty(psl));
	for (int i = 0; i < psl->size - 1; i++)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	psl->size--;
}

// 尾删
void SLPopBack(SL* psl)
{
	assert(!SLEmpty(psl));
	psl->size--;
}

// 指定位置 pos 前插入数据
void SLInsertFront(SL* psl, int pos, SLDateType x)
{
	assert(psl && pos <= psl->size);
	SLByCapacity(psl);

	for (int i = psl->size; i > pos - 1; i--)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[pos - 1] = x;
	psl->size++;
}

// 指定位置 pos 后插入数据
void SLInsertBack(SL* psl, int pos, SLDateType x)
{
	assert(psl && pos < psl->size);
	SLByCapacity(psl);

	for (int i = psl->size; i > pos; i--)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[pos + 1] = x;
	psl->size++;
}

// 指定位置 pos 插入数据
void SLInsert(SL* psl, int pos, SLDateType x)
{
	assert(psl && pos < psl->size);
	SLByCapacity(psl);

	for (int i = psl->size; i > pos; i--)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[pos] = x;
	psl->size++;
}

// 指定位置 pos 删除数据
void SLErase(SL* psl, int pos)
{
	assert(!SLEmpty(psl) && pos <= psl->size);
	for (int i = pos; i < psl->size - 1; i++)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	psl->size--;
}

// 查找数据
SLDateType SLFind(SL* psl, SLDateType x)
{
	assert(!SLEmpty(psl));
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// 打印
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}

// 销毁
void SLDestory(SL* psl)
{
	assert(psl);
	if (psl->arr != NULL)
	{
		free(psl->arr);
		psl->arr = NULL;
	}

	psl->size = psl->capacity = 0;
	psl = NULL;
}