// 3.8 A1042.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	scanf("%d", &n);
	char map[5] = { 'S', 'H', 'C', 'D', 'J' };
	int a[54];
	int b[54] = {}, c[54] = {};
	for (int i = 1; i <=54; i++)
		c[i-1] = i;
	for (int i = 0; i < 54; i++)
		scanf("%d", &a[i]);
	while (n--)
	{
		for (int i = 0; i < 54;i++)
			b[a[i]-1] = c[i];
		for (int j = 0; j<54; j++)
			c[j] = b[j];
	}
	for (int m = 0; m < 54; m++)
	{
		printf("%c%d", map[(c[m]-1)/13], ((c[m]-1) % 13)+1);//一定要记住
		if (m < 53)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}

