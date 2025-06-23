//��ʽ�ṹ�Ķ�����
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//������ʽ�ṹ�Ķ�����
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data; //�洢������
	struct BinaryTreeNode* left; //ָ�����ӽ���ָ��
	struct BinaryTreeNode* right;//ָ���Һ��ӽ���ָ��
}BTNode;

//�������
BTNode* BTBuyNode(char x)
{
	//�����ϵͬ�����ڴ�
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;

	return newnode;
}

//����һ��������
BTNode* CreateBinaryTree()
{
	//�������
	BTNode* nodeA = BTBuyNode('A');
	BTNode* nodeB = BTBuyNode('B');
	BTNode* nodeC = BTBuyNode('C');
	BTNode* nodeD = BTBuyNode('D');
	BTNode* nodeE = BTBuyNode('E');
	BTNode* nodeF = BTBuyNode('F');

	//���ӽ�� --- ����������ͼ������˳������
	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;

	//���ظ����ĵ�ַ
	return nodeA;
}

//ǰ����� --- ������
void BTPreOrder(BTNode* root)
{
	//���Ϊ��,��ӡNULL
	if (root == NULL)
	{
		printf("NULL ");
		//�������κ����͵�ֵ
		return;
	}
	//��ӡ��������洢������
	printf("%c ", root->data);
	//�ݹ��������
	BTPreOrder(root->left);
	//�ݹ�����ҽ��
	BTPreOrder(root->right);
}

//������� --- �����
void BTInOrder(BTNode* root)
{
	//���Ϊ�գ���ӡNULL
	if (root == NULL)
	{
		printf("NULL ");
		//�������κ����͵�ֵ
		return;
	}
	//�ݹ��������
	BTInOrder(root->left);
	//��ӡ����е�����
	printf("%c ", root->data);
	//�ݹ�����ҽ��
	BTInOrder(root->right);
}

//������� --- ���Ҹ�
void BTPostOrder(BTNode* root)
{
	//���Ϊ�գ���ӡNULL
	if (root == NULL)
	{
		printf("NULL ");
		//�������κ����͵�ֵ
		return;
	}
	//�ݹ��������
	BTPostOrder(root->left);
	//�ݹ�����ҽ��
	BTPostOrder(root->right);
	//��ӡ����е�����
	printf("%c ", root->data);
}

//����������ĸ���
//�õݹ�ʵ��
int BinaryTreeSize(BTNode* root)
{
	////���Ϊ�շ���0
	if (root == NULL)
	{
		return 0;
	}
	//���ǿ�
	//���������ĸ��� = 1 + ���������ĸ��� + ���������ĸ���
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}