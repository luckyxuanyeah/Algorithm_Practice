// 3.11 B1010(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int a[1010] = {};
	int b, k, max = 0, count = 0;
	while (scanf("%d%d", &k, &b) != EOF)
	{
		a[b] = k;
		if (max < b)
			max = b;
	}
	for (int i = max; i >= 0; i--)
	{
		a[i] = i*a[i];
		if (a[i] != 0)
			count++;
	}
	if (count ==0)//如果最后求导没有非零值，则输出0 0
			printf("0 0");
	else
	{
		for (int i = max; i >= 0; i--)
		{

			if (a[i] != 0)//枚举 将不为零的输出
			{
				printf("%d %d", a[i], i - 1);
				count--;
				if (count != 0)
					printf(" ");//将空格如此输出！！！
			}
		}
	}
	return 0;
}

