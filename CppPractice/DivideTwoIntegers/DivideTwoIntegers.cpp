//Divide two integers without using multiplication, division and mod operator. 

#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	long long newDividend = dividend;
	long long newDivisor = divisor;
	bool isDividendNegative, isDivisorNegative;
	isDividendNegative = isDivisorNegative = false;
	if (newDividend < 0)
	{
		newDividend = -newDividend;
		isDividendNegative = true;
	}
	if (newDivisor < 0)
	{
		newDivisor = -newDivisor;
		isDivisorNegative = true;
	}

	int result = 0;
	if (newDividend >= newDivisor)
	{
		const int MAX = 64;
		long long tmpSum[MAX] = { 0 }, tmpCount[MAX] = { 0 };
		tmpSum[0] = newDivisor;
		tmpCount[0] = 1;
		int i;
		for (i = 1; i < MAX; i++)
		{
			tmpSum[i] = tmpSum[i - 1] + tmpSum[i - 1];
			tmpCount[i] = tmpCount[i - 1] + tmpCount[i - 1];
			if (tmpSum[i] > newDividend)
				break;
		}
		long long sum = 0;
		for (i--; i >= 0; i--)
		{
			if (sum + tmpSum[i] <= newDividend)
			{
				sum += tmpSum[i];
				result += tmpCount[i];
			}
			if (sum == newDividend)
				break;
		}
	}

	if ((isDividendNegative && !isDivisorNegative) || (!isDividendNegative && isDivisorNegative))
		result = -result;
	return result;
}

void main()
{
	long long dividend = -2147483648LL;
	long long divisor = 1;
	cout << divide(dividend, divisor) << endl;
	system("pause");
}