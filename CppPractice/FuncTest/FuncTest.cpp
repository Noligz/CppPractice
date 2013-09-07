#include <iostream>
#include <time.h>
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

int BitABS(int n)
{
	int shiftRight = sizeof(n) * 8 - 1;
	int signBit = n >> shiftRight;
	int ret = n^signBit + signBit;
	return ret;
}

int IfABS(int n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}

unsigned BitMulti(unsigned a, unsigned b)
{
	unsigned ret = 0;
	for (int i = 0; i < 32; i++)
	{
		(b & 1 << i) && (ret += a << i);
	}
	return ret;
}

void main()
{
	clock_t startClock, finishClock;
	startClock = clock();

	for (size_t i = 0; i < 100000000; i++)
	{
		//int b = abs(-345);
		//int a=BitABS(-345);
		//int c = IfABS(-345);
		int a = 3099, b = 6877;
		//unsigned c = BitMulti(a, b);
		unsigned d = a * b;
	}
	

	finishClock = clock();
	cout << endl << "Duration: " << (double) (finishClock - startClock) / 1000 << endl;

	system("pause");
}