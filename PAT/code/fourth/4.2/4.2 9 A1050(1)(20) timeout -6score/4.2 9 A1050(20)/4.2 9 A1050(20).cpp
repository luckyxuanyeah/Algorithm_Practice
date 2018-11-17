// 4.2 9 A1050(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char s1[10001], s2[10001];
	gets_s(s1);
	gets_s(s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	bool yes[10001] = { false };
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (s1[i] == s2[j])
			{
				yes[i] = true;
				break;
			}
		}
		if (yes[i] == false)
			printf("%c", s1[i]);
	}
	return 0;
}

