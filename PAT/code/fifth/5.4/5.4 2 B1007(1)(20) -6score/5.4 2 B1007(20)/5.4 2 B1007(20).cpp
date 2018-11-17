// 5.4 2 B1007(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 100001;
int prime[maxn], num = 0;
bool p[maxn] = { false };
void Find_Prime(int n)
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			prime[num++] = i;
			if (i > n) break;
			for (int j = i; j < maxn; j += i)
				p[j] = true;
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	Find_Prime(n);
	int count = 0;
	for (int i = 0; i+1 < num; i++)
	{
		if (prime[i + 1] - prime[i] == 2 && prime[i + 1] % 2 == 1 && prime[i] % 2 == 1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}