// 3.3 example.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"

int main()
{
	int n;
	char character;
	scanf("%d %c", &n, &character);
	double line = n*0.5;
	for (int i = 0; i < round(line); i++)
	{
		if (i == 0 || i == round(line) - 1)
		{
			for (int j = 0; j < n; j++)
				printf("%c", character);
			printf("\n");
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (j == 0)
					printf("%c", character);
				else if (j < n - 1)
					printf(" ");
				else
					printf("%c\n", character);
			}
		}
		
	}
	return 0;
}

