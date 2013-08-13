#include <iostream>
using namespace std;

template<typename T>
int LIS(T* arr, int length)
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

void main()
{
	int a[9] = {3,5,9,1,3,5,7,8,9};
	cout << LIS(a,9) << endl;
	system("pause");
}