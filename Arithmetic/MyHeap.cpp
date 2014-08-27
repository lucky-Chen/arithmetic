#include "MyHeap.h"

/*
*  当前节点 i
*  父节点 (i-1)/2
*  左子节点2i+1
*  右子节点2i+2
*/


template <typename T>
void MyHeap<typename T>::makeMinHeap(T *dataList, int length)
{
	int indexWithChild = (length - 1) / 2 - 1;
	for (; indexWithChild >= 0 ; indexWithChild--)
	{
		//从最后一个非叶节点开始调整
		MinHeapFixdown(dataList, indexWithChild,length-1);
	}
}




template <typename T>
void MyHeap<typename T>::delMinHeapData(T *dataList, int length)
{
	swap(dataList, 0,length-1);
	MinHeapFixdown(dataList, 0, length-1);
}

template <typename T>
void MyHeap<typename T>::heapMinSort(T *dataList, int length)
{
	makeMinHeap(dataList, length);
	for (int i = length - 1; i > 0; i--)
	{
		//拿出最小数 前面的数从建堆
		swap(dataList,0,i);
		MinHeapFixdown(dataList, 0, i-1);
	}
}



//---------------------------protected---------------------------------
template <typename T>
void MyHeap<typename T>::swap(T *dataList,int iFist,int iSecond)
{
	T tmp = dataList[iFist];
	dataList[iFist] = dataList[iSecond];
	dataList[iSecond] = tmp;
}

//（下沉调整）
template <typename T>
void MyHeap<typename T>::MinHeapFixdown(T *dataList, int start, int end)
{
	int parentIndex = start;
	//挖坑
	T tmp = dataList[parentIndex];
	//leftChildIndex
	int minorIndex = 2 * parentIndex + 1;
	while (minorIndex <= end)
	{
		if (minorIndex + 1 <= end && dataList[minorIndex + 1] < dataList[minorIndex])
		{
			minorIndex++;
		}
		//比较父节点和子节点最小数大小
		if (tmp>dataList[minorIndex])
		{
			//子节点数据小 上浮 （填坑 --挖坑）
			dataList[parentIndex] = dataList[minorIndex];
			parentIndex = minorIndex;
			minorIndex = 2 * minorIndex + 1;
		}
		else
		{
			break;
		}
	}
	//填坑
	dataList[parentIndex] = tmp;
}

//上浮调整
template <typename T>
void MyHeap<typename T>::MinHeapFixup(T *dataList, int currentIndex)
{
	int parentIndex = (currentIndex - 1) / 2;
	//挖坑
	T tmp = dataList[currentIndex];
	while (currentIndex > 0 && parentIndex >= 0)
	{
		if (tmp < dataList[parentIndex])
		{
			//子节点数据小 父节点下沉 （填坑 --挖坑）
			dataList[currentIndex] = dataList[parentIndex];
			currentIndex = parentIndex;
			parentIndex = (currentIndex - 1) / 2;
		}
		else
		{
			break;
		}
	}
	//填坑
	dataList[currentIndex] = tmp;
}