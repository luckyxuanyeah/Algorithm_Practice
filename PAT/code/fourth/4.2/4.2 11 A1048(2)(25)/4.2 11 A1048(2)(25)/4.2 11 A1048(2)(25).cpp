// 4.2 11 A1048(2)(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
const int n = 1005;
int hash[n];
int main()
{
	int n, m, a;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		++hash[a];
	}
	for (int i = 0; i < n; i++)
	{
		if (hash[i] && hash[m - i])
		{
			if (i == m - i && hash[i] <= 1)
				continue;
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}

