#ifndef _MYSORT_H_
#define _MYSORT_H_
#include "head.h"

template <typename  T>

class MySort{
public :
	//快排
	void quickSort(T *dataList,  int left, int right);
	//直接插入排序
	void insertSort(T *dataList, int length);
	//希尔排序
	void shellSort(T *dataList, int length);
	//归并排序
	bool mergeSort(T *dataList, int length);
	
protected:
	//归并排序部分操作
	void mergeArray(T *dataList, int left, int mid, int right, T *tmp);
	void merge(T *dataList, int left, int right, T *tmp);



};
#endif