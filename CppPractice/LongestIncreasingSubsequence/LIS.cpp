#include <iostream>
using namespace std;

template<typename T>
int LIS(T* arr, int length)//O(n^2)
{
	if(arr == NULL || length < 0)
		return -1;

	int* opt = new int[length];//记录当前最长递增子序列的长度
	T* maxV = new T[length];//记录当前最长递增子序列的最大数

	opt[0] = 1;
	maxV[0] = arr[0];
	for(int i = 1; i < length; i++)
	{
		T maxV0;//如果当前最长递增子序列不包含arr[i]，记下当前最长递增子序列的最大数
		int len0, len1;
		maxV0 = arr[0];
		len0 = len1 = 0;
		for(int j = 0;j < i; j++)
		{
			//考虑不包含arr[i]的情况，注意opt[0:i-1]中有相同值的情况
			if(opt[j] > len0 || (opt[j] == len0 && maxV0 > maxV[j]))
			{
				len0 = opt[j];
				maxV0 = maxV[j];
			}
			//考虑包含arr[i]的情况
			if(opt[j] > len1 && maxV[j] <= arr[i])
				len1 = opt[j];
		}
		len1++;//因为包含了arr[i]

		bool isAdapt = true;//当前最长递增子序列是否包含arr[i]
		if(len0 > len1)
			isAdapt = false;
		else if(len0 == len1)
		{
			if(maxV0 < arr[i])
				isAdapt = false;
		}

		if(isAdapt)
		{
			opt[i] = len1;
			maxV[i] = arr[i];
		}
		else
		{
			opt[i] = len0;
			maxV[i] = maxV0;
		}
	}

	int result = opt[length - 1];
	delete[] opt;
	delete[] maxV;
	return result;
}

template <typename T>
int LIS2(T* arr, int length)//O(nlogn)
{
	if (arr == NULL || length <= 0)
		return -1;

	int len = 1;//当前已知最长递增子序列的长度
	T* maxV = new T[length + 1];//maxV[i]=长度为i的递增子序列的最大值
	maxV[1] = arr[0];
	for (int i = 1; i < length; i++)
	{
		int left = 1;
		int right = len;
		T currV = arr[i];
		//二分法，在maxV[]中找到小于currV的最大值
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (maxV[mid] >= currV)
				right = mid - 1;
			else
				left = mid + 1;
		}
		maxV[right + 1] = currV;
		if (right + 1 > len)
			len++;
	}
	delete [] maxV;
	return len;
}

void main()
{
	int a [] = { 3, 5, 9, 1, 3, 5, 7, 8, 9, 4 };
	int length = sizeof(a) / sizeof(int);
	cout << LIS2(a, length) << endl;
	system("pause");
}