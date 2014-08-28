#include "LinkUtils.h"
template<typename T> 
LinkCircleInfo<T>::LinkCircleInfo()
{
	index = -1;
	adress = NULL;
	length = -1;
}
template<typename T>
void LinkUtils<T>::coutLink(LinkNode<T> *head)
{
	LinkNode<T> *tmp = head;
	while (tmp != NULL)
	{
		cout << *(tmp->data) << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
//×ªÖÃ
template<typename T>
LinkNode<T>* LinkUtils<T>::reverse(LinkNode<T>* head)
{
	LinkNode<T> *pre = NULL, *current = head, *next = NULL;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	next = head->next;
	while (next != NULL)
	{
		current->next = pre;
		pre = current;
		current = next;
		next = current->next;
	}
	//Á´±íÄ©Î²
	current->next = pre;
	return current;
}
template<typename T>
bool LinkUtils<T>::isHasCircle(LinkNode<T> *head, bool isNeedIndex, bool isNessLength)
{

}
