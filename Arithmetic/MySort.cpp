#include "MySort.h"


template <typename  T>
void MySort<typename T>::quickSort(T *dataList, int left, int right)
{
	T baseData = dataList[left];
	
	
	if (left < right)
	{
		int currentLeft = left, currentRight = right;
		//һ���ڿ�����
		while (currentLeft < currentRight)
		{
			//����������<baseData������
			for (; currentLeft < currentRight && dataList[currentRight] >= baseData; currentRight--);

			if (currentLeft < currentRight)
			{
				dataList[currentLeft] = dataList[currentRight];
				currentLeft++;
			}

			//����������>=dataBase������
			for (; currentLeft < currentRight &&dataList[currentLeft] < baseData; currentLeft++);

			if (currentLeft < currentRight)
			{

				dataList[currentRight] = dataList[currentLeft];
				currentRight--;
			}
		}
		dataList[currentLeft] = baseData;
		//����
		quickSort(dataList, left, currentLeft - 1);
		quickSort(dataList, currentLeft+1, right);

	}
}