#include "MyHeap.h"

/*
*  ��ǰ�ڵ� i
*  ���ڵ� (i-1)/2
*  ���ӽڵ�2i+1
*  ���ӽڵ�2i+2
*/


template <typename T>
void MyHeap<typename T>::makeMinHeap(T *dataList, int length)
{
	int indexWithChild = (length - 1) / 2 - 1;
	for (; indexWithChild >= 0 ; indexWithChild--)
	{
		//�����һ����Ҷ�ڵ㿪ʼ����
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
		//�ó���С�� ǰ������ӽ���
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

//���³�������
template <typename T>
void MyHeap<typename T>::MinHeapFixdown(T *dataList, int start, int end)
{
	int parentIndex = start;
	//�ڿ�
	T tmp = dataList[parentIndex];
	//leftChildIndex
	int minorIndex = 2 * parentIndex + 1;
	while (minorIndex <= end)
	{
		if (minorIndex + 1 <= end && dataList[minorIndex + 1] < dataList[minorIndex])
		{
			minorIndex++;
		}
		//�Ƚϸ��ڵ���ӽڵ���С����С
		if (tmp>dataList[minorIndex])
		{
			//�ӽڵ�����С �ϸ� ����� --�ڿӣ�
			dataList[parentIndex] = dataList[minorIndex];
			parentIndex = minorIndex;
			minorIndex = 2 * minorIndex + 1;
		}
		else
		{
			break;
		}
	}
	//���
	dataList[parentIndex] = tmp;
}

//�ϸ�����
template <typename T>
void MyHeap<typename T>::MinHeapFixup(T *dataList, int currentIndex)
{
	int parentIndex = (currentIndex - 1) / 2;
	//�ڿ�
	T tmp = dataList[currentIndex];
	while (currentIndex > 0 && parentIndex >= 0)
	{
		if (tmp < dataList[parentIndex])
		{
			//�ӽڵ�����С ���ڵ��³� ����� --�ڿӣ�
			dataList[currentIndex] = dataList[parentIndex];
			currentIndex = parentIndex;
			parentIndex = (currentIndex - 1) / 2;
		}
		else
		{
			break;
		}
	}
	//���
	dataList[currentIndex] = tmp;
}