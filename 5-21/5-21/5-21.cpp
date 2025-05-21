#include <stdio.h>
#include <stdlib.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int QuickLomuto(int* arr, int left, int right)
{
	int keyi = left;
	int rev = keyi;
	int cur = rev + 1;

	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && cur != ++rev)
		{
			Swap(&arr[rev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[keyi], &arr[rev]);

	return rev;
}

// ����֮��·����
void QuickSort(int* arr, int left, int right)
{
	// ��Χ�Ƿ���Ч
	if (left >= right)
	{
		return;
	}
	
	int begin = left;
	int end = right;

	int randi = left + (rand() % (right - left));
	Swap(&arr[left], &arr[randi]);

	int key = arr[left];
	int cur = left + 1;

	while (cur <= right)
	{
		if(arr[cur] < key)
		{
			Swap(&arr[cur], &arr[left]);
			cur++;
			left++;
		}
		else if (arr[cur] > key)
		{
			Swap(&arr[cur], &arr[right]);
			right--;
		}
		else
		{
			cur++;
		}
	}

	// �ݹ�
	QuickSort(arr, begin, left);
	QuickSort(arr, right + 1, end);
}

/*
void QuickSort(int* arr, int front, int rear)
{
	// ��Χ�Ƿ���Ч
	if (front >= rear)
	{
		return;
	}

	int keyi = QuickLomuto(arr, front, rear);

	// �ݹ�
	QuickSort(arr, front, keyi - 1);
	QuickSort(arr, keyi + 1, rear);
}
*/


int main()
{
	int arr[] = { 4, 7, 5, 7, 8, 3, 7, 2, 7, 9, 6, 1, 2, 4, 0, 4, 7, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	QuickSort(arr, 0, size - 1);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	/*
	int arr[] = { 4, 6, 3, 1, 0, 2, 9, 8, 5, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	QuickSort(arr, 0, size - 1);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	*/

	return 0;
}