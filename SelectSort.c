/*
*选择排序：每次未排序中的最小元素，进行插入
*/

#include <iostream>
#define LEN 10
using namespace std;

void print(int *pData, int count){
	for (int i = 0; i < count; i++)
		cout << *(pData + i) << " ";
	cout << endl;
}

void SelectSort(int *pData, int count){
	//Exchange with the smallest item in every round.
	int min = *pData;
	int tmp;
	int index;
	for (int i = 0; i < count; i++){
		min = pData[i]; //Initial the min
		index = i;  //Initial the index of the min
		for (int j = i; j < count; j++){
			if (min>pData[j]){  //Find the min
				min = pData[j];
				index = j;  //Get the index of the min
			}
		}
		tmp = pData[i];   //Exchange the min and the pData[i];
		pData[i] = pData[index];
		pData[index] = tmp;
	}
}

int main(){
	int a[LEN] = { 2, 1, 4, 3, 5, 6, 7, 0, 9, 8 };
	SelectSort(a, LEN);
	print(a, LEN);

	return 0;
}
