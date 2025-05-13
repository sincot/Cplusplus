#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//ֱ�Ӳ�������
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

// ϣ������
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		// �ֳ� gap ��
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

// ֱ��ѡ������
void SelectSort(int* arr, int n)
{
	int front = 0;
	int rear = n - 1;
	
	while (front < rear)
	{
		//���������е����ֵ����Сֵ
		int mini = front;
		int maxi = front;

		// ����ѡ����������
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

		// ��Сѡ�����������
		front++;
		rear--;
	}
}

// ð������
void BubbleSort(int* arr, int n)
{
	// ����
	for (int i = 0; i < n; i++)
	{
		// ÿ�˽����Ĵ���
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
	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//InsertSort(arr, size);     // ���� ֱ�Ӳ�������
	//ShellSort(arr, size);      // ���� ϣ������
	//SelectSort(arr, size);     // ���� ֱ��ѡ������  
	//BubbleSort(arr, size);     // ���� ð������

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}