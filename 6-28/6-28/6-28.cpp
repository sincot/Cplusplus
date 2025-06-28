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
	// 选取gap
	int gap = n;

	while (gap > 1)
	{
		// 分组
		gap = gap / 3 + 1;

		// 组内排序
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];

			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					// 赋值
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
		// right 找比基准值小的数
		while (left <= right && arr[right] > arr[key])
		{
			right--;
		}

		// left 找比基准值大的数
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

// 快速排序
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
	printf("排序前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	//ShellSort(arr, size);
	QuickSort(arr, 0, size - 1);

	printf("排序后：");
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

// 实现链式结构二叉树
typedef char BTDataType;
typedef struct BTNode
{
	BTDataType data;
	struct BTNode* leftChild;
	struct BTNode* rightChild;
}BTNode;

//为结点开辟内存空间
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

// 构造二叉树
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

// 前序遍历
void BTPreOrder(BTNode* root)
{
	// 递归的终止条件
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// 根左右
	printf("%c ", root->data);

	BTPreOrder(root->leftChild);
	BTPreOrder(root->rightChild);
}

// 中序遍历
void BTInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// 左根右
	BTInOrder(root->leftChild);
	printf("%c ", root->data);
	BTInOrder(root->rightChild);
}

// 后序遍历
void BTPostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	// 左右根
	BTPostOrder(root->leftChild);
	BTPostOrder(root->rightChild);
	printf("%c ", root->data);
}

// 实现队列的结点结构
typedef int QDataType;
typedef struct QueueNode
{
	// 与队列中的不同
	BTNode* data;
	struct QueueNode* next;
}QueueNode;

// 实现队列的结构
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

// 初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
}

// 入队列
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

// 判断队列中的数据是否为 0
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->phead == NULL;
}

// 出队列
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));

	QueueNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
}

// 取队头的数据
BTNode* QueueTop(Queue* pq)
{
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

// 层序遍历
void BTLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	// 入队列
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		// 取队头的数据
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

// 二叉树结点的个数
int BTNodeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BTNodeSize(root->leftChild) + BTNodeSize(root->rightChild);
}

// 二叉树叶子结点的个数
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

// 二叉树的深度/高度
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

// 查找值为 x 的结点
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

// 销毁二叉树中的数据 —— 后序遍历
void BTDestory(BTNode** proot)
{
	if (*proot == NULL)
	{
		return;
	}

	// 左右根
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