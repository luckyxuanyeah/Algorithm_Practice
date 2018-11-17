// 3.6 5 B1002(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

char change[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
	char n[101];
	gets(n);
	int sum = 0;
	int len = strlen(n);
	for (int i = 0; i < len; i++)
		sum = sum + (n[i] - '0');
	int ans[101] = {};
	int num = 0;
	while (sum != 0)
	{
		ans[num++] = sum % 10;
		sum = sum / 10;
	}
	for (int i = num - 1; i >= 0; i--)
	{
		printf("%s", change[ans[i]]);
		if (i > 0)
			printf(" ");
	}
	return 0;
}

