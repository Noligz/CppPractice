#include <iostream>
#include <string>
using namespace std;

//
void Swap(string &str, int i, int j)
{
	if(i < 0 || j < 0 || i > str.length() || j > str.length())
		return;
	if(i == j)
		return;
	if(str[i] == str[j])
		return;
	char t = str[i];
	str[i] = str[j];
	str[j] = t;
}

//
bool IsSwap(const string str, int i, int j)
{
	if(i < 0 || j < 0 || i > str.length() || j > str.length())
		return false;
	for(int k = i; k < j; k++)
		if(str[k] == str[j])
			return false;
	return true;
}

//
void Permutation(string str, int p, int len)
{
	if(str == "" || str == "\0")
	{
		cout << "the string is null! ";
		return;
	}
	if(p < 0)
	{
		cout << "parameter error!";
		return;
	}

	if(p == len - 1)
		cout << str << endl;

	for(int i = p ; i < len; i++)
	{
		if(IsSwap(str, p, i))
		{
			Swap(str, p, i);
			Permutation(str, p+1, len);
			Swap(str, p, i);
		}
	}
}

void main()
{
	string str = "122";
	Permutation(str,0,str.length());
	system("pause");
}