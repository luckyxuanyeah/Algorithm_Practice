// 3.1 9 A1009(25).cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "stdio.h"


int main()
{
	double a[2][1010] = {}, c[2011] = {};
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
		for (int j = 0; j <= 1000; j++)
		{
			c[i + j] = c[i + j] + a[1][j] * a[0][i];//���Ǽ���֮ǰ����ϵ������
		}
	}
	for (int i = 0; i <= 2000; i++)
	{
		if (c[i] != 0)
			count++;
	}
	if (count == 0)
		printf("0");
	else
	{
		printf("%d ", count);
		for (int j = 2000; j >= 0; j--)
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