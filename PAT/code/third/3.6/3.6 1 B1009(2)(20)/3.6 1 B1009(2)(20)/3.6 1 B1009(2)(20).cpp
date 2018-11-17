// 3.6 1 B1009(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	char n[90][90];
	int num = 0;
	while (scanf("%s", n[num]) != EOF)
		num++;
	for (int i = num - 1; i >= 0; i--)
	{
		printf("%s", n[i]);
		if (i > 0)
			printf(" ");
	}
	return 0;
}

