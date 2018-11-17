// 3.5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int n, m;
	int a[101];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n;i++)
		scanf("%d", &a[i]);
	m = m%n;
	for (int j = n - m; j < n;j++)
		printf("%d ", a[j]);
	for (int k = 0; k < n - m; k++)
	{
		printf("%d", a[k]);
		if (k < n - m - 1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}

