#include <iostream>
#define LEN 10
using namespace std;

void BubbleSort(int *pData, int count){ 
	int tmp;
	for (int i = 1; i < count; i++)
		for (int j = count - 1; j >= i; j--){
			if (pData[j] < pData[j - 1]){
				tmp = pData[j];
				pData[j] = pData[j - 1];
				pData[j - 1] = tmp;
			}
		}
}

void print(int *pData,int count){
	for (int i = 0; i < count; i++)
		cout << *(pData + i) << " ";
	cout << endl;
}

int main(){
	int a[LEN] = {2,1,4,3,5,6,9,0,8,7};
	BubbleSort(a, LEN);
	print(a,LEN);
	return 0;
}
