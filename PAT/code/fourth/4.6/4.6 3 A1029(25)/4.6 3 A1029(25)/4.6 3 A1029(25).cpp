// 4.6 3 A1029(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 1000010;
long long a[maxn], b[maxn], c[maxn];
int n1, n2;
int merge(long long a[], long long b[], long long c[], int n1, int n2)
{
	int i = 0, j = 0, index = 0;
	while (i < n1 && j < n2)
	{
		if (a[i] <= b[j])
			c[index++] = a[i++];
		else
			c[index++] = b[j++];
	}
	while (i < n1) c[index++] = a[i++];
	while (j < n2) c[index++] = b[j++];
	return index;
}
int main()
{
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
		scanf("%lld", &a[i]);
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
		scanf("%lld", &b[i]);
	int index = merge(a, b, c, n1, n2);
	if (index % 2 != 0)
		index = index / 2;
	else
		index = index / 2 - 1;
	printf("%lld\n", c[index]);
	return 0;
}