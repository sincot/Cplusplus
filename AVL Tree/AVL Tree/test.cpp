#include <iostream>
#include "AVL Tree.h"

using namespace std;

int main()
{
    // 插入最后一个数据的时，旋转出现了问题
    AVLTree<int, int> t;
    int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

    cout << "插入顺序: ";
    for (auto e : arr)
        cout << e << " ";
    cout << endl << endl;

    for (auto e : arr)
    {
        cout << "插入 " << e << " 后: ";
        t.Insert({ e, e });
       // t.InOrder();
        t.IsBalanceTree();
        cout << endl;
    }

    cout << "最终结果: ";
    t.InOrder();

    return 0;
}