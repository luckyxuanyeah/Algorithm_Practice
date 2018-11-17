// 3.1 7 B1010(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 1010;
int main()
{
	int a[maxn] = { 0 };
	int k, e, count = 0;
	while (scanf("%d%d", &k, &e) != EOF)//输入的特别之处注意！
		a[e] = k;
	for (int i = 0; i <=1000; i++)//注意一下i的最大值！
	{
		a[i - 1] = a[i] * i;
		a[i] = 0;
		if (a[i - 1] != 0)
			count++;
	}
	if (count == 0)
		printf("0 0\n");//特别判断当期为零多项式时
	else
	{
		for (int i = 1000; i >= 0; i--)
		{
			if (a[i] != 0)
			{
				printf("%d %d", a[i], i);
				count--;
				if (count > 0) printf(" ");
			}
		}
	}
	return 0;
}
