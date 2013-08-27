#include <iostream>
using namespace std;

void f1()
{
	char str [] = "FuncTest";
	char *p = &str[0];
	cout << *p << "\t" << str << endl;
	++*p++;
	cout << *p << "\t" << str << endl;

	//F       FuncTest
	//u       GuncTest
}

void f2()
{
	char c [] = "c";
	cout << strlen(c) << endl;
}

void main()
{
	f2();

	system("pause");
}