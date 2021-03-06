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
	//int* arr6 = new int[size](1);//compile eror
	int arr5[size] = { 1 };//1 0 0
	bool* arr7 = new bool[size]();

	for (int i = 0; i < size; i++)
	{
		cout << arr7[i];
	}
}

void ValidPlusPLus()
{
	int a, b, c;
	a = b = c = 0;
	(++a)++;
	// ++a++; //invalid
	// (a + b)++; //invalid
	// ++(a + b); //invalid
	a++ + a++ + a++;
}

void EnumValue()
{
	enum { a, b = 5, c, d = 4, e };
	printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);
	//0,5,6,4,5
}

void main()
{
	clock_t startClock, finishClock;
	startClock = clock();

	for (size_t i = 0; i < 100000000; i++)
	{
	}


	finishClock = clock();
	cout << endl << "Duration: " << (double) (finishClock - startClock) << " ms" << endl;
	system("pause");
}