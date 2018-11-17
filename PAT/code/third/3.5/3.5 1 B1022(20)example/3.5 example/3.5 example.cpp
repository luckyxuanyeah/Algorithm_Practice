// 3.5 example.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"


int main()
{
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	int sum = a + b;
	int c[32] = {};
	int i = 0;
	do
	{
		c[i++] = sum%d;
		sum = sum / d;
	} while (sum != 0);
	for (int j = i-1; j >= 0; j--)
	{
		printf("%d", c[j]);
	}
	return 0;
}

