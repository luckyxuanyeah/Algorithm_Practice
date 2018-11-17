// 3.6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"

int main()
{
	int n;
	scanf("%d", &n);
	int a[1001];
	int a1=0, a2=0, a3=0, a5=0;
	double a4 = 0;
	int count[5] = {0};
	int sum = 0, num = 0, max = 0, count2= 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] % 5 == 0 && a[i] % 2 == 0)
		{
			a1 = a[i] + a1;
			count[0]++;
		}
		if (a[i] % 5 == 1)
		{
			count2++;
			if (count2 % 2 != 0)
				a2 = a2 + a[i];
			else
				a2 = a2 - a[i];
			count[1]++;
		}
		if (a[i] % 5 == 2)
		{
			a3++;
			count[2]++;
		}
		if (a[i] % 5 == 3)
		{
			sum = a[i] + sum;
			num++;
			count[3]++;
		}
		a4 = (double)sum /(double) num;
		if (a[i] % 5 == 4)
		{
			if (max < a[i])
				max = a[i];
			count[4]++;
		}
		a5 = max;
	}
	if (count[0] == 0)
		printf("N ");
	else
		printf("%d ", a1);
	if (count[1] == 0)
		printf("N ");
	else
		printf("%d ", a2);
	if (count[2] == 0)
		printf("N ");
	else
		printf("%d ", a3);
	if (count[3] == 0)
		printf("N ");
	else
		printf("%.1f ", a4);
	if (count[4] == 0)
		printf("N");
	else
		printf("%d", a5);
	system("pause");
	return 0;
}

