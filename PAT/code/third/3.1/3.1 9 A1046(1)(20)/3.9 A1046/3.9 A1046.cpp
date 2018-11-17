// 3.9 A1046.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	int a[100001];
	scanf("%d", &n);
	for (int i = 1; i <= n;i++)
		scanf("%d", &a[i]);
	int m;
	int e[10001][2];
	int dis[10001] = {};
	int sub[10001] = {};
	scanf("%d", &m);
	for (int j = 0; j < m; j++)
	{
		int temp = 0;
		int sum1 = 0, sum2 = 0;
		scanf("%d%d",&e[j][0],&e[j][1]);
		if (e[j][0]>e[j][1])
		{
			temp = e[j][0];
			e[j][0] = e[j][1];
			e[j][1] = temp;
		}
		sub[j] =e[j][1] - e[j][0];
		for (int k = 0; k < sub[j]; k++)
			sum1= sum1 + a[(e[j][0] + k-1)%n+1];
		for (int k = 0; k < n - sub[j]; k++)
			sum2 = sum2 + a[(e[j][1] + k-1)%n+1];
		if (sum1<sum2)
			sum2 = sum1;
		dis[j] = sum2;
	}
	for (int k = 0; k < m; k++)
		printf("%d\n", dis[k]);
	return 0;
}

