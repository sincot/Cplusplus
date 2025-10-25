#include "RBTree.h"

int main()
{
	RBTree<int, int> rbt;
    int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

    cout << "插入顺序: ";
    for (auto e : arr)
        cout << e << " ";
    cout << endl << endl;

    for (auto e : arr)
    {
        //cout << "插入 " << e << " 后: ";
        rbt.Insert({ e, e });
        //rbt.IsBalance();
        // t.InOrder();
        //cout << endl;
    }

    cout << "最终结果: " << endl;
    rbt.InOrder();
	return 0;
}