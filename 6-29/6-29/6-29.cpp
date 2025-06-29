#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ֱ�Ӳ�������
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;

		int tmp = arr[end + 1];

		//ѭ���Ƚ�
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

//ϣ������
void ShellSort(int* arr, int n)
{
	int gap = n;

	while (gap > 1)
	{
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

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//ѡ������
void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		int min = begin;
		int max = begin;

		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}

		if (max == begin)
		{
			max = min;
		}

		Swap(&arr[begin], &arr[min]);
		Swap(&arr[end], &arr[max]);

		begin++;
		end--;
	}
}

//�鲢����
void MergeMid(int* arr, int left, int right, int* tmp)
{
	//�ݹ����ֹ����
	if (left >= right)
	{
		return;
	}

	//�ֽ�
	int mid = left + (right - left) / 2;

	MergeMid(arr, left, mid, tmp);
	MergeMid(arr, mid + 1, right, tmp);

	int begin = left;
	int end = mid;
	int rev = mid + 1;
	int cur = right;

	int index = left;

	while (begin <= end && rev <= cur)
	{
		if (arr[begin] < arr[rev])
		{
			tmp[index++] = arr[begin++];
		}
		else
		{
			tmp[index++] = arr[rev++];
		}
	}

	while (begin <= end)
	{
		tmp[index++] = arr[begin++];
	}

	while (rev <= cur)
	{
		tmp[index++] = arr[rev++];
	}

	memcpy(arr, tmp, sizeof(int) * (right + 1));
}

void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}

	MergeMid(arr, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}
