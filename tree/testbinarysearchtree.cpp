/*
 * Author: Cheng xiang
 * Date: 2019-2-25
 * test binary search tree
*/

#include "binarySearchTree.h"
using namespace std;

void printMaxAndMin(const BinarySearchTree<int> &bst)
{
    cout << "min: " << bst.findMin() << endl;
    cout << "max: " << bst.findMax() << endl;
}

int main()
{
    BinarySearchTree<int> bst;
    cout << "insert 1, 0, 2" << endl;
    bst.insert(1);
    bst.insert(0);
    bst.insert(2);
    printMaxAndMin(bst);

    cout << "insert 5" << endl;
    bst.insert(5);
    printMaxAndMin(bst);

    cout << "remove 5" << endl;
    bst.remove(5);
    printMaxAndMin(bst);

    cout << "remove 1, 0" << endl;
    bst.remove(1);
    bst.remove(0);
    printMaxAndMin(bst);

    cout << "insert 3" << endl;
    bst.insert(3);
    printMaxAndMin(bst);

    cout << "remove 2, 3" << endl;
    bst.remove(2);
    bst.remove(3);
    //printMaxAndMin(bst);
    if(bst.isEmpty())
    {
        cout << "this binary search tree is empty!" << endl;
    }

    return 0;
}