// 3.6 10 A1005(20).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

char change[10][6] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
	char n[102];
	scanf("%s", n);
	int len = strlen(n);
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum = sum + (n[i] - '0');
	char ans[5][6] = {};
	int m = 0;
	do{
		strcpy(ans[m] , change[sum % 10]);
		sum = sum / 10;
		++m;
	} while (sum != 0);
	for (int i = m - 1; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if (i > 0) printf(" ");
	}
	return 0;
}

