// 3.1 6 A1046(20).cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 100010;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//���ֳ�ʱ Ӧ����Ԥ����
int main()
{
	int n, m, d[maxn], dis[maxn] = {}, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		sum += d[i];
		dis[i] = sum;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, num = 0;
		scanf("%d%d", &a, &b);
		if (a>b)
			swap(a, b);
		num = dis[b-1] - dis[a-1];
		if (sum - num < num)
			num = sum - num;
		printf("%d\n", num);
	}
	return 0;
}