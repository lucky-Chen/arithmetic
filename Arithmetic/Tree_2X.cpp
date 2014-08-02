#include "Tree_2x.h"

template <typename T>
void Tree_2X<typename T>::DFS(Node<T> *node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		cout << *(node->data) << " ";
		DFS(node->leftChild);
		DFS(node->rightChild);
	}
	
}
template <typename T>
void Tree_2X<typename T>::BFS(Node<T>* node)
{
	int i = 0;
	queue<Node<T>*> q;
	q.push(node);
	while (!q.empty())
	{
		Node<T>* tmpNode = q.front();
		cout << *(tmpNode->data) << " ";
		q.pop();
		if (tmpNode->leftChild != NULL)
		{
			q.push(tmpNode->leftChild);
		}
		if (tmpNode->rightChild != NULL)
		{
			q.push(tmpNode->rightChild);
		}
	}	
}