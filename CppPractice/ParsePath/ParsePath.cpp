#include <iostream>
#include <string>
#include <vector>
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

string ParsePath2(const string& src)
{
	if (src == "")
		return "";
	vector<string> data;
	char spliter = '\\', dot = '.';
	int length = src.length();
	for (int i = 0; i < length; i++)
	{
		while (i < length && src[i] == spliter)
			i++;
		if (i < length)
		{
			int peek = i + 1;
			while (peek < length && src[peek] != spliter)
				peek++;
			string str = src.substr(i, peek - i);
			if (str == "..")
			{
				if (data.empty())
					return "";
				data.pop_back();
			}
			else if (str != ".")
				data.push_back(str);
			i = peek;
		}
	}
	
	if (!data.empty())
	{
		vector<string>::iterator iter = data.begin();
		string result = *iter++;
		for (; iter != data.end(); iter++)
			result += '\\' + *iter;
		return result;
	}
	else
		return "";
}

void main()
{
	string path = "D:\\zxc\\\\..\\\\\\cvb\\";// "D:\\z\\v\\.\\a.u\\..\\..\\q\\..\\asd.txt";
	string result = ParsePath2(path);
	if (result != "")
		cout << result << endl;
	else
		cout << "invalid path" << endl;
	system("pause");
}