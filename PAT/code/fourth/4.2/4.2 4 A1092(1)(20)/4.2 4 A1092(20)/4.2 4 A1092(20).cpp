// 4.2 4 A1092(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char a[1001], b[1001];
	int hash[128] = {}, hash1[128] = {};
	bool use[128] = { false };
	scanf("%s", a);
	scanf("%s", b);
	int len1 = strlen(a);
	int len2 = strlen(b);
	for (int i = 0; i < len1; i++)
		hash[a[i]]++;
	for (int i = 0; i < len2; i++)
		hash1[b[i]]++;
	int count = -1, count1 = 0, count2 = 0;
	for (int i = 0; i < len2; i++)
	{
		if (hash1[b[i]] > hash[b[i]])
		{
			count = i;
			break;
		}
	}
	int num = 0;
	for (int i = 0; i < len2; i++)
	{
		if (use[b[i]] == false)
		{
			num = num + hash1[b[i]];
			use[b[i]] = true;
		}
	}
	bool use2[128] = { false };
	for (int i = 0; i < len2; i++)
	{
		if (hash1[b[i]] >= hash[b[i]] && use2[b[i]] == false)
		{
			count1 = hash1[b[i]] - hash[b[i]] + count1;
			use2[b[i]] = true;
		}
	}
	for (int i = 0; i < 128; i++)
	{
		if (hash[i] != 0)
			count2 = count2 + hash[i];
	}
	if (count < len2 && count >= 0)
		printf("No %d\n", count1);
	else
		printf("Yes %d\n", count2 - num);
	return 0;
}

