// 3.1 2 B1008(20).cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "stdio.h"

int main()
{
	int a[110], n, m;
	scanf("%d%d", &n, &m);
	//������m��һ��С��n
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