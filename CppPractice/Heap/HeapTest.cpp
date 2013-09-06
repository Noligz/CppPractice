#include <iostream>
#include "Heap.h"
using namespace std;

void main()
{
	int arr [] = { 5, 7, 6, 3, 2, 8, 9, 11 };
	MaxHeap<int> aHeap;
	int length = sizeof(arr) / sizeof(int) ;
	for (int i = 0; i < length; i++)
	{
		aHeap.Add(arr[i]);
		int a = aHeap.Top();
	}
	aHeap.Pop();
	aHeap.Print();

	MaxHeap<int> bHeap = aHeap;
	bHeap.Pop();
	aHeap.Print();
	bHeap.Print();
	system("pause");
}