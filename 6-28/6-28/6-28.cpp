#include <stdio.h>

/*
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void ShellSort(int* arr, int n)
{
	// ѡȡgap
	int gap = n;

	while (gap > 1)
	{
		// ����
		gap = gap / 3 + 1;

		// ��������
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];

			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					// ��ֵ
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

int Lomuto(int* arr, int left, int right)
{
	int key = left;
	left += 1;

	while (left <= right)
	{
		// right �ұȻ�׼ֵС����
		while (left <= right && arr[right] > arr[key])
		{
			right--;
		}

		// left �ұȻ�׼ֵ�����
		while (left <= right && arr[left] < arr[key])
		{
			left++;
		}

		if (left <= right)
		{
			Swap(&arr[left++], &arr[right--]);
		}
	}

	Swap(&arr[key], &arr[right]);

	return right;
}

// ��������
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int key = Lomuto(arr, left, right);
	QuickSort(arr, left, key - 1);
	QuickSort(arr, key + 1, right);
}

int main()
{
	int arr[] = { 4, 7, 5, 9, 0, 2, 1, 6, 8, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����ǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	//ShellSort(arr, size);
	QuickSort(arr, 0, size - 1);

	printf("�����");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	ShellSort(arr, size);

	return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// ʵ����ʽ�ṹ������
typedef char BTDataType;
typedef struct BTNode
{
	BTDataType data;
	struct BTNode* leftChild;
	struct BTNode* rightChild;
}BTNode;

//Ϊ��㿪���ڴ�ռ�
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}

	newnode->data = x;
	newnode->leftChild = newnode->rightChild = NULL;

	return newnode;
}

// ���������
BTNode* CreateBinaryTree()
{
	BTNode* nodeA = BuyNode('A');
	BTNode* nodeB = BuyNode('B');
	BTNode* nodeC = BuyNode('C');
	BTNode* nodeD = BuyNode('D');
	BTNode* nodeE = BuyNode('E');
	BTNode* nodeF = BuyNode('F');
	BTNode* nodeG = BuyNode('G');

	nodeA->leftChild = nodeB;
	nodeA->rightChild = nodeC;
	nodeB->leftChild = nodeD;
	nodeC->leftChild = nodeE;
	nodeC->rightChild = nodeF;
	nodeE->leftChild = nodeG;

	return nodeA;
}

// ǰ�����
void BTPreOrder(BTNode* root)
{
	// �ݹ����ֹ����
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// ������
	printf("%c ", root->data);

	BTPreOrder(root->leftChild);
	BTPreOrder(root->rightChild);
}

// �������
void BTInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// �����
	BTInOrder(root->leftChild);
	printf("%c ", root->data);
	BTInOrder(root->rightChild);
}

// �������
void BTPostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// ���Ҹ�
	BTPostOrder(root->leftChild);
	BTPostOrder(root->rightChild);
	printf("%c ", root->data);
}

// ʵ�ֶ��еĽ��ṹ
typedef int QDataType;
typedef struct QueueNode
{
	// ������еĲ�ͬ
	BTNode* data;
	struct QueueNode* next;
}QueueNode;

// ʵ�ֶ��еĽṹ
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

// ��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}

// �����
void QueuePush(Queue* pq, BTNode* root)
{
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("newnode malloc fail!");
		return;
	}

	newnode->data = root;
	newnode->next = NULL;

	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}

// �ж϶����е������Ƿ�Ϊ 0
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->phead == NULL;
}

// ������
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));

	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

// ȡ��ͷ������
BTNode* QueueTop(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

// �������
void BTLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	// �����
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		// ȡ��ͷ������
		BTNode* top = QueueTop(&q);
		printf("%c ", top->data);
		QueuePop(&q);

		if (top->leftChild != NULL)
		{
			QueuePush(&q, top->leftChild);
		}

		if (top->rightChild != NULL)
		{
			QueuePush(&q, top->rightChild);
		}
	}
}

// ���������ĸ���
int BTNodeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BTNodeSize(root->leftChild) + BTNodeSize(root->rightChild);
}

// ������Ҷ�ӽ��ĸ���
int BTNodeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->leftChild == NULL && root->rightChild == NULL)
	{
		return 1;
	}

	return BTNodeLeafSize(root->leftChild)
		+ BTNodeLeafSize(root->rightChild);
}

int BTNodeLeafKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BTNodeLeafKSize(root->leftChild, k - 1)
		+ BTNodeLeafKSize(root->rightChild, k - 1);
}

// �����������/�߶�
int BTDeap(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftDeap = BTDeap(root->leftChild);
	int rightDeap = BTDeap(root->rightChild);

	return 1 + (leftDeap > rightDeap ? leftDeap : rightDeap);
}

// ����ֵΪ x �Ľ��
BTNode* BTFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode* pleft = BTFind(root->leftChild, x);
	if (pleft != NULL)
	{
		return pleft;
	}

	BTNode* pright = BTFind(root->rightChild, x);
	if (pright != NULL)
	{
		return pright;
	}

	return NULL;
}

// ���ٶ������е����� ���� �������
void BTDestory(BTNode** proot)
{
	if (*proot == NULL)
	{
		return;
	}

	// ���Ҹ�
	BTDestory(&((*proot)->leftChild));
	BTDestory(&((*proot)->rightChild));

	free(*proot);
	*proot = NULL;
}

int main()
{
	BTNode* root = CreateBinaryTree();

	//BTPreOrder(root);
	//BTInOrder(root);
	//BTPostOrder(root);
	//BTLevelOrder(root);
	//printf("%d ", BTNodeSize(root));
	//printf("%d ", BTNodeLeafSize(root));
	//printf("%d ", BTNodeLeafKSize(root, 3));
	//printf("%d ", BTDeap(root));
	BTNode* pfind = BTFind(root, 'H');
	printf("%p ", pfind);
}