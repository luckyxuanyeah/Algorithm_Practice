// 4.7 1 A1093(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
const int maxn = 100010;
int leftNumP[maxn] = { 0 };
int main()
{
	char str[maxn];
	gets_s(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i>0)
			leftNumP[i] = leftNumP[i - 1];
		if (str[i] == 'P')
			leftNumP[i]++;
	}
	int rightNumT = 0, count = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (str[i] == 'T')
			rightNumT++;
		else if (str[i] == 'A')
			count = (count + leftNumP[i] * rightNumT)%1000000007;
	}
	printf("%d\n", count);
	return 0;
}

