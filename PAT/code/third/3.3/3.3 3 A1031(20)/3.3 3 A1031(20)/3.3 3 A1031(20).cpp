// 3.3 3 A1031(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char n[100];
	scanf("%s", n);
	int len = strlen(n);
	int n1=1, n2=3;
	for (int i = 1; i < len; i++)
	{
		n1 = (len + 2 - n2) / 2;
		if (2 * n1 + n2 - 2 != len)
			n2 = len - (2 * n1 + n2 - 2) + n2;
		if (n1>n2)
		{
			n2++;
			n1 = (len + 2 - n2) / 2;
			if (len + 2 - n1 - n2 != n1)
			{
				n2++;
				n1 = (len + 2 - n2) / 2;
			}
		}
	}
	for (int i = 0; i < n1 - 1; i++)
	{
		printf("%c", n[i]);
		for (int j = 0; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n", n[len - 1 - i]);
	}
	for (int i = 0; i < n2; i++)
		printf("%c", n[n1-1 + i]);
	printf("\n");
	return 0;
}

