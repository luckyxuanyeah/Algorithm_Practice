// 4.2 2 B1033(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
const int maxn = 100010;
int main()
{
	char a[maxn], b[maxn];
	scanf("%s", a);
	scanf("%s", b);
	bool hash[256] = { false };
	int len1 = strlen(a);
	int len2 = strlen(b);
	for (int i = 0; i < len1; i++)
	{
		hash[a[i]] = true;
		if (a[i] >= 'a'&&a[i] <= 'z')
			hash[a[i] - 32] = true;
		else if (a[i] >= 'A'&&a[i] <= 'Z')
			hash[a[i] + 32] = true;
	}
	for (int i = 0; i < len2; i++)
	{
		if (b[i] >= 'A'&&b[i] <= 'Z'&&hash['+'] == true)
			continue;
		else if (hash[b[i]] == false)
			printf("%c", b[i]);
	}
	printf("\n");
	return 0;
}

