// 排序

#include <stdio.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

// hoare 版本的快速排序
int QuickHoare(int* arr, int front, int rear)
{
	// 定义基准值
	int keyi = front;
	// 改变当前 front 的指向
	front++;

	// 分组找基准值 —— 循环
	while (front <= rear)
	{
		// right —— 从右往左找比基准值小的
		while (arr[rear] > arr[keyi] && front <= rear)
		{
			rear--;
		}
		// left —— 从左往右找比基准值大的
		while (arr[front] < arr[keyi] && front <= rear)
		{
			front++;
		}

		// 交换
		if (front <= rear)
		{
			Swap(&arr[front], &arr[rear]);
			front++;
			rear--;
		}
	}

	Swap(&arr[keyi], &arr[rear]);

	return rear;
}

// Lomuto 双指针法
void QuickLomuto(int* arr, int left, int right)
{

}
void QuickSort(int* arr, int left, int right)
{
	// 判断在当前的范围内是否能够找到基准值，即范围是否合法
	if (left >= right)
	{
		return;
	}

	// 找基准值
	int keyi = QuickHoare(arr, left, right);

	// 递归左子序列 —— 范围 [ left, keyi - 1 ]
	QuickSort(arr, left, keyi - 1);
	
	// 递归右子序列 —— 范围 [ keyi + 1, right ]
	QuickSort(arr, keyi + 1, right);
}

int main()
{
	int arr[] = { 4, 7, 5, 3, 6, 2, 9, 0, 1, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//QuickSort(arr, 0, size - 1); // hoare 版本

	printf("排序后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}