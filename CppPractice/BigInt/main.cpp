#include "BigInt.h"
using namespace std;

void main()
{
	BigInt a("12345678901234567890123456789");
	BigInt b("-62316801523106503");
	BigInt c = a * b;
	cout << c << endl;
	system("pause");
}