#include "RBTree.h"

int main()
{
	RBTree<int, int> rbt;
    int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

    cout << "����˳��: ";
    for (auto e : arr)
        cout << e << " ";
    cout << endl << endl;

    for (auto e : arr)
    {
        //cout << "���� " << e << " ��: ";
        rbt.Insert({ e, e });
        //rbt.IsBalance();
        // t.InOrder();
        //cout << endl;
    }

    cout << "���ս��: " << endl;
    rbt.InOrder();
	return 0;
}