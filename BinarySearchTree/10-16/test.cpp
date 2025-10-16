#include "BinarySearchTree.h"
#include <string>

int main()
{
	//int arr[] = { 8,3,1,10,6,4,7,14,13 };
	//// 实例化二叉搜索树
	//BSTree<int> bst;

	//// 将 arr 中的值插入至 bst
	//for (auto e : arr)
	//{
	//	bst.Insert(e);
	//}

	//// 遍历
	//bst.InOrder();

	//// 删除 8
	//bst.Erase(8);
	//bst.InOrder();

	//// 删除 6
	//bst.Erase(6);
	//bst.InOrder();

	// 使用 key/value 二叉搜索树
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", 
		             "西瓜", "苹果", "香蕉", "苹果","香蕉" };
	AY::BSTree<string, int> bst;
	for (auto& e : arr)
	{
		auto pNode = bst.Find(e);
		if (pNode == nullptr)
		{
			bst.Insert(e, 1);
		}
		else
		{
			pNode->_value++;
		}
	}

	bst.InOrder();

	return 0;
}