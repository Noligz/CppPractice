#include <iostream>
#include <string>
using namespace std;

string ParsePath(const string& str)
{
	if (str == "")
		return "";
	int srcLength = str.length();
	string src = str;

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

	string result = "";
	int resultIdx = 0;
	for (int i = 0; i < srcLength; i++)
	{
		if (src[i] != mark)
			result += src[i];
	}
	return result;
}

void main()
{
	string path = "D:\\z\\v\\.\\a.u\\..\\..\\q\\..\\asd.txt";
	string result = ParsePath(path);
	if (result != "")
		cout << result << endl;
	else
		cout << "invalid path" << endl;
	system("pause");
}