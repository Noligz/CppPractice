#include "BigInt.h"
using namespace std;

void main()
{
	BigInt a("123456789");
	BigInt b("-1234567");
	BigInt c = a * b;
	c.Print();
	cout << endl;
	system("pause");
}