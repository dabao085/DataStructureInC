/*
 * Author: Cheng xiang
 * Date: 2019-2-25
 * test binary search tree
*/

#include "binarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(0);
    bst.insert(2);

    cout << bst.findMin() << endl;
    cout << bst.findMax() << endl;

    return 0;
}