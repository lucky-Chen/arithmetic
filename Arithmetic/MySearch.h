#ifndef _MYSEARCH_H_
#define _MYSEARCH_H_
/*
*     �����㷨��
*/
template <typename T>
class MySearch
{
public:
	/*
	*����Ҫ�� ��С��������
	*/
	int binarySearch(T *arrar, int length, const T key);
	
	bool isOverBorder(int i, int length);
	
};
#endif