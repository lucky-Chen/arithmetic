#include "MySort.h"


template <typename  T>
void MySort<typename T>::quickSort(T *dataList, int left, int right)
{
	T baseData = dataList[left];
	
	
	if (left < right)
	{
		int currentLeft = left, currentRight = right;
		//一遍挖坑排序
		while (currentLeft < currentRight)
		{
			//从右向左找<baseData的数据
			for (; currentLeft < currentRight && dataList[currentRight] >= baseData; currentRight--);

			if (currentLeft < currentRight)
			{
				dataList[currentLeft] = dataList[currentRight];
				currentLeft++;
			}

			//从左向右找>=dataBase的数据
			for (; currentLeft < currentRight &&dataList[currentLeft] < baseData; currentLeft++);

			if (currentLeft < currentRight)
			{

				dataList[currentRight] = dataList[currentLeft];
				currentRight--;
			}
		}
		dataList[currentLeft] = baseData;
		//分治
		quickSort(dataList, left, currentLeft - 1);
		quickSort(dataList, currentLeft+1, right);

	}
}