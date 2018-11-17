// 3.3 2 B1027(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"

int main()
{
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int bottom = (int)sqrt(2.0 * (1 + n)) - 1;
	if (bottom % 2 == 0)
		bottom--;
	int num = (bottom + 1)*(bottom + 1) / 2 - 1;
	for (int i = bottom; i >= 1; i = i - 2)
	{
		for (int j = 0; j < (bottom - i) / 2; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
	}
	for (int i = 3; i <= bottom; i = i + 2)
	{
		for (int j = 0; j < (bottom - i) / 2; j++)
			printf(" ");
		for (int j = 0; j < i; j++)
			printf("%c", c);
		printf("\n");
	}
	printf("%d\n", n - num);
	return 0;
}

