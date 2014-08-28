#include "head.h"


int  arrayList[] = { 1, 2, 4, 0, 7, 3, 4, 1, 3, 6, 7, 67 };
int getArrayLength()
{
	return sizeof(arrayList) / sizeof(int);
}
void coutList(int *dataList, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << dataList[i];
		cout << "  ";
	}
	cout << endl;
}


void testQuickSort(int *dataList, int length)
{
	MySort<int> sort_my;
	sort_my.quickSort(dataList, 0, length - 1);
}
void testInsertSort(int *dataList, int length)
{
	MySort<int> sort_my;
	sort_my.insertSort(dataList, length);
}
void testShellInsert(int *dataLis, int length)
{
	MySort<int> sort_my;
	sort_my.shellSort(dataLis, length);
}
bool testMergeSort(int *dataLis, int length)
{
	MySort<int> sort_my;
	return sort_my.mergeSort(dataLis, length);
}
void testHeap()
{

	int length = getArrayLength();
	MyHeap<int> heap;
	heap.makeMinHeap(arrayList, length);
	cout << "make MinHeap : \t";
	coutList(arrayList, length);

	cout << "sort result : \t";
	heap.heapMinSort(arrayList, length);
	coutList(arrayList, length);

}
void testBinarySearch()
{
	MySearch<int> search;
	int arraySort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << "index " << search.binarySearch(arraySort, 10, 10) << endl;

}
Node<int>* getNodes()
{
	static Node<int> *root = new Node<int>();
	static Node<int> *node1_1 = new Node<int>();
	static Node<int> *node1_2 = new Node<int>();
	static Node<int> *node2_1 = new Node<int>();
	static Node<int> *node2_2 = new Node<int>();
	static Node<int> *node2_3 = new Node<int>();
	static Node<int> *node2_4 = new Node<int>();
	static int data_0_0 = 0;
	static int data_1_1 = 1;
	static int data_1_2 = 2;
	static int data_2_1 = 3;
	static int data_2_2 = 4;
	static int data_2_3 = 5;
	static int data_2_4 = 6;

	root->data = &data_0_0;
	node1_1->data = &data_1_1;
	node1_2->data = &data_1_2;
	node2_1->data = &data_2_1;
	node2_2->data = &data_2_2;
	node2_3->data = &data_2_3;
	node2_4->data = &data_2_4;
	node1_1->data = &data_1_1;

	root->leftChild = node1_1;
	root->rightChild = node1_2;
	node1_1->leftChild = node2_1;
	node1_1->rightChild = node2_2;
	node1_2->leftChild = node2_3;
	node1_2->rightChild = node2_4;

	return root;
}

void testDFS()
{
	Tree_2X<int> tree;
	Node<int> *node = getNodes();
	tree.DFS(node);
	delete[] node;
}
void testBFS()
{
	Tree_2X<int> tree;
	Node<int> *node = getNodes();
	tree.BFS(node);
	delete[] node;
}
void getSimpleLink(LinkNode<int> *head)
{
	
	static MyLinkList<int> link(head);
	for (int i = 0; i < getArrayLength(); i++){
		if (i == 0)
		{
			head->data = &arrayList[i];
			continue;
		}
		link.insertData(link.getFoot(), &arrayList[i]);
	}

}
//≤‚ ‘¡¥±Ì
void testLinkList()
{
	
	LinkNode<int> *head = new LinkNode<int>();
	MyLinkList<int> link(head);
	for (int i = 0; i < getArrayLength(); i++){
		if (i == 0)
		{
			head->data = &arrayList[i];
			continue;
		}
		link.insertData(link.getFoot(), &arrayList[i]);
	}
	
	cout << "cout linklistData "<<endl;
	link.countLink();
	cout << "length " << link.getLength()<<endl;
	cout << "mid node :  " << *(link.getMidNode()->data)<<endl;
}


void testLinkUtils()
{
	LinkUtils<int> lu;
	LinkNode<int> *head = new LinkNode<int>();
	getSimpleLink(head);
	cout << "before reverse" << endl;
	lu.coutLink(head);
	cout << "after reverse" << endl;
	head = lu.reverse(head);
	lu.coutLink(head);
} 
int  main()
{

	testLinkUtils();
	system("pause");
	return 0;
}
