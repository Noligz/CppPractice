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

void f3()
{
	const char *p1 = "hello";
	char* const p2 = "world";
	p1++;//valid
	//p2++; //invalid
	p2[2] = 'l';//invalid, 因为"world"在常量区
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

void MinMaxInt()
{
	int intBitCount = sizeof(int) * 8;
	//int maxInt = (1 << (intBitCount - 1)) - 1;
	int minInt = 1 << (intBitCount - 1);
	int maxInt = minInt - 1;
	cout << maxInt << "\t" << minInt << endl;
	cout << (int)0x7FFFFFFF << "\t" << (int)0x80000000 << endl;
}

void f4()
{
	signed char a = 0xe0;
	int b = a;
	unsigned char c = a;
	if (a == c)
		a = c;
	if (a == b)
		a = b;
	if (b == c)
		b = c;
}

void ArrayInit()
{
	const int size = 3;
	int arr1[size];//? ? ?
	int arr2[size] = { 0 };//0 0 0
	int* arr3 = new int[size];//? ? ?
	int* arr4 = new int[size]();//0 0 0
	int arr5[size] = { 1 };//1 0 0
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

	//MinMaxInt();
	//ArrayInit();
	//f4();

	finishClock = clock();
	cout << endl << "Duration: " << (double) (finishClock - startClock) << " ms" << endl;

	system("pause");
}