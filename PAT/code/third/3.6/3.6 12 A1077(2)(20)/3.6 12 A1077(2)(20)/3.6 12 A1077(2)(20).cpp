// 3.6 12 A1077(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int n, minlen = 256, ans = 0;
char s[100][256];

int main()
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets_s(s[i]);
		int len = strlen(s[i]);
		if (len < minlen) minlen = len;
		for (int j = 0; j < len / 2; j++)
		{
			char temp = s[i][j];
			s[i][j] = s[i][len - j - 1];
			s[i][len - j - 1] = temp;
		}
	}
	for (int i = 0; i < minlen; i++)
	{
		char c = s[0][i];
		bool same = true;
		for (int j = 0; j < n; j++)
		{
			if (c != s[j][i])
			{
				same = false;
				break;
			}
		}
		if (same) ans++;
		else break;
	}
	if (ans)
	{
		for (int i = ans - 1; i >= 0; i--)
			printf("%c", s[0][i]);
	}
	else
		printf("nai");
	return 0;
}

