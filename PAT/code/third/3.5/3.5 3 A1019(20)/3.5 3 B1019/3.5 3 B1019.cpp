// 3.5 3 B1019.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	int a[32];
	int i = 0;
	do{
		a[i++] = n % b;
		n = n / b;
	} while (n != 0);
	int k = 0;
	int count = i-1;
	int count1 = 0;
	while (a[k] == a[count] && k <= count) //��㣬����Ҫѭ������ ������while����
	{
		k++;
		count--; 
		count1++;
	}
	int time = (i - 1) / 2 + 1;
	if (count1 == time)
		printf("Yes\n");
	else
		printf("No\n");
	for (int j = i-1; j >= 0; j--)
	{
		printf("%d", a[j]);
		if (j > 0)
			printf(" ");
	}
	return 0;
}

