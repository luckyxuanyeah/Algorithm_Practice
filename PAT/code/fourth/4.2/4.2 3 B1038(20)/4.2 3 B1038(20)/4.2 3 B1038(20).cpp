// 4.2 3 B1038(20).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int n;
	scanf("%d", &n);
	int hash[101] = {};
	int t, k;
	while (n--)
	{
		scanf("%d", &t);
		hash[t]++;
	}
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d", &t);
		printf("%d", hash[t]);
		if (k > 0)
			printf(" ");
	}
	return 0;
}

