
#include "MySort.h"

//快速排序
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
		quickSort(dataList, currentLeft + 1, right);

	}
}

//直接插入排序
template <typename T>
void MySort<typename T>::insertSort(T *dataList, int lenth)
{
	for (int indexOfDisOrder = 1; indexOfDisOrder < lenth; indexOfDisOrder++)
	{
		int indexOfOrder = indexOfDisOrder - 1;

		if (dataList[indexOfDisOrder] < dataList[indexOfOrder])
		{
			T tmpData = dataList[indexOfDisOrder];
			for (; indexOfOrder >= 0 && tmpData < dataList[indexOfOrder]; indexOfOrder--)
			{
				//后移数据
				dataList[indexOfOrder + 1] = dataList[indexOfOrder];
			}
			dataList[indexOfOrder + 1] = tmpData;
		}
		cout << "-------> ";
		for (int i = 0; i < lenth; i++)
		{
			cout << dataList[i] << " ";
		}
		cout << endl;
	}
}
//希尔排序
template<typename T>
void MySort<typename T>::shellSort(T *dataList, int length)
{

	for (int gap = length / 2; gap > 0; gap /= 2)
	{
		//分组
		for (int indexOfDisOrder = gap; indexOfDisOrder < length; indexOfDisOrder++)
		{
			//直接插入排序
			int indexOfOrder = indexOfDisOrder - gap;
			if (dataList[indexOfDisOrder] < dataList[indexOfOrder])
			{
				T tmpData = dataList[indexOfDisOrder];
				//后移数据
				for (; indexOfOrder >= 0 && tmpData < dataList[indexOfOrder]; indexOfOrder -= gap)
				{
					dataList[indexOfOrder + gap] = dataList[indexOfOrder];
				}
				dataList[indexOfOrder + gap] = tmpData;
			}
		}
	}
}
//归并排序
template<typename T>
bool  MySort<typename T>::mergeSort(T *dataList, int length)
{
	T *tmp = new T[length];
	if (tmp == NULL)
	{
		cout << "内存空间分配失败" << endl;
		return false;
	}
	merge(dataList, 0, length - 1, tmp);
	delete[] tmp;
	return true;

}
//归并操作
template <typename T>
void MySort<typename T>::merge(T *dataList, int left, int right, T *tmp)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge(dataList, left, mid, tmp);
		merge(dataList, mid+1, right, tmp);
		mergeArray(dataList, left, mid, right, tmp);
	}
}

//归并排序中的合并数组
template<typename T>
void MySort<typename T>::mergeArray(T* dataList, int left, int mid,int right, T* tmp)
{
	int tmpLeft = left, tmpRight = mid + 1, tmpIndex = 0;
	while ( tmpLeft <= mid && tmpRight <= right)
	{
		if (dataList[tmpLeft] < dataList[tmpRight])
		{
			tmp[tmpIndex++] = dataList[tmpLeft++];
		}
		else
		{
			tmp[tmpIndex++] = dataList[tmpRight++];
		}
	}
	//加上剩余的
	while (tmpLeft <= mid)
	{
		tmp[tmpIndex++] = dataList[tmpLeft++];
	}
	while (tmpRight <= right)
	{
		tmp[tmpIndex++] = dataList[tmpRight++];
	}
        //数据放回原数组
	for (int i = 0; i < tmpIndex; i++)
	{
		dataList[left + i] = tmp[i];
	}
}

