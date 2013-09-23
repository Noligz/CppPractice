#include <iostream>
using namespace std;

bool Verify(int num, int valueToVarify)
{
	if (valueToVarify < 0)
		return false;
	if (num < 0)
		num = -num;

	int count = 0;
	for (int i = 1; i <= num; i++)
	{
		int n = i;
		while (n)
		{
			if (n % 10 == 1)
				count++;
			n /= 10;
		}
	}

	if (count == valueToVarify)
	{
		//cout << "correct" << endl;
		return true;
	}
	else
	{
		cout <<"num = " << num << ", value = "<< valueToVarify<< ", Correct answer: " << count << endl;
		return false;
	}

}

int CountOf1Between0ToN(int num)
{
	if (num < 0)
		num = -num;

	int count = 0;
	int step = 1;
	while (num / step > 0)
	{
		count += num / (10 * step) * step;//num��0��num / (10 * step)����ǰλ����1�Ĵ���

		int currStepNumber = num % (10 * step) / step;	//��ǰλ������

		//num��num / (10 * step)��num����ǰλ����1�Ĵ���
		if (currStepNumber == 1)
			count += num % step + 1;//+1����ΪӦ���ǵ�ǰλΪ1������ȫ��0������
		else if (currStepNumber > 1)
			count += step;

		step *= 10;
	}

	return count;
}

void main()
{
	//int input = 310;
	//int result = CountOf1Between0ToN(input);
	//cout << "CountOf1Between0ToN, N = " << input << ", result: " << result << endl;
	//Verify(input, result);

	for (int i = 0; i < 9999; i++)
	{
		Verify(i, CountOf1Between0ToN(i));
	}

	system("pause");
}