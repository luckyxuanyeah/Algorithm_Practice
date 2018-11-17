// 3.1 8 A1002(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 1010;
int main()
{
	int k1, e, count = 0;
	scanf("%d", &k1);
	double a[maxn] = { 0 }, b[maxn] = { 0 }, c[maxn] = { 0 }, k;
	for (int i = 0; i < k1; i++)
	{
		scanf("%d%lf", &e, &k);
		a[e] = k;
	}
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++)
	{
		scanf("%d%lf", &e, &k);
		b[e] = k;
	}
	for (int i = 0; i < maxn; i++)
	{
		c[i] = a[i] + b[i];
		if (c[i] != 0)
			count++;
	}
	if (count == 0)
		printf("0");//当没有非零项时输出0
	else{
		printf("%d ", count);
		for (int i = 1001; i >= 0; i--)
		{
			if (c[i] != 0)
			{
				printf("%d %.1f", i, c[i]);
				count--;
				if (count > 0)
					printf(" ");
			}
		}
	}
	return 0;
}