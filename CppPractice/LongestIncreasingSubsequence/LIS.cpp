#include <iostream>
using namespace std;

template<typename T>
int LIS(T* arr, int length)//O(n^2)
{
	if(arr == NULL || length < 0)
		return -1;

	int* opt = new int[length];//��¼��ǰ����������еĳ���
	T* maxV = new T[length];//��¼��ǰ����������е������

	opt[0] = 1;
	maxV[0] = arr[0];
	for(int i = 1; i < length; i++)
	{
		T maxV0;//�����ǰ����������в�����arr[i]�����µ�ǰ����������е������
		int len0, len1;
		maxV0 = arr[0];
		len0 = len1 = 0;
		for(int j = 0;j < i; j++)
		{
			//���ǲ�����arr[i]�������ע��opt[0:i-1]������ֵͬ�����
			if(opt[j] > len0 || (opt[j] == len0 && maxV0 > maxV[j]))
			{
				len0 = opt[j];
				maxV0 = maxV[j];
			}
			//���ǰ���arr[i]�����
			if(opt[j] > len1 && maxV[j] <= arr[i])
				len1 = opt[j];
		}
		len1++;//��Ϊ������arr[i]

		bool isAdapt = true;//��ǰ������������Ƿ����arr[i]
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

	int len = 1;//��ǰ��֪����������еĳ���
	T* maxV = new T[length + 1];//maxV[i]=����Ϊi�ĵ��������е����ֵ
	maxV[1] = arr[0];
	for (int i = 1; i < length; i++)
	{
		int left = 1;
		int right = len;
		T currV = arr[i];
		//���ַ�����maxV[]���ҵ�С��currV�����ֵ
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