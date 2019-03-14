/*
 * Author:
 * Date: 2019-3-14
 * Description:
*/
#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T> &vecT)
{
	T tmp;
	int count = vecT.size();
    if(count <= 0)
    {
        return ;
    }

	for (int i = 0; i < count; ++i)
	{
		for (int j = count - 1; j >= i; j--){
			if (vecT[j] < vecT[j - 1]){
				tmp = vecT[j];
				vecT[j] = vecT[j - 1];
				vecT[j - 1] = tmp;
			}
		}
	}
}

template <typename T>
void insertSort(std::vector<T> &vecT)
{
    T flag;
    int count = vecT.size();
    if(count <= 0)
    {
        return ;
    }

	for (int i = 0; i < count; ++i)
    {
		flag = vecT[i];
		for (int j = i - 1; (j >= 0) && (flag < vecT[j]); ++j)//Find the position of insertation
        {  
			vecT[j + 1] = vecT[j];
		}
		vecT[j + 1] = flag;
	}
}

template <typename T>
void selectSort(std::vector<T> &vecT)
{
    //Exchange with the smallest item in every round.
    int count = vecT.size();
	T min = vecT[0], tmp;
	int index;
	for (int i = 0; i < count; ++i){
		min = vecT[i]; //Initial the min
		index = i;  //Initial the index of the min
		for (int j = i; j < count; ++j){
			if (min > vecT[j]){  //Find the min
				min = vecT[j];
				index = j;  //Get the index of the min
			}
		}
		tmp = vecT[i];   //Exchange the min and the vecT[i];
		vecT[i] = vecT[index];
		vecT[index] = tmp;
	}
}


#endif