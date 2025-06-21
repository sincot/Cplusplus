#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//定义堆的结构
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;    
	int size;           
	int capacity;       
}HP;

//堆的初始化
void HeapInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//交换数据
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//向上调整算法
void AdjustUp(HPDataType* arr, int child)
{
	while (child > 0)
	{
		int parent = (child - 1) / 2;

		//建小堆：大的数据往下放，小的数据往上放，即arr[child] < arr[parent]时，需要调整
		//建大堆：大的数据往上放，小堆数据往下放，即arr[child] > arr[parent]时，需要调整
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);

			//继续往上调整
			child = parent;
		}
		else
		{
			break;
		}
	}
}

//向下调整算法
void AdjustDown(HPDataType* arr, int parent, int n)
{
	int child = 2 * parent + 1;

	//只要child不越界，就不会停止调整
	while (child < n)
	{
		//建小堆：求取父结点的子结点中值为最小的 即 arr[child] > arr[child + 1]
		//建大堆：求取父结点的子结点中值为最大的 即 arr[child] < arr[child + 1]
		//万一某个父结点只有一个孩子结点呢？那么child + 1后就会越界，所以需要特别处理
		if (child + 1 < n && arr[child] > arr[child + 1])
		{
			child++;
		}

		//将下标为child的结点与下标为parent的结点的值进行比较
		//建小堆：大的数据往下放，小的数据往上放，即arr[child] < arr[parent]时，需要调整
		//建大堆：大的数据往上放，小堆数据往下放，即arr[child] > arr[parent]时，需要调整
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);

			//继续向下调整
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

//往堆中插入数据
void HeapPush(HP* php, HPDataType x)
{
	//堆的地址不能为空
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;

		HP* tmp = (HP*)realloc(php->arr, sizeof(HP) * newcapacity);

		//判断内存是否开辟成功
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}

		php->arr = tmp;
		php->capacity = newcapacity;
	}

	//将数据x插入堆中
	php->arr[php->size] = x;

	//向上调整算法
	AdjustUp(php->arr, php->size);

	//最后有效数据个数size要++
	php->size++;
}

//判断堆中的数据是否为空
bool HeapEmpty(HP* php)
{
	//堆的地址不能为空
	assert(php);

	//当有效数据个数size等于0时，可以表明堆中的数据为空
	return php->size == 0;
}

//出堆 --- 出堆顶的数据
void HeapPop(HP* php)
{
	//判断堆中的元素是否为空
	assert(!HeapEmpty(php));

	Swap(&php->arr[0], &php->arr[php->size - 1]);

	php->size--;

	AdjustDown(php->arr, 0, php->size);
}

//取堆顶数据
HPDataType HeapTop(HP* php)
{
	//堆中的有效数据个数不能为0
	assert(!HeapEmpty(php));

	return php->arr[0];
}

//销毁堆中的数据
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
