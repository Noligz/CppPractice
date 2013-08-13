#include <iostream>
using namespace std;

void ReverseString(char* str)
{
	if(str == NULL)
	{
		cerr<<"null point exception"<<endl;
		return;
	}

	int length=strlen(str);
	if(length == 1)
		return;

	char* end=str+length-1;
	for(int i=0;i<length/2;i++)
	{
		*str ^= *end;
		*end ^= *str;
		*str++ ^= *end--;
	}
}

void main()
{
	char str[]="asdfgh";

	ReverseString(str);
	if(str!=NULL)
		cout<<str<<endl;

	system("pause");
}