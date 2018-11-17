// 3.2 1 B1041(15).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	scanf("%d", &n);
	long long a[1010][3];
	for (int i = 0; i < n; i++)
		scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
	int m;
	scanf("%d", &m);
	int b[1010];
	for (int j = 0; j < m; j++)
		scanf("%d", &b[j]);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i] == a[j][1] && j < n)
			{
				printf("%lld %lld\n", a[j][0], a[j][2]);
				break;
			}
		}
		continue;
	}
	return 0;
}

