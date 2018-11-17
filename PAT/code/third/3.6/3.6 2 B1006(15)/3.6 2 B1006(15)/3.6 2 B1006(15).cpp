// 3.6 2 B1006(15).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	scanf("%d", &n);
	int b, s, g;
	int a = 1;
	b = n / 100;
	s = n % 100 / 10;
	g = n % 10;
	for (int i = 0; i < b; i++)
		printf("B");
	for (int i = 0; i < s; i++)
		printf("S");
	for (int i = 0; i < g; i++)
		printf("%d", a++);
	return 0;
}

