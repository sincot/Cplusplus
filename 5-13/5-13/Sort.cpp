#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//直接插入排序
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];

		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}

		arr[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		// 分成 gap 组
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];

			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			arr[end + gap] = tmp;
		}
	}
}

// 直接选择排序
void SelectSort(int* arr, int n)
{
	int front = 0;
	int rear = n - 1;
	
	while (front < rear)
	{
		//找现区间中的最大值和最小值
		int mini = front;
		int maxi = front;

		// 控制选择排序区间
		for (int i = front + 1; i <= rear; i++)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}

		if (maxi == front)
		{
			maxi = mini;
		}

		Swap(&arr[front], &arr[mini]);
		Swap(&arr[rear], &arr[maxi]);

		// 缩小选择排序的区间
		front++;
		rear--;
	}
}

// 冒泡排序
void BubbleSort(int* arr, int n)
{
	// 趟数
	for (int i = 0; i < n; i++)
	{
		// 每趟交换的次数
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int main()
{
	int arr[] = { 7, 4, 5, 1, 2, 9, 3, 8, 0, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//InsertSort(arr, size);     // —— 直接插入排序
	//ShellSort(arr, size);      // —— 希尔排序
	//SelectSort(arr, size);     // —— 直接选择排序  
	//BubbleSort(arr, size);     // —— 冒泡排序

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}