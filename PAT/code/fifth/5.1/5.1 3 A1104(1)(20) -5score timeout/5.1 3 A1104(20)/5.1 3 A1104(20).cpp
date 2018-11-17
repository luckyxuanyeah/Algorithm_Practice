// 5.1 3 A1104(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 100010;
int main()
{
	int n;
	scanf("%d", &n);
	double a[maxn];
	for (int i = 0; i < n; i++)
		scanf("%lf", &a[i]);
	double sum = 0, sum1 = 0;
	double sum[maxn] = {};
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			sum = sum + a[j] * (n - j);
	}
	/*
	int main()
	{
		int n;
		scanf("%d", &n);
		double a[maxn];
		for (int i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		double sum = 0, sum1 = 0;
		double sum_p[maxn] = {};
		for (int i = 0; i < n; i++)
			sum1 = sum1 + a[i];
		sum = sum1*(double)n;
		int left = 1, right = n - 2;
		int m = 0;
		while (left <= right)
		{
			int count = right - left + 1;
			for (int i = left; i <= right; i++)
				sum_p[m] = sum_p[m] + a[i];
			sum_p[m] = sum_p[m] * (double)count;
			m++;
			left++;
			right--;
		}
		for (int i = 0; i < m; i++)
			sum = sum + sum_p[i];
		printf("%.2f\n", sum);
		return 0;
	}
	*/
	printf("%.2f\n", sum);
	return 0;
}

