#ifndef _TREE_2X_H_
#define _TREE_2X_H_

/*
*  ������ ��
*  �����㷨���
*/
#include<queue>
template <typename T>
struct Node
{
	T *data;
	Node *leftChild;
	Node *rightChild;
	Node()
	{
		leftChild = NULL;
		rightChild = NULL;
	}
};

template <typename T>
class Tree_2X
{
public:
	
	void DFS(Node<T>* node);
	void BFS(Node<T>* node);



};
#endif