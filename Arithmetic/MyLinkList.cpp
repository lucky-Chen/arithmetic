#include "MyLinkList.h"

template<typename T>
MyLinkList<typename T>::MyLinkList(LinkNode<T>* node)
{
	head = foot = node;
	length = 0;
}

template<typename T>
MyLinkList<typename T>::~MyLinkList()
{
	delLink();
}

//��
template<typename T>
bool MyLinkList<typename T>::insertData(LinkNode<T>* preNode, T* data)
{
	if (preNode==NULL ||data == NULL)
	{
		return false;
	}
	LinkNode<T> *tmp = new LinkNode<T>();
	tmp->data = data;
	tmp->next = preNode->next;
	preNode->next = tmp;
	//β�ڵ�
	if (preNode == foot)
	{
		foot = preNode->next;
	}

	length++;
	return true;
}
template<typename T>
bool MyLinkList<typename T>::changeHeadNode(T* data)
{
	LinkNode<T>* newHeadNode = new LinkNode<T>();
	newHeadNode->data = data;
	newHeadNode->next = head;
	head = newHeadNode;
}
//ɾ
template<typename T>
bool MyLinkList<typename T>::delData(LinkNode<T>* node)
{ 
	LinkNode<T>* preNode = head;
	//ͷ���
	if (tmpNode == node)
	{
		head = head->next;
		delete(preNode);
	}
	//β�ڵ�
	else if (node == foot)
	{
		LinkNode<T> preNode = getNode(getLength() - 2);
		foot = preNode;
		delete(node);
	}
	else
	{
		preNode = getPreNode(node);
		preNode->next = node->next;
		delete(node);
	}
	length--;
	return true;
}
//��
template<typename T>
int MyLinkList<typename T>::getLength()
{
	LinkNode<T>* tmp = head;
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->next;
	}
	return length;
}
template<typename T>
LinkNode<T>* MyLinkList<typename T>::getNode(int i)
{
	//Խ��
	if (i>=getLength() || i<0)
	{
		return NULL;
	}
	//δԽ��
	LinkNode<T>* tmpNode = head;
	for (int index = 0; index < i; i++)
	{
		tmpNode = tmpNode->next;
	}
	return tmpNode;
}

template<typename T>
LinkNode<T>* MyLinkList<typename T>::getMidNode()
{
	LinkNode<T>* fast, *slow;
	fast = slow = head;
	while (fast��=NULL &&fast->next��NULL && fast->next->next!NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
template<typename T>
LinkNode<T>* MyLinkList<typename T>::getFoot()
{

	return foot;
}
template<typename T>
LinkNode<T>* MyLinkList<typename T>::getHead()
{
	return head;
}
template<typename T>
LinkNode<T>*  MyLinkList<typename T>::getPreNode(LinkNode<T>* node)
{
	//ͷ���
	if (head == node)
	{
		return NULL;
	}
	else
	{
		LinkNode<T>* preNode = head;
		LinkNode<T>* tmpNode = preNode->next;
		while (tmp != NULL && tmpNode != node)
		{
			preNode = preNode->next;
			tmpNode = preNode->next;
		}
		if (tmp == node && node!=NULL)
		{
			return preNode;
		}
		//û�ҵ�
		return NULL;
	}
	
}
template<typename T>
void MyLinkList<typename T>::countLink()
{
	LinkNode<T> *tmp = head;
	while (tmp != NULL)
	{
		cout << *(tmp->data) << " ";
		tmp = tmp->next;
	}
	cout << endl;
}


//��
template<typename T>
bool MyLinkList<typename T>::updateData(int i, T* data)
{
	if (isOverBorder)
	{
		return false;
	}
	LinkNode<T>* dirNode = getNode(i);
	dirNode->data = data;
	return true;
}

//����
template<typename T>
void MyLinkList<typename T>::delLink()
{
	length = 0;
	while (head != NULL)
	{
		LinkNode<T>* tmp = head;
		head = head->next;
		delete(tmp);
	}
	head = foot = NULL;
}
//---------------------------protected---------------------
template<typename T>
bool MyLinkList<typename T>::isOverBorder(int i)
{
	if (i<0||i>=length)
	{
		return  true;
	}
	return false;
}