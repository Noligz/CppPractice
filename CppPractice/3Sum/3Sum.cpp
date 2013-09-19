#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector< vector<int> > Triplets;

Triplets ThreeSum(vector<int> arr, int targetSum)
{
	sort(arr.begin(), arr.end());
	int length = arr.size();
	Triplets ret;
	for (int i = 0; i < length; i++)
	{
		//skip duplicate
		if (i > 0 && arr[i] == arr[i - 1])
			continue;

		int left = i + 1;
		int right = length - 1;
		while (left < right)
		{
			int currSum = arr[i] + arr[left] + arr[right];

			if (currSum > targetSum)
				right--;
			else if (currSum < targetSum)
				left++;
			else
			{
				vector<int> triplet(3);
				triplet[0] = arr[i];
				triplet[1] = arr[left];
				triplet[2] = arr[right];
				ret.push_back(triplet);
				left++;
				right--;
			}
		}
	}
	return ret;
}

void PrintTriplets(const Triplets tri)
{
	if (tri.size() == 0)
		cout << "No data" << endl;
	else
	{
		Triplets::const_iterator iter = tri.cbegin();
		for (; iter != tri.cend(); iter++)
		{
			for (int i = 0; i < 3; i++)
				cout << (*iter)[i] << "\t";
			cout << endl;
		}
	}
}

void main()
{
	int iarray [] = { -1, 0, 1, 2, -1, -4, -1 };
	size_t count = sizeof(iarray) / sizeof(int);
	vector<int> arr(iarray, iarray + count);
	Triplets result = ThreeSum(arr, 0);
	PrintTriplets(result);
	system("pause");
}