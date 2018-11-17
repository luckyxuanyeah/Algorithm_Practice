// 3.12 A1002(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"


int main()
{
	double a[2][1010] = {}, c[1010] = {};
	int num[2], m;
	double k;
	for (int j = 0; j < 2; j++)
	{
		scanf("%d", &num[j]);
		for (int i = 0; i < num[j]; i++)
		{
			scanf("%d%lf", &m, &k);
			a[j][m] = k;
		}
	}
	int count = 0;
	for (int i = 0; i <= 1000; i++)
	{
		c[i] = a[1][i] + a[0][i];
		if (c[i] != 0)
			count++;
	}
	if (count == 0)
		printf("0");
	else
	{
		printf("%d ", count);
		for (int j = 1000; j >= 0; j--)
		{
			if (c[j] != 0)
			{
				printf("%d %.1f", j, c[j]);
				count--;
				if (count > 0)
					printf(" ");
			}
		}
	}
	return 0;
}

