/*
 * Author: Chengx
 * Date: 2019-3-14
 * Description:
*/
#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <vector>

template <typename T>
class Sort
{
public:
	Sort(std::vector<T> &values) : m_values(values)//如何复制效率高?
	{}

	void bubbleSort()
	{
		T tmp;
		int count = m_values.size();
		if(count <= 0)
		{
			return ;
		}

		for (int i = 0; i < count; ++i)
		{
			for (int j = count - 1; j >= i; j--){
				if (m_values[j] < m_values[j - 1]){
					tmp = m_values[j];
					m_values[j] = m_values[j - 1];
					m_values[j - 1] = tmp;
				}
			}
		}
	}
	void insertSort()
	{
		T flag;
		int count = m_values.size();
		if(count == 0)
		{
			return ;
		}

		for (int i = 1; i < count; ++i)//第一个值默认有序
		{
			flag = m_values[i];
			int j = i;
			for (; (j > 0) && (flag < m_values[j]); --j)//Find the position of insertation
			{  
				m_values[j] = m_values[j - 1];
			}
			m_values[j] = flag;
		}
	}
	void selectSort()
	{
		//Exchange with the smallest item in every round.
		int count = m_values.size();
		if(count <= 0)
		{
			return ;
		}

		T min = m_values[0], tmp;
		int index;
		for (int i = 0; i < count; ++i)
		{
			min = m_values[i]; //Initial the min
			index = i;  //Initial the index of the min
			for (int j = i; j < count; ++j)
			{
				if (min > m_values[j]){  //Find the min
					min = m_values[j];
					index = j;  //Get the index of the min
				}
			}
			tmp = m_values[i];   //Exchange the min and the vecT[i];
			m_values[i] = m_values[index];
			m_values[index] = tmp;
		}
	}
	void heapSort();
	void shellSort()
	{
		int count = m_values.size();
		if(count == 0)
		{
			return ;
		}

		for(int gap = count / 2; gap > 0; gap /= 2)
		{
			for(int i = gap; i < count; ++i)
			{
				T tmp = m_values[i];
				int j = i;
				for(; j >= gap && tmp < m_values[j - gap]; j -= gap)
				{
					m_values[j] = m_values[j - gap];
				}
				m_values[j] = tmp;
			}
		}
	}
	void mergeSort();
	void quickSort();
	//void externalSort();
private:
private:
	std::vector<T> &m_values;
};

#endif