// 3.6 8 B1048(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
const int maxn = 110;
char a[maxn], b[maxn], ans[maxn] = { 0 };
void reverse(char s[])
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++)
	{
		int temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
int main()
{
	scanf("%s %s", a, b);
	reverse(a);
	reverse(b);
	int len1 = strlen(a);
	int len2 = strlen(b);
	int len = len1 > len2 ? len1: len2;
	for (int i = 0; i < len; i++)
	{
		int num1 = i < len1 ? a[i] - '0' : 0;
		int num2 = i < len2 ? b[i] - '0' : 0;
		if (i % 2 == 0)
		{
			int temp = (num2 + num1) % 13;
			if (temp == 10) ans[i] = 'J';
			else if (temp == 11) ans[i] = 'Q';
			else if (temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}
		else
		{
			int temp = (num2 - num1 + 10) % 10;
			ans[i] = temp + '0';
		}
	}
	reverse(ans);
	printf("%s", ans);
	return 0;
}

