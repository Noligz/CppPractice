/*
n个人，m个关系，具有直接关系或间接关系的人组成一个朋友圈，计算有几个朋友圈
*/

#include<iostream>
using namespace std;

int FriendCircleCount(int peopleCount, int relationshipCount, int relationship [][2])
{
	if (peopleCount <= 0 || relationshipCount <= 0 || relationship == NULL)
		return -1;

	int* leader = new int[peopleCount];	//一个朋友圈有一个leader，数组记录每个人的leader
	for (int i = 0; i < peopleCount; i++)
	{
		leader[i] = i;
	}

	for (int i = 0; i < relationshipCount; i++)
	{
		int person1 = (*(relationship + i))[0];
		int person2 = (*(relationship + i))[1];

		leader[person2] = leader[person1];
	}

	int ret = 0;
	for (int i = 0; i < peopleCount; i++)
	{
		if (leader[i] == i)
			ret++;
	}

	delete [] leader;

	return ret;
}

void main()
{
	int peopleCount = 6;
	int relationship[][2] = {
		  {0,1}
		, {1,2}
		, {3,4}
	};
	cout << FriendCircleCount(6, 3, relationship) << endl;
	system("pause");
}