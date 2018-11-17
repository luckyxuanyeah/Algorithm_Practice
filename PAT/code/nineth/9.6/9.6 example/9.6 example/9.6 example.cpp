// 9.6 example.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int N = 110;
bool flag[N];
int father[N];
int findFather(int x)
{
	while (x != father[x])
		x = father[x];
	return x;
}
void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
		father[faA] = faB;
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		flag[i] = false;
	}
}
int main()
{
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		Union(a, b);
	}
	for (int i = 1; i <= n; i++)
		flag[findFather(i)] = true;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += flag[i];
	printf("%d\n", ans);
	return 0;
}

