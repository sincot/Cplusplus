#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 递归版本
void Merge(int* arr, int left, int right, int* tmp)
{
	// 判断区间是否合法
	if (left >= right)
	{
		return;
	}

	int mid = left + (right - left) / 2;

	// [ left mid ]      [ mid+1 right ]
	// 递归
	Merge(arr, left, mid, tmp);
	Merge(arr, mid + 1, right, tmp);

	// 合并两个序列序列
	// 保存原来的区间范围
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int index = begin1;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}

	// 没有合并完
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}
}

// 计数排序
void CountSort(int* arr, int n)
{
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	int* count = (int*)malloc(sizeof(int) * (max - min + 1));
	if (count == NULL)
	{
		exit(1);
	}

	for (int i = 0; i < max - min + 1; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}

	// 还原
	int index = 0;
	for (int i = 0; i < max - min + 1; i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}

	free(count);
	count = NULL;
}

// 归并排序
void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	Merge(arr, 0, n - 1, tmp);
}

int main()
{
	int arr[] = { 4, 7, 2, 5, 8, 0, 1, 3, 9, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//MergeSort(arr, size);
	CountSort(arr, size);

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}