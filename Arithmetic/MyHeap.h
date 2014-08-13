#ifndef _MYHEAP_H_
#define _MYHEAP_H_
template <typename T>
class MyHeap{
public:
	MyHeap();
	int getLength();
	T *makeMinHeap(T *dataList, int length);
	
	void addMinHeapData(T *dataList, int length, T data);
	void delMinHeapData(T *dataList, int length);
protected:
	int length;
	//调整最小堆
	void MinHeapFixup(T *dataList, int i);
	void MinHeapFixdown(T *dataList, int i);
};

#endif
