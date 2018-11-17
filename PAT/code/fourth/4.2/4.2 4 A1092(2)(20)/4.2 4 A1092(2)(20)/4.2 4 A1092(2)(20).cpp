// 4.2 4 A1092(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
const int maxn = 1010;
int hash[80] = {}, miss = 0;
int change(char c)
{
	if (c >= 'a'&&c <= 'z') return c - 'a' + 10;
	else if (c >= '0'&&c <= '9') return c - '0';
	else if (c >= 'A'&&c <= 'Z') return c - 'A' + 36;
}

int main()
{
	char whole[maxn], target[maxn];
	gets_s(whole);
	gets_s(target);
	int len1 = strlen(whole);
	int len2 = strlen(target);
	for (int i = 0; i < len1; i++)
	{
		int id = change(whole[i]);
		hash[id]++;
	}
	for (int i = 0; i < len2; i++)
	{
		int id = change(target[i]);
		hash[id]--;
		if (hash[id] < 0)
			miss++;
	}
	if (miss>0) printf("No %d\n", miss);
	else printf("Yes %d\n", len1 - len2);
	return 0;
}

