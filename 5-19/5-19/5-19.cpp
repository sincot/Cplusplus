// ����

#include <stdio.h>

void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

// hoare �汾�Ŀ�������
int QuickHoare(int* arr, int front, int rear)
{
	// �����׼ֵ
	int keyi = front;
	// �ı䵱ǰ front ��ָ��
	front++;

	// �����һ�׼ֵ ���� ѭ��
	while (front <= rear)
	{
		// right ���� ���������ұȻ�׼ֵС��
		while (arr[rear] > arr[keyi] && front <= rear)
		{
			rear--;
		}
		// left ���� ���������ұȻ�׼ֵ���
		while (arr[front] < arr[keyi] && front <= rear)
		{
			front++;
		}

		// ����
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

// Lomuto ˫ָ�뷨
void QuickLomuto(int* arr, int left, int right)
{

}
void QuickSort(int* arr, int left, int right)
{
	// �ж��ڵ�ǰ�ķ�Χ���Ƿ��ܹ��ҵ���׼ֵ������Χ�Ƿ�Ϸ�
	if (left >= right)
	{
		return;
	}

	// �һ�׼ֵ
	int keyi = QuickHoare(arr, left, right);

	// �ݹ��������� ���� ��Χ [ left, keyi - 1 ]
	QuickSort(arr, left, keyi - 1);
	
	// �ݹ��������� ���� ��Χ [ keyi + 1, right ]
	QuickSort(arr, keyi + 1, right);
}

int main()
{
	int arr[] = { 4, 7, 5, 3, 6, 2, 9, 0, 1, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	//QuickSort(arr, 0, size - 1); // hoare �汾

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}