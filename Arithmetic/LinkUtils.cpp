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
//转置
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
	//链表末尾
	current->next = pre;
	return current;
}
template<typename T>
bool LinkUtils<T>::isHasCircle(LinkNode<T> *head, LinkCircleInfo<T> *info, bool needIndex, bool needCircleLength)
{
	if (head->next == NULL ){
		return false;
	}
	LinkNode<T> *slow = head->next;
	LinkNode<T> *fast = head->next->next;
	while (slow != fast)
	{
		if (fast->next == NULL || fast->next->next == NULL)
		{
			//到链表尾部 仍然无环
			return false;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	//有环
	if (needIndex)
	{
		//需要交点索引位置
		slow = head;
		int index = 0;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
			index++;
		}
		info->index = index;
		info->adress = slow;
	}
	if (needCircleLength)
	{
		//需要环长度
		int  length = 1;
		slow = slow->next;
		while (slow != fast)
		{
			length++;
			slow = slow->next;
		}
		info->length = length;
	}
	return true;
	


}
