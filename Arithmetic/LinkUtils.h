#ifndef _LINKUTILS_H_
#define _LINKUTILS_H_
#include "MyLinkList.h"
/*'
 *  �����������㷨
 *  ת�� ��·�жϵ�
 *
*/
template <typename T>
struct LinkCircleInfo
{
	//���ֻ�·�ڵ�����
	int index;
	//��·�ڵ��ַ
	LinkNode<T> *adress;
	//������
	int length;
	LinkCircleInfo();
};
template <typename T>
class LinkUtils
{
public:
	//ת��
	LinkNode<T>* reverse(LinkNode<T> *head);
	//��·�ж�
	bool isHasCircle(LinkNode<T> *head, LinkCircleInfo<T> *info, bool needIndex, bool needCircleLength);
	//
	void coutLink(LinkNode<T> *head);

};
#endif