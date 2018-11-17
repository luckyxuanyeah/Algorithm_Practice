// 3.5 4 A1027(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
char radix[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };
int main()
{
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	char a[7] = {};
	printf("#");
	printf("%c%c", radix[r / 13 % 13], radix[r % 13]);
	printf("%c%c", radix[g / 13 % 13], radix[g % 13]);
	printf("%c%c\n", radix[b / 13 % 13], radix[b % 13]);
	return 0;
}

