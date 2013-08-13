#include <iostream>
using namespace std;

template<typename T>
void Swap(T* arr, int a, int b)
{
	T tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

template<typename T>
void QuickSort(T* arr, int start, int end)
{
	if(arr == NULL || start < 0 || end < 0)
		return;
	if(start >= end)
		return;
	int startOrigin = start;
	int endOrigin = end;
	T pivot = arr[start];
	while(start < end)
	{
		while(start < end && arr[end] <= pivot)
			end--;
		if(start < end)
			arr[start++] = arr[end];
		while(start < end && arr[start] >= pivot)
			start++;
		if(start < end)
			arr[end--] = arr[start];
	}
	arr[end] = pivot;
	//if(end > 0)
		QuickSort(arr, startOrigin, end - 1);
	//if(end < endOrigin)
		QuickSort(arr, end + 1, endOrigin);
}

template<typename T>
T FindK(T* arr, int start, int end, int k)
{
	if(arr == NULL || start < 0 || end < 0 || k < 0)
		return NULL;
	if(start >= end || k - 1 > end - start)
		return NULL;
	int startOrigin = start;
	int endOrigin = end;
	T pivot = arr[start];
	while(start < end)
	{
		while(start < end && arr[end] <= pivot)
			end--;
		if(start < end)
			arr[start++] = arr[end];
		while(start < end && arr[start] >= pivot)
			start++;
		if(start < end)
			arr[end--] = arr[start];
	}
	arr[end] = pivot;
	int tmp = end - startOrigin;
	if(tmp == k - 1)
		return pivot;
	else if(tmp > k - 1)
		return FindK(arr, startOrigin, end - 1, k);
	else
		return FindK(arr, end + 1, endOrigin, k - tmp - 1);
}

template<typename T>
void Bubble(T* arr, int length)
{
	if(arr == NULL || length < 0)
		return;
	for(int i = 0; i < length; i++)
	{
		for(int j = 1; j < length - i; j++)
		{
			if(arr[j] < arr[j - 1])
				Swap(arr, j - 1, j);
		}
	}
}

template<typename T>
T FindK_Bubble(T* arr, int length, int k)
{
	if(arr == NULL || length < 0 || k < 0 || k > length)
		return NULL;
	for(int i = 0; i < k; i++)
	{
		for(int j = 1; j < length - i; j++)
		{
			if(arr[j - 1] > arr[j])
				Swap(arr, j - 1, j);
		}
	}
	return arr[length - k];
}

void main()
{
	int a[] = {3,6,2,1,1,55,9,4,3,7,8,5,3,3};
	int count = 14;
	int k = 3;
	QuickSort(a,0,count - 1);
	//Bubble(a, count);
	for(int i = 0; i < count; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << FindK(a, 0, count - 1, k) << endl;
	cout << FindK_Bubble(a, count, k) << endl;
	system("pause");
}