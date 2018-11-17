// 3.3 2 B1027(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int max = 0, num = 0;
	for (int i = 1; i < 60; i++)
	{
		int sum = i + i*(i - 1);
		if ((n - (2 * sum - 1)) < 0)
		{
			num = 2 * ((i - 1) + (i - 1)*(i - 2)) - 1;
			max = (i - 2) * 2 + 1;
			break;
		}
	}	
	int line = max / 2 + 1;
	int sub = max;	
	int count = 3;
	if (max == 1)
		printf("*\n");
	else
	{
		for (int i = 1; i <= line; i++)
		{
			for (int j = 1; j <= (max+sub)/2; j++)
			{
				if (sub == max)
				{
					if (j < max) printf("%c", c);
					else printf("%c\n", c);
				}
				else if (sub != max && sub>0)
				{
					if (j <= (max - sub) / 2)
						printf(" ");
					else
					{
						if (j < (max + sub) / 2) printf("%c", c);
						else printf("%c\n", c);
					}
				}
			}
			sub = sub - 2;
		}
		for (int i = 1; i <= line - 1; i++)
		{
			for (int j = 1; j <= (max+count)/2; j++)
			{
				if (count < max)
				{
					if (j <= (max - count) / 2)
						printf(" ");
					else
					{
						if (j < (max + count) / 2) printf("%c", c);
						else printf("%c\n", c);
					}
				}
				else if (count==max)
				{
					if (j < max) printf("%c", c);
					else printf("%c\n", c);
				}
			}					
			count = count + 2;
		}
	}
	printf("%d\n", n - num);
	return 0;
}

