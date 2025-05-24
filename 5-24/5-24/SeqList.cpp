#include "SeqList.h"

// ��ʼ��
void SLInit(SL* psl)
{
	psl->arr = NULL;
	psl->size = psl->capacity = 0;
}

// ����
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

// ͷ��
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

// β��
void SLPushBack(SL* psl, SLDateType x)
{
	assert(psl);
	SLByCapacity(psl);
	psl->arr[psl->size++] = x;
}

// �ж�˳����Ƿ�Ϊ��
bool SLEmpty(SL* psl)
{
	assert(psl);
	return psl->size == 0;
}

// ͷɾ
void SLPopFront(SL* psl)
{
	assert(!SLEmpty(psl));
	for (int i = 0; i < psl->size - 1; i++)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	psl->size--;
}

// βɾ
void SLPopBack(SL* psl)
{
	assert(!SLEmpty(psl));
	psl->size--;
}

// ָ��λ�� pos ǰ��������
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

// ָ��λ�� pos ���������
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

// ָ��λ�� pos ��������
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

// ָ��λ�� pos ɾ������
void SLErase(SL* psl, int pos)
{
	assert(!SLEmpty(psl) && pos <= psl->size);
	for (int i = pos; i < psl->size - 1; i++)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	psl->size--;
}

// ��������
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

// ��ӡ
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}

// ����
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