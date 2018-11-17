// 3.1 3 B1012(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
//任然扣一分,用一个记个数的数组
int main()
{
	int n, ans[5] = { 0 }, count[5] = { 0 };
	int a[1010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 5 == 0)
		{
			if (a[i] % 2 == 0)
			{
				ans[0] = a[i] + ans[0];
				count[0]++;
			}
		}
		else if (a[i] % 5 == 1)
		{
			if (count[1] % 2 == 0)
				ans[1] += a[i];
			else if (count[1] % 2 == 1)
				ans[1] -= a[i];
			count[1]++;
		}
		else if (a[i] % 5 == 2)
		{
			ans[2]++;
			count[2]++;
		}
		else if (a[i] % 5 == 3)
		{
			ans[3] = ans[3] + a[i];
			count[3]++;
		}
		else if (a[i] % 5 == 4)
		{
			if (ans[4] < a[i])
				ans[4] = a[i];
			count[4]++;
		}
	}
	if (count[0] == 0) printf("N ");
	else printf("%d ", ans[0]);
	if (count[1] == 0) printf("N ");
	else printf("%d ", ans[1]);
	if (count[2] == 0) printf("N ");
	else printf("%d ", ans[2]);
	if (count[3] == 0) printf("N ");
	else printf("%.1f ", (double)ans[3] / count[3]);//double型这样输出才好
	if (count[4] == 0) printf("N\n");
	else printf("%d\n", ans[4]);
	return 0;
}

