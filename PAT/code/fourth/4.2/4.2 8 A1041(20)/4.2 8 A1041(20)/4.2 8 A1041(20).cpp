// 4.2 8 A1041(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
const int maxn = 100010;
int main()
{
	int n;
	scanf("%d", &n);
	int hash[maxn] = {};
	int k;
	int number[maxn] = {};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		number[i] = k;
		hash[k]++;
	}
	int count = maxn;
	for (int i = 0; i < maxn; i++)
	{
		if (hash[i] == 1)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == number[j])
				{
					if (count>j)
						count = j;
					break;
				}
			}
		}
	}
	if (count < maxn)
		printf("%d\n", number[count]);
	else
		printf("None\n");
	return 0;
}

