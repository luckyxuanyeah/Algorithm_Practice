// 3.6 example.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char a[260];
	scanf("%s", &a);
	int len = strlen(a);
	int count = 0;
	for (int i = 0; i < len / 2; i++)
	{
		if (a[i] == a[len - 1 - i])
			count++;
	}
	if (count == len / 2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

