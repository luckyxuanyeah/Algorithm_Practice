// 4.4 2 B1023(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int a[10];
	for (int i = 0; i < 10;i++)
		scanf("%d", &a[i]);
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = sum + a[i];
	for (int i = 1; i < 10; i++)
	{
		if (a[i] != 0){
			printf("%d", i);
			a[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		while (a[i] != 0){
			printf("%d", i);
			a[i]--;
		}
	}
	return 0;
}

