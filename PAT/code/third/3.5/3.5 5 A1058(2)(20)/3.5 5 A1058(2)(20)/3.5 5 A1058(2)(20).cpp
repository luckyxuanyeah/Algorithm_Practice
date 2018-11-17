// 3.5 5 A1058(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int a[3], b[3], c[3] = {};
	scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	int temp = 0;
	c[2] = (a[2] + b[2]) % 29;
	temp = (a[2] + b[2]) / 29;
	c[1] = (a[1] + b[1] + temp) % 17;
	temp = (a[1] + b[1] + temp) / 17;
	c[0] = a[0] + b[0] + temp;
	printf("%d.%d.%d\n", c[0], c[1], c[2]);
	return 0;
}

