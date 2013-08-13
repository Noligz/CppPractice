#include <iostream>
using namespace std;

#define MAXLEN 20
#define max(x, y) x > y ? x : y

int opt[MAXLEN][MAXLEN];//

template<typename T>
int LCS(T* arr1, int length1, T* arr2, int length2)
{
	if(arr1 == NULL || length1 < 0 || arr2 == NULL || length2 < 0)
		return -1;

	for(int i = 0;i < length1 ;i++)
	{
		if(arr1[i] == arr2[0])
			opt[i][0] = 1;
		else
			opt[i][0] = 0;
	}
	for(int j = 0;j < length2 ;j++)
	{
		if(arr1[0] == arr2[j])
			opt[0][j] = 1;
		else
			opt[0][j] = 0;
	}

	for(int i = 1; i < length1; i++)
	{
		for(int j = 1; j < length2; j++)
		{
			if(arr1[i] == arr2[j])
				opt[i][j] = opt[i - 1][j - 1] + 1;
			else
				opt[i][j] = max(opt[i - 1][j], opt[i][j - 1]);
		}
	}

	return opt[length1 - 1][length2 - 1];
}

template<typename T>
void PrintLCS(T* arr1, int i, T* arr2, int j)
{
	if(arr1 == NULL || i < 0 || arr2 == NULL || j < 0)
		return;

	if(i == 0)
		cout << arr1[0];
	else if(j == 0)
		cout << arr2[0];
	else if(arr1[i] == arr2[j])
	{
		PrintLCS(arr1, i - 1, arr2, j - 1);
		cout << arr1[i];
	}
	else if(opt[i - 1][j] < opt[i][j - 1])
		PrintLCS(arr1, i, arr2, j - 1);
	else
		PrintLCS(arr1, i - 1, arr2, j);
}

void main()
{
	char x[] = "ABCBDAB";
	char y[] = "BDCABA";
	cout << LCS(x, strlen(x), y, strlen(y)) << endl;
	PrintLCS(x, strlen(x), y, strlen(y));
	cout << endl;
	system("pause");
}