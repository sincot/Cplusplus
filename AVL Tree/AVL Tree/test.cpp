#include <iostream>
#include "AVL Tree.h"

using namespace std;

int main()
{
    // �������һ�����ݵ�ʱ����ת����������
    AVLTree<int, int> t;
    int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

    cout << "����˳��: ";
    for (auto e : arr)
        cout << e << " ";
    cout << endl << endl;

    for (auto e : arr)
    {
        cout << "���� " << e << " ��: ";
        t.Insert({ e, e });
       // t.InOrder();
        t.IsBalanceTree();
        cout << endl;
    }

    cout << "���ս��: ";
    t.InOrder();

    return 0;
}