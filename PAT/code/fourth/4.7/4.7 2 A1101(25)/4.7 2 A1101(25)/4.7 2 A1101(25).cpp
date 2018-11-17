// 4.7 2 A1101(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 100010;
const int inf = 0x3fffffff;
int main()
{
	int n;
	scanf("%d", &n);
	int a[maxn];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int leftMax[maxn];
	leftMax[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (i>0)
			leftMax[i] = leftMax[i - 1];
		if (i>0 && a[i - 1] > leftMax[i - 1])
			leftMax[i] = a[i - 1];
	}
	int rightMin[maxn] = {0};
	rightMin[n - 1] = inf;
	for (int i = n - 1; i >= 0; i--)
	{
		if (i < n - 1)
			rightMin[i] = rightMin[i + 1];
		if (i < n - 1 && a[i + 1] < rightMin[i + 1])
			rightMin[i] = a[i + 1];
	}
	int count = 0;
	int ans[maxn] = {0};
	for (int i = 0; i < n; i++)
	{
		if (leftMax[i]< a[i] && rightMin[i] > a[i])
			ans[count++] = a[i];
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++){
		printf("%d", ans[i]);
		if (i < count - 1) printf(" ");
	}
	printf("\n");
	return 0;
}