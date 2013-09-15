#include <iostream>
using namespace std;

void PrintResult(int candidates [], int pickedIdx [], int pickedCount)
{
	int i;
	for (i = 0; i < pickedCount - 1; i++)
	{
		cout << candidates[pickedIdx[i]] << " + ";
	}
	cout << candidates[pickedIdx[i]] << endl;
}

void SumItUp(int target, int candidates [], int lengthCandidate, int pickedIdx [], int pickedCount, bool canReuse)
{
	if (target < 0)
		return;
	if (target == 0)
	{
		PrintResult(candidates,pickedIdx,pickedCount);
		return;
	}
	int i;
	if (pickedCount == 0)
		i = 0;
	else
		i = pickedIdx[pickedCount - 1] + !canReuse;
	for (; i < lengthCandidate; i++)
	{
		pickedIdx[pickedCount] = i;
		SumItUp(target - candidates[i], candidates, lengthCandidate, pickedIdx, pickedCount + 1, canReuse);
	}
}

void main()
{
	int target = 7;
	int candidates [] = { 6, 3, 2, 7 };

	//int target = 8;
	//int candidates [] = { 10,1,2,7,6,1,5 };

	int lengthCandidate = sizeof(candidates) / sizeof(int);

	int* pickedIdx = new int[target];
	SumItUp(target, candidates, lengthCandidate, pickedIdx, 0, true);

	delete [] pickedIdx;
	system("pause");
}