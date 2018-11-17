// 3.6 6 A1061(2)(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char a[40000] = {'\0'};
	gets_s(a);
	int len = strlen(a);
	int p = 0, m = 0;
	bool symbol = true;
	char num[5] = {};
	for (int i = 3; i < len; i++)
	{
		if (a[i] == 'E')
		{
			p = i;
			break;
		}
	}
	if (a[p+1] == '-')
		symbol = false;
	for (int j = p + 2; j < len; j++)
		num[m++] = a[j];
	int multy = 0;
	for (int i = 0; i < m; i++)
		multy = (num[i] - '0') + multy * 10;
	if (a[0] == '-')
		printf("-");
	int count1 = 0, count2 = 0;
	if (symbol == true)
	{
		if (multy == 0)
		{
			for (int i = 3; i < p; i++)
			{
				if (a[i] != '0')
					count2 = i;
			}
			for (int i = 1; i <= count2; i++)
				printf("%c", a[i]);
		}
		else if (multy >= p - 3)
		{
			printf("%c", a[1]);
			for (int i = 3; i < p; i++)
			{
				if (a[i] != '0')
					count1 = i;
			}
			if (a[3] != '0'){
				for (int i = 3; i <= count1; i++)
					printf("%c", a[i]);
			}
			for (int j = 0; j < (multy - count1 + 2); j++)
				printf("0");
		}
		else if (multy < p - 3)
		{
			printf("%c", a[1]);
			for (int i = 3; i < (multy + 3); i++)
				printf("%c", a[i]);
			printf(".");
			for (int i = (multy + 3); i < p; i++){
				printf("%c", a[i]);
				if (a[i] == '\0')
					printf("0");
			}
		}
	}
	else if (symbol == false)
	{
		printf("0.");
		for (int i = 0; i < multy - 1; i++)
			printf("0");
		printf("%c", a[1]);
		for (int j = 3; j < p; j++)
			printf("%c", a[j]);
	}
	return 0;
}