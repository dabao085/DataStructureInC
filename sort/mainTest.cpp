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
    Sort<int> iSort(ivec);
    iSort.bubbleSort();
    
    for(const auto &a : ivec)
        cout << a << " ";
    cout << endl;
    return 0;
}