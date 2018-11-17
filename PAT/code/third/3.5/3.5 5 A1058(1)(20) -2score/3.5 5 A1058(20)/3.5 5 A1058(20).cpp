// 3.5 5 A1058(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int a1, a2, a3, b1, b2, b3;
	scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
	long long sum = 0, sum1 = 0, sum2 = 0;
	sum1 = a1 * 17 * 29 + a2 * 29 + a3;
	sum2 = b1 * 17 * 29 + b2 * 29 + b3;
	sum = sum1 + sum2;
	printf("%d.%d.%d\n", sum / (29 * 17), sum % (29 * 17) / 29, sum % 29);
	return 0;
}	

