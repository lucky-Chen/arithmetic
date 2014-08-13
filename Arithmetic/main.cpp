#include "head.h"
#include "MySort.cpp"
#include "Tree_2x.cpp"
#include  "MyHeap.cpp"

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
	cout << *(node->data) << endl;
	tree.BFS(node);
	delete[] node;
}

int  main()
{
	int  testIntArray[] = { 1, 2, 4, 0, 7, 3, 4, 1, 3, 6, 7, 67 };
	int length = sizeof(testIntArray) / sizeof(int);

	testBFS();

	system("pause");
	return 0;
}
