// 4.2 9 A1050(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
int main()
{
	char s1[10001], s2[10001];
	bool change[128] = { false };
	gets_s(s1);
	gets_s(s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for (int i = 0; i < len2; i++)
		change[s2[i]] = true;
	for (int i = 0; i < len1; i++)
	{
		if (change[s1[i]] == false)
			printf("%c", s1[i]);
	}
	return 0;
}

