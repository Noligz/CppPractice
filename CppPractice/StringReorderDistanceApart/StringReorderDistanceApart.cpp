/*
Given a string of lowercase characters, reorder them such that the same characters are at least distance d from each other.

Input: { a, b, b }, distance = 2
Output: { b, a, b }
*/

#include <iostream>
using namespace std;

char* StringReorderDistanceApart(char* src, int distance)
{
	if (src == NULL || distance <= 0)
		return NULL;

	int table[26] = { 0 };
	char* p = src;
	while (*p != '\0')
		table[*p++ - 'a']++;
	int duplicate[26], nonDuplicate[26];
	int duplicateCount = 0, nonDuplicateCount = 0;
	for (int i = 0; i < 26; i++)
	{
		if (table[i] > 0)
		{
			if (table[i] == 1)
				nonDuplicate[nonDuplicateCount++] = i;
			else
				duplicate[duplicateCount++] = i;
		}
	}

	char* result = new char[strlen(src)];
	int resultIdx = 0;
	while (true)
	{
		int outCharCount = 0;
		for (int i = 0; i < duplicateCount; i++)
		{
			if (table[duplicate[i]] > 0)
			{
				result[resultIdx++] = 'a' + duplicate[i];
				outCharCount++;
				table[duplicate[i]]--;
			}
		}
		if (outCharCount == 0)
			break;
		if (outCharCount < distance)
		{
			for (int j = 0; j < distance - outCharCount; j++)
			{
				if (nonDuplicateCount == 0)
				{
					delete [] result;
					return NULL;
				}
				result[resultIdx++] = 'a' + nonDuplicate[--nonDuplicateCount];
			}
		}
	}
	while (nonDuplicateCount > 0)
		result[resultIdx++] = 'a' + nonDuplicate[--nonDuplicateCount];
	result[resultIdx++] = '\0';
	return result;
}

void main()
{
	char src [] = "abcfrrrtjuuuiobb";
	int distance = 5;
	char* result = StringReorderDistanceApart(src, distance);
	if (result != NULL)
		cout << result << endl;
	else
		cout << "No solution" << endl;
	system("pause");
}