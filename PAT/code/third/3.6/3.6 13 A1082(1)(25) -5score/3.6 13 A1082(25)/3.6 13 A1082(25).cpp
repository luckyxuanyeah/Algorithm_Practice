// 3.6 13 A1082(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

char num[8][5] = { "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };
char change[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

int main()
{
	char n[11] = {};
	gets_s(n);
	int len = strlen(n);
	int count2 = 0, count1 = 0;
	char n2[11] = {};
	if (n[0] == '-')
	{
		printf("Fu ");
		for (int i = 1; i < len; i++)
			n2[i - 1] = n[i];
		strcpy(n, n2);
		len = len - 1;
	}
	int count = len - 2;
	if (len == 1 && n[0] == '0')
		printf("ling");
	else{
		for (int i = 0; i < len; i++)
		{
			if (n[i] != '0')
			{
				count1 = 0;
				if (i < len - 1)
				{
					printf("%s %s", change[n[i] - '0'], num[count]);
					for (int j = i+1; j < len; j++)
					{
						if (n[j] == '0')
							count1++;
					}
					if (count1 != (len - i - 1))
						printf(" ");
					else if (count1 == len - i - 1)
						break;
				}
				else printf("%s", change[n[i] - '0']);
			}
			else if (n[i] == '0'&&n[i + 1] != '0')
			{
				if ((len - i - 1) % 4 == 0)
					printf("%s ", num[count]);
				else if ((len - i - 1) % 4 != 0)
					printf("%s ", change[n[i] - '0']);
			}
			else if (n[i] == '0'&&n[i + 1] == '0')
			{
				count2 = 0;
				for (int j = i; j < len; j++)
				{
					if (n[j] == '0')
						count2++;
				}
				if (count2 != (len - i))
				{
					if ((len - i - 1) % 4 == 0)
						printf("%s ", num[count]);
					else
					{
						printf("%s ", change[n[i] - '0']);
						i = i + count2;
					}
				}
				else if (count2 == (len - i))
					break;
			}
			count--;
		}
	}
	return 0;
}

