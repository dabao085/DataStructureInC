/*Insert Sort:每次取出一个元素，将其插入前面已排好序的部分中。
 *使用一个flag存放需要排序的元素。
 *
 */
#include <iostream>
#define LEN 10
using namespace std;

void InsertSort(int *pData,int count){
	int i, j;
	int flag;
	for (i = 0; i < count; i++){
		flag = pData[i];
		for (j = i - 1; j >= 0 && flag < pData[j]; j--){  //Find the position of insertation
			pData[j + 1] = pData[j];
		}
		pData[j + 1] = flag;
	}
}

void print(int *pData, int count){
	for (int i = 0; i < count; i++)
		cout << *(pData + i) << " ";
	cout << endl;
}

int main(){
	int a[LEN] = { 2, 1, 4, 3, 5, 6, 7, 0, 9, 8 };
	InsertSort(a, LEN);
	print(a, LEN);
	return 0;
}
