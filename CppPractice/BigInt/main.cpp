#include "BigInt.h"
using namespace std;

void main()
{
	BigInt a("12345678901234567890123456789");
	BigInt b("-123456790");
	BigInt c = a * b;
	c.Print();
	cout << endl;
	system("pause");
}