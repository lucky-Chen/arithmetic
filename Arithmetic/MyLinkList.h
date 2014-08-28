#ifndef _MYLINKLIST_H_
#define _MYLINKLIST_H_
/*
*   ����������
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
	//��
	bool insertData(LinkNode<T>* preNode, T* data);
	bool changeHeadNode(T* data);
	//ɾ
	bool delData(LinkNode<T>* node);
	//��
	LinkNode<T>* getMidNode();
	LinkNode<T>* getNode(int i);
	LinkNode<T>* getHead();
	LinkNode<T>* getFoot();
	LinkNode<T>* getPreNode(LinkNode<T>* node);
	void countLink();
	int  getLength();
	//��
	bool updateData(int i, T* data);
	//����
	void  delLink();
protected:
	int length;
	LinkNode<T>* head;
	LinkNode<T>* foot;
	bool isOverBorder(int i);

};

#endif