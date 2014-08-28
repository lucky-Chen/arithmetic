#ifndef _MYLINKLIST_H_
#define _MYLINKLIST_H_
/*
*   基本链表类
*/
#include <iostream>
using namespace std;
template<typename T>
struct LinkNode
{
	T* data;
	LinkNode *next;
	LinkNode()
	{
		data = NULL;
		next = NULL;
	}
};


template<typename T>
class MyLinkList
{
public:
	MyLinkList(LinkNode<T>* node);
	~MyLinkList();
	//增
	bool insertData(LinkNode<T>* preNode, T* data);
	bool changeHeadNode(T* data);
	//删
	bool delData(LinkNode<T>* node);
	//查
	LinkNode<T>* getMidNode();
	LinkNode<T>* getNode(int i);
	LinkNode<T>* getHead();
	LinkNode<T>* getFoot();
	LinkNode<T>* getPreNode(LinkNode<T>* node);
	void countLink();
	int  getLength();
	//改
	bool updateData(int i, T* data);
	//回收
	void  delLink();
protected:
	int length;
	LinkNode<T>* head;
	LinkNode<T>* foot;
	bool isOverBorder(int i);

};

#endif