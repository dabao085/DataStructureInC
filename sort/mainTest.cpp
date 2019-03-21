/*
 * Author: Chengx
 * Date: 2019-3-21
 * Description:
*/
#include "sort.h"
using namespace std;

int main()
{
    vector<int> ivec = {9,7,5,3,1,8,6,4,2};
    cout << "before sort: " << endl;
    Sort<int> iSort1(ivec);
    iSort1.bubbleSort();
    cout << "after sort: " << endl;
    for(const auto &a : ivec)
        cout << a << " ";
    cout << endl;

    cout << "before sort: " << endl;
    Sort<int> iSort2({9,7,5,3,1,8,6,4,2});
    iSort2.bubbleSort();
    cout << "after sort: " << endl;
    iSort2.printValues();

    return 0;
}