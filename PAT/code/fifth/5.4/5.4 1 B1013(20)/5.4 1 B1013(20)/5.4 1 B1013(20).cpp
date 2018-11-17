// 5.4 1 B1013(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 1000001;
int prime[maxn] = {}, pNum = 0;
bool p[maxn] = { false };
void Find_Prime()
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			prime[pNum++] = i;
			for (int j = i; j < maxn; j += i)
				p[j] = true;
		}
	}
}
int main()
{
	Find_Prime();
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = m - 1; i < n; i++)
	{
		printf("%d", prime[i]);
		if ((i - m + 2) % 10 != 0 && i<n-1)
			printf(" ");
		else printf("\n");
	}
	return 0;
}