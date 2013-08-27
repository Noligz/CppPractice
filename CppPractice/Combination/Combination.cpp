#include <iostream>
using namespace std;

void Combination(const char* src, int count, char* dest, int destIdx)
{
	if (src == NULL || count <= 0 || destIdx < 0)
		return;

	int length = strlen(src);
	if (length == 0 || count > length)
		return;

	if (count == 1)
	{
		dest[destIdx + 1] = '\0';
		for (int i = 0; i < length; i++)
		{
			dest[destIdx] = src[i];
			cout << dest << endl;
		}
	}
	else
	{
		//不取src[0]，剩下的取count个
		Combination(src + 1, count, dest, destIdx);

		//取src[0]，剩下的取count - 1个
		dest[destIdx] = *src;
		Combination(src + 1, count - 1, dest, destIdx + 1);
	}
}

void Combination(const char* src)
{
	if (src == NULL)
		return;

	int length = strlen(src);
	char* dest = new char[length + 1];

	for (int i = 1; i <= length; i++)
	{
		Combination(src, i, dest, 0);
	}

	delete[] dest;
}

void main()
{
	char src [] = "abcd";
	Combination(src);
	system("pause");
}