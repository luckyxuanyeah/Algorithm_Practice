// 3.6 8 B1048(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

char change[13] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K' };

int main()
{
	char a[101], b[101];
	scanf("%s %s", a, b);
	char ans[101] = {};
	int len1 = strlen(a);
	int len2 = strlen(b);
	if (len2 > len1)
	{
		for (int i = len1 - 1; i >= 0; i--)
			a[i + (len2 - len1)] = a[i];
		for (int j = len2 - len1 - 1; j >= 0; j--)
			a[j] = '0';
	}
	else if (len2 < len1)
	{
		for (int i = len2 - 1; i >= 0; i--)
			b[i + (len1 - len2)] = b[i];
		for (int j = len1 - len2 - 1; j >= 0; j--)
			b[j] = '0';
	}
	int temp = 0;
	if (len1>len2)
		len2 = len1;
	for (int i = len2 - 1; i >= 0; i = i - 2)
	{
		int count = ((b[i] - '0') + (a[i] - '0')) % 13;
		ans[i] = change[count];
	}
	for (int i = len2 - 2; i >= 0; i = i - 2)
		ans[i] = (b[i] + 10 - a[i]) % 10 + '0';
	printf("%s", ans);
	return 0;
}

