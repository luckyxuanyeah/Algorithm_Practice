// 3.1 2 B1008(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"

int main()
{
	int a[110], n, m;
	scanf("%d%d", &n, &m);
	//忘记了m不一定小于n
	m = m%n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (m == 0){
		for (int i = 0; i < n; i++)
		{
			printf("%d", a[i]);
			if (i < n - 1)
				printf(" ");
		}
	}
	else{
		for (int i = n - m; i < n; i++)
			printf("%d ", a[i]);
		for (int i = 0; i < n - m; i++)
		{
			printf("%d", a[i]);
			if (i < n - m - 1)
				printf(" ");
		}
	}
	return 0;
}