#ifndef _MYSORT_H_
#define _MYSORT_H_
#include "head.h"

template <typename  T>

class MySort{
public :
	//����
	void quickSort(T *dataList,  int left, int right);
	//ֱ�Ӳ�������
	void insertSort(T *dataList, int length);
	//ϣ������
	void shellSort(T *dataList, int length);
	//�鲢����
	bool mergeSort(T *dataList, int length);
	
protected:
	//�鲢���򲿷ֲ���
	void mergeArray(T *dataList, int left, int mid, int right, T *tmp);
	void merge(T *dataList, int left, int right, T *tmp);



};
#endif