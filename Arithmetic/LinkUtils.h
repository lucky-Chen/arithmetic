#ifndef _LINKUTILS_H_
#define _LINKUTILS_H_
#include "MyLinkList.h"
/*'
 *  链表操作相关算法
 *  转置 环路判断等
 *
*/
template <typename T>
struct LinkCircleInfo
{
	//出现环路节点坐标
	int index;
	//环路节点地址
	T *adress;
	//环长度
	int length;
	LinkCircleInfo();
};
template <typename T>
class LinkUtils
{
public:
	//转置
	LinkNode<T>* reverse(LinkNode<T> *head);
	//环路判断
	bool isHasCircle(LinkNode<T> *head, bool isNeedIndex, bool isNessLength);
	//
	void coutLink(LinkNode<T> *head);

};
#endif