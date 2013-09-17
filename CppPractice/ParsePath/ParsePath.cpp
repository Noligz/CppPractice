#include <iostream>
using namespace std;

char* ParsePath(char* src)
{
	int srcLength = strlen(src);
	//if (str == NULL || *str == '\0')
	//	return NULL;
	//int srcLength = strlen(str);
	//char* src = new char[srcLength + 1];
	//strcpy_s(src, srcLength, str);

	char spliter = '\\', dot = '.', mark = '\0';

	int forward, backward;
	for (int i = 0; i < srcLength; i++)
	{
		if (src[i] == dot)
		{
			backward = i - 1;
			forward = i + 1;
			while (forward < srcLength && src[forward] == dot)
				forward++;
			if (forward == srcLength || src[forward] == spliter)
			{
				if (forward - i == 2)
				{
					backward -= 1;
					while (backward >= 0 && src[backward] != spliter)
						backward--;
					if (backward < 0)
						return NULL;
				}
				for (int j = backward; j < forward; j++)
					src[j] = mark;
			}
		}
	}

	char* result = new char[srcLength];
	int resultIdx = 0;
	for (int i = 0; i < srcLength; i++)
	{
		if (src[i] != mark)
			result[resultIdx++] = src[i];
	}
	result[resultIdx] = '\0';
	//delete [] src;
	return result;
}

void main()
{
	char path [] = "D:\\z\\v\\.\\a.u\\..\\..\\q\\..\\asd.txt";
	char* result = ParsePath(path);
	if (result != NULL)
		cout << result << endl;
	else
		cout << "invalid path" << endl;
	system("pause");
}