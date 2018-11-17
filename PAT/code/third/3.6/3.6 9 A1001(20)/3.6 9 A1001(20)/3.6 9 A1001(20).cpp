// 3.6 9 A1001(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = a + b;
	char num[9] = {};
	int m = 0;
	if (sum < 0)
	{
		printf("-");
		sum = -sum;
	}
	int count = sum;
	while (sum != 0)
	{
		num[m++] = sum % 10 + '0';
		sum = sum / 10;
	}
	int len = strlen(num);
	if (len < 4)
		printf("%d", count);
	else if (count==0) printf("0");
	else
	{
		for (int i =len-1;i>=0; i--){
			printf("%c", num[i]);
			if (i % 3 == 0 && i > 0) printf(",");
		}
	}
	return 0;
}

