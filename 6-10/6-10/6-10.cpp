#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


//����ѵĽṹ
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;    //��ʹ��������ʵ�ֵ�
	int size;           //��Ч���ݸ���
	int capacity;       //�ڴ�ռ�Ĵ�С
}HP;

//�ѵĳ�ʼ��
void HeapInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//��������
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//���ϵ����㷨
void AdjustUp(HPDataType* arr, int child)
{
	//���ϵ����ϵ�����ֱ��child�ߵ������ʱ����ֹͣ����
	while (child > 0)
	{
		//��֪���ӽ����±꣬���丸�����±�
		//�������±� = �� ���ӽ����±� - 1 �� /  2
		int parent = (child - 1) / 2;

		//��С�ѣ�����������·ţ�С���������Ϸţ���arr[child] < arr[parent]ʱ����Ҫ����
		//����ѣ�����������Ϸţ�С���������·ţ���arr[child] > arr[parent]ʱ����Ҫ����
		if (arr[child] < arr[parent])
		{
			//���ӽ����������丸�������ݽ��н���
			Swap(&arr[child], &arr[parent]);

			//�������ϵ���
			child = parent;
		}
		else
		{
			break;
		}
	}
}

//���µ����㷨
void AdjustDown(HPDataType* arr, int parent, int n)
{
	//�ɸ������±������ӽ����±�
	//�ӽ����±� = �� �丸�����±� - 1 ��/ 2
	int child = 2 * parent + 1;

	//ֻҪchild��Խ�磬�Ͳ���ֹͣ����
	while (child < n)
	{
		//��С�ѣ���ȡ�������ӽ����ֵΪ��С�� �� arr[child] > arr[child + 1]
		//����ѣ���ȡ�������ӽ����ֵΪ���� �� arr[child] < arr[child + 1]
		//��һĳ�������ֻ��һ�����ӽ���أ���ôchild + 1��ͻ�Խ�磬������Ҫ�ر���
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}

		//���±�Ϊchild�Ľ�����±�Ϊparent�Ľ���ֵ���бȽ�
		//��С�ѣ�����������·ţ�С���������Ϸţ���arr[child] < arr[parent]ʱ����Ҫ����
		//����ѣ�����������Ϸţ�С���������·ţ���arr[child] > arr[parent]ʱ����Ҫ����
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);

			//�������µ���
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

//�����в�������
void HeapPush(HP* php, HPDataType x)
{
	//�ѵĵ�ַ����Ϊ��
	assert(php);

	//�ж϶��Ƿ���Ҫ����
	//����жϣ�����Ч���ݸ���size�����ڴ�ռ�Ĵ�Сcapacityʱ����Ҫ����
	if (php->size == php->capacity)
	{
		//�ж�capacity�Ƿ�Ϊ0
		//��Ϊ0����ֵΪ4������Ϊ0����ֵΪԭ��������
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;

		//Ϊ���鿪��newcapcity����СΪsizeof(HP)���ڴ�ռ�
		HP* tmp = (HP*)realloc(php->arr, sizeof(HP) * newcapacity);

		//�ж��ڴ��Ƿ񿪱ٳɹ�
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}

		php->arr = tmp;
		php->capacity = newcapacity;
	}

	//������x�������
	php->arr[php->size] = x;

	//���ϵ����㷨
	AdjustUp(php->arr, php->size);

	//�����Ч���ݸ���sizeҪ++
	php->size++;
}

//�ж϶��е������Ƿ�Ϊ��
bool HeapEmpty(HP* php)
{
	//�ѵĵ�ַ����Ϊ��
	assert(php);

	//����Ч���ݸ���size����0ʱ�����Ա������е�����Ϊ��
	return php->size == 0;
}

//���� --- ���Ѷ�������
void HeapPop(HP* php)
{
	//�ж϶��е�Ԫ���Ƿ�Ϊ��
	assert(!HeapEmpty(php));

	//���Ѷ����������β�����ݽ��н���
	Swap(&php->arr[0], &php->arr[php->size - 1]);

	//������Ϻ��ٽ���Ч���ݸ�����1�����ɽ��Ѷ�������ɾ��
	php->size--;

	//���µ����㷨��ʹ�Ƕѽṹ��Ϊ�ѽṹ
	//��������в��������Բ�����arr
	//���������µ����������ǴӸ����Ŀ�ʼ������Ҫ֪���������±�
	//��Ҫ֪��������Ч���ݸ������ܱ���Խ�����
	AdjustDown(php->arr, 0, php->size);
}

//ȡ�Ѷ�����
HPDataType HeapTop(HP* php)
{
	//���е���Ч���ݸ�������Ϊ0
	assert(!HeapEmpty(php));

	//ֱ�ӽ������±�Ϊ0�Ľ���ֵ����
	return php->arr[0];
}

//���ٶ��е�����
void HeapDestory(HP* php)
{
	assert(php);
	if (php->arr)
	{
		free(php->arr);
		php->arr = NULL;
	}
	php->size = php->capacity = 0;
}

int main()
{
	HP hp;
	HeapInit(&hp);

	HeapPush(&hp, 5);
	HeapPush(&hp, 20);
	HeapPush(&hp, 10);
	HeapPush(&hp, 25);
	HeapPush(&hp, 27);
	HeapPush(&hp, 30);
	HPDataType top = HeapTop(&hp);
	printf("%d ", top);

	return 0;
}
