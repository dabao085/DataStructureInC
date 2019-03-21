/*
 * Author: Chengx
 * Date: 2019-3-14
 * Description:
*/
#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class Sort
{
public:
	Sort(std::vector<T> &values) : m_values(values){printValues();}//如何复制效率高?
	Sort(std::vector<T> &&values) : m_values(values)
	{
		std::cout << "rvalues constructor..." << std::endl;
		printValues();
	}

	void printValues()
	{
		for(const auto &a : m_values)
			std::cout << a << " ";
		std::cout << std::endl;
	}

	void bubbleSort()
	{
		printValues();
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
					// tmp = m_values[j];
					// m_values[j] = m_values[j - 1];
					// m_values[j - 1] = tmp;
					std::swap(m_values[j], m_values[j - 1]);
				}
			}
		}
	}

	void insertSort()
	{
		printValues();
		T flag;
		int count = m_values.size();
		if(count == 0)
		{
			return ;
		}

		for (int i = 1; i < count; ++i)//第一个值默认有序
		{
			flag = std::move(m_values[i]);
			int j = i;
			for (; (j > 0) && (flag < m_values[j - 1]); --j)//Find the position of insertation
			{  
				m_values[j] = std::move(m_values[j - 1]);
			}
			m_values[j] = std::move(flag);
		}
	}

	void selectSort()
	{
		//Exchange with the smallest item in every round.
		printValues();
		int count = m_values.size();
		if(count <= 0)
		{
			return ;
		}

		T min, tmp;
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
			// tmp = m_values[i];   //Exchange the min and the vecT[i];
			// m_values[i] = m_values[index];
			// m_values[index] = tmp;
			std::swap(m_values[i], m_values[index]);
		}
	}

	void heapSort();
	void shellSort()
	{
		printValues();
		int count = m_values.size();
		if(count == 0)
		{
			return ;
		}

		for(int gap = count / 2; gap > 0; gap /= 2)
		{
			for(int i = gap; i < count; ++i)
			{
				T tmp = std::move(m_values[i]);
				int j = i;
				for(; j >= gap && tmp < m_values[j - gap]; j -= gap)
				{
					m_values[j] = std::move(m_values[j - gap]);
				}
				m_values[j] = std::move(tmp);
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