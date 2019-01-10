#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include"interval_update.h"
#define step(n) 1.0/pow(2,n)
bool fun(int v);
bool mNum(int a, int b);
void intervalSearching(double low, double high)
{
	double d = high - low;
	double last;
	int begin = 0;
	int intlow = ceil(low * pow(2, begin));
	int inthigh = floor(high * pow(2, begin));
	int lowloop = intlow;
	int highloop = inthigh;
	bool flag = false;
	int resultlow;
	int resulthigh;
	while (!flag)
	{

		while (lowloop < highloop && (!flag)){
			for (int i = lowloop; i < highloop; i++)
			{
				for (int j = highloop; j > lowloop; j--)
				{
					if (flag = mNum(i, j))
					{
						resultlow = i;
						resulthigh = j;
						break;
					}
				}
				if (flag)
					break;
			}
		}
		if (!flag)
		{
			begin += 1;
			lowloop = ceil(low * pow(2, begin));
			highloop = floor(high * pow(2, begin));
		}
	}
	last = resultlow / pow(2, begin);//小数
	//把这个写到文件里
}
bool mNum(int a, int b)
{
	int c = b - a;
	if ((a%c == 0) && (b%c == 0) && fun(c))
	{
		return true;
	}
	else
		return false;
}

bool fun(int v)//判断是不是2的幂次

{
	if ((v > 0) && (v&(v - 1)) == 0)
		return true;
	else
		return false;
}
