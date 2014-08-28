#include "MySearch.h"
template <typename T>
bool MySearch<T>::isOverBorder(int i, int length)
{
	if (i < 0 || i >= length)
	{
		return true;
	}
	return false;

}
template <typename T>
int MySearch<T>::binarySearch(T *arrar, int length, const T key)
{
	int left = 0, right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		//������� �����ݽ�С��
		if (key < arrar[mid])
		{
			right = mid - 1;
		}
		//���Ҳ��ң����ݽϴ�
		else if (key >arrar[mid])
		{
			left = mid + 1;
		}
		//�ҵ�
		else
		{
			return mid;
		}
	}
	return -1;
}
