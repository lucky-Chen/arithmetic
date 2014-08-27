#ifndef _MYHEAP_H_
#define _MYHEAP_H_
template <typename T>
class MyHeap{
public:
	//MyHeap();
	void makeMinHeap(T *dataList, int length);
	void heapMinSort(T* dataList, int length);
	//void addMinHeapData(T *dataList, int length, T data);
	void delMinHeapData(T *dataList, int length);

protected:
	//���ϸ�������
	void MinHeapFixup(T *dataList, int i);
	//���³�������
	void MinHeapFixdown(T *dataList, int i,int length);
	//��������
	void swap(T *dataList, int iFist, int iSecond);
};

#endif
