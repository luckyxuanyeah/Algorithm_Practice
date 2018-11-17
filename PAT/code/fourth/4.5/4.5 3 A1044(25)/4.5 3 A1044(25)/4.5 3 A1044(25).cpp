// 4.5 3 A1044(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 100001;
int sum[maxn];
int n, S, nearS = 100000010;
int upper_bound(int left, int right, int number)
{
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (sum[mid] > number)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + m);
		if (sum[j - 1] - sum[i - 1] == m)
		{
			nearS = m;
			break;
		}
		else if (j <= n && sum[j] - sum[i - 1] < nearS)
			nearS = sum[j] - sum[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);
		if (sum[j - 1] - sum[i - 1] == nearS)
			printf("%d-%d\n", i, j - 1);
	}
	return 0;
}