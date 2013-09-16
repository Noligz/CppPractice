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

void BasicTypeBits()
{
	cout << "bool: " << sizeof(bool) * 8 << endl;
	cout << "char: " << sizeof(char) * 8 << endl;
	cout << "int: " << sizeof(int) * 8 << endl;
	cout << "long: " << sizeof(long) * 8 << endl;
	cout << "long long: " << sizeof(long long) * 8 << endl;
}

void main()
{
	clock_t startClock, finishClock;
	startClock = clock();

	for (size_t i = 0; i < 100000000; i++)
	{
		////int b = abs(-345);
		////int a=BitABS(-345);
		////int c = IfABS(-345);
		//int a = 3099, b = 6877;
		////unsigned c = BitMulti(a, b);
		//unsigned d = a * b;
	}

	BasicTypeBits();
	

	finishClock = clock();
	cout << endl << "Duration: " << (double) (finishClock - startClock) << " ms" << endl;

	system("pause");
}