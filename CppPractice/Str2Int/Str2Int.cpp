#include<iostream>
using namespace std;

bool Str2Int(const char* str, int& num)
{
	if(str == NULL)
		return false;

	int length = strlen(str);
	if(length <= 0)
		return false;
	int isNegtive = 1;
	long long n = 0;
	int i = 0;

	if(str[0] == '-')
	{
		isNegtive = -1;
		i++;
	}
	else if(str[0] == '+')
		i++;

	while(str[i] == ' ' || str[i] == ',')
		i++;
	if(i >= length)
		return false;

	for(; i < length; i++)
	{
		char tmp = str[i];
		if(tmp == ' ' || tmp == ',')
			continue;
		if(tmp < '0' || tmp > '9')
			return false;
		n = n * 10 + tmp - '0';
		if(n > std::numeric_limits<int>::max())
		{
			cerr << "Overflow!" << endl;
			return false;
		}
	}
	n *= isNegtive;

	num = n;
	return true;
}

void main()
{
	char str[] = "-68723457";
	int n;
	bool isSuccess = Str2Int(str, n);
	if(isSuccess)
		cout << n << endl;
	system("pause");
}