#include <iostream>
#include "SegTree.h"
using namespace std;

void main()
{
	int segment[][2] = {
		  5, 8
		, 10, 45
		, 0, 7
		, 2, 3
		, 3, 9
		, 13, 26
		, 15, 38
		, 50, 67
		, 39, 42
		, 70, 80
	};
	int segCount = sizeof(segment) / sizeof(int) / 2;

	SegTree st(-10, 100);
	for (int i = 0; i < segCount; i++)
	{
		st.Insert(segment[i][0], segment[i][1]);
	}
	int result = st.CoverLength(20,51);
	cout << result << endl;
	system("pause");
}