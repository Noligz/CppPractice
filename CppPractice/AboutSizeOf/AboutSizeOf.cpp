#include <iostream>
using namespace std;

enum ColorEnum
{
	RED, BLUE, BLACK
};

void BasicTypeBits()
{
	cout << "bool: " << sizeof(bool) * 8 << endl;//8
	cout << "char: " << sizeof(char) * 8 << endl;//8
	cout << "short: " << sizeof(short) * 8 << endl;//16
	cout << "int: " << sizeof(int) * 8 << endl;//32
	cout << "1: " << sizeof(1) * 8 << endl;//32
	cout << "4294967297: " << sizeof(4294967297) * 8 << endl;//64
	//cout << "18446744073709551617: " << sizeof(18446744073709551617) * 8 << endl;//error: constant too big
	cout << "long: " << sizeof(long) * 8 << endl;//32
	cout << "long long: " << sizeof(long long) * 8 << endl;//64
	cout << "enum: " << sizeof(ColorEnum) * 8 << endl;//32
	cout << "float: " << sizeof(float) * 8 << endl;//32
	cout << "double: " << sizeof(double) * 8 << endl;//64
	cout << "1.1: " << sizeof(1.1) * 8 << endl;//64
	cout << "char&: " << sizeof(char&) * 8 << endl;//8
	cout << "int&: " << sizeof(int&) * 8 << endl;//32
}

union U//24: max(20,1,8),再8字节对齐
{
	int a[5]; //20
	char b; //1
	double c; //8, 需要8字节对齐
};

struct STRU//32: 16+1+8=25,再8字节对齐
{
	int a[4]; //16
	char b; //1
	double c; //8, 需要8字节对齐
};

class VoidClass
{};

class NormalClass//8: 4字节对齐
{
	int ii;
	char cc;
	void foo() {    }
	typedef char* (*f)(void*);
};

class HasVirtual
{
	int ii;
	char cc;
	virtual void f1(){}
	virtual void f2(){}
};

void AboutSizeof()
{
	char* pc = "NetEast";
	char ac [] = "NetEast";
	int ia [] = { 1, 2, 3 };
	int* pi;
	cout << "char*: " << sizeof(pc) << endl;//4
	cout << "char[]: " << sizeof(ac) << endl;//8=7+1
	cout << "int[]: " << sizeof(ia) << endl;//12=4*3
	cout << "pointer: " << sizeof(pi) << endl; //4
	
	cout << "Union: " << sizeof(U) << endl;//24
	cout << "struct: " << sizeof(STRU) << endl;//24

	cout << "NormalClass: " << sizeof(NormalClass) << endl;//8, 需要4字节对齐
	cout << "VoidClass: " << sizeof(VoidClass) << endl;//1
	cout << "HasVirtual: " << sizeof(HasVirtual) << endl;//12
}

void WrapUnion()
{
	union Uout
	{
		char c[25];//25
		U uin;//24,8字节对齐
	};

	cout << "WrapUnion: " << sizeof(Uout) << endl;//32
}

void DeriveClass()
{
	class VDVoid :virtual VoidClass{};
	class MultiV :virtual NormalClass, virtual HasVirtual{};

	cout << "VDVoid: " << sizeof(VDVoid) << endl;//4
	cout << "MultiV: " << sizeof(MultiV) << endl;//24,vc与gcc不同
}

void func(char(&p)[10])
{
	printf("%d\n", sizeof(p));// 10  
}

void main()
{
	BasicTypeBits();
	AboutSizeof();
	WrapUnion();
	DeriveClass();
	char a[10];
	func(a);

	system("pause");
}