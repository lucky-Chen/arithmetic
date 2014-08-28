#ifndef _MYSEARCH_H_
#define _MYSEARCH_H_
/*
*     查找算法类
*/
template <typename T>
class MySearch
{
public:
	/*
	*数据要求 由小到大排列
	*/
	int binarySearch(T *arrar, int length, const T key);
	
	bool isOverBorder(int i, int length);
	
};
#endif