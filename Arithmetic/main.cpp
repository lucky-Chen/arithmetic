#include "MySort.h"
#include "MySort.cpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

int  main()
{

	MySort<int> sort_my;
	int  testIntArray[] = { 1, 2, 4, 0, 7, 3, 4, 1, 3, 6, 7, 67 };
	int length = sizeof(testIntArray) / sizeof(int);
	sort_my.quickSort(testIntArray, 0, 11);
	for (int i = 0; i < length; i++)
	{
		cout << testIntArray[i]<<endl;
	}
	system("pause");

	return 0;
}
