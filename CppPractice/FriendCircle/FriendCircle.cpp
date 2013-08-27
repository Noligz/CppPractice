/*
n���ˣ�m����ϵ������ֱ�ӹ�ϵ���ӹ�ϵ�������һ������Ȧ�������м�������Ȧ
*/

#include<iostream>
using namespace std;

int FriendCircleCount(int peopleCount, int relationshipCount, int relationship [][2])
{
	if (peopleCount <= 0 || relationshipCount <= 0 || relationship == NULL)
		return -1;

	int* leader = new int[peopleCount];	//һ������Ȧ��һ��leader�������¼ÿ���˵�leader
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