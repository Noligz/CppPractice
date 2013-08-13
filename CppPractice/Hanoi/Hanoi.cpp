#include <iostream>
using namespace std;

void Hanoi3(int h, char start, char through, char dest)
{
	if(h <= 0)
	{
		cerr << "ERROR!";
		return;
	}
	if(1 == h)
		cout << start << " ==> " << dest << endl;
	else
	{
		Hanoi3(h - 1, start, dest, through);
		cout << start << " ==> " << dest << endl;
		Hanoi3(h - 1, through, start, dest);
	}
}

int Step_Hanoi3(int h)
{
	if(h < 0)
		return -1;
	return 2 ^ h - 1;
}

void PrintHanoi4(int h, int* stepHanoi4, int* opt, char start, char through1, char through2, char dest)
{
	if(h <= 0)
	{
		cerr << "ERROR!";
		return;
	}
	if(1 == h)
		cout << start << " ==> " << dest << endl;
	else
	{
		PrintHanoi4(opt[h], stepHanoi4, opt, start, dest, through2, through1);
		Hanoi3(h - opt[h], start, through2, dest);
		PrintHanoi4(opt[h], stepHanoi4, opt, through1, start, through2, dest);
	}
}

void Hanoi4(int h, char start, char through1, char through2, char dest)
{
	if(h <= 0)
	{
		cerr << "ERROR!";
		return;
	}
	if(1 == h)
		cout << start << " ==> " << dest << endl;
	else
	{
		int* stepHanoi4 = new int[h + 1];	//i层高的4柱汉诺塔需要的步数
		int* opt = new int[h + 1];			//i层高的4柱汉诺塔最佳分割处以上的层数

		//计算stepHanoi4和opt
		stepHanoi4[1] = 1;
		opt[0] = 0;
		for(int i = 2; i <= h; i++)
		{
			int min = 2 * stepHanoi4[1] + Step_Hanoi3(i - 1);
			int optTmp = 1;
			for(int j = 2; j < i; j++)
			{
				int stepj = 2 * stepHanoi4[j] + Step_Hanoi3(i - j);
				if( stepj < min)
				{
					min = stepj;
					optTmp = j;
				}
			}
			stepHanoi4[i] = min;
			opt[i] = optTmp;
		}

		PrintHanoi4(h, stepHanoi4, opt, start, through1, through2, dest);
	}
}

void main()
{
	//Hanoi3(3, 'a', 'b', 'c');
	Hanoi4(5, 'a', 'b', 'c', 'd');
	system("pause");
}