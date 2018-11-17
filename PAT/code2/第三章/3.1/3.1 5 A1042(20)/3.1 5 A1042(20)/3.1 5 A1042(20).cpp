// 3.1 5 A1042(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
//用mp映射成扑克牌的花色
char mp[5] = { 'S', 'H', 'C', 'D', 'J' };
//定义三个数组 start next end
int start[54], next[54], end[54];
int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= 54; i++)
		start[i] = i;
	for (int i = 1; i <= 54; i++)
		scanf("%d", &next[i]);
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= 54; j++)
			end[next[j]] = start[j];
		for (int j = 1; j <= 54; j++)//将start重新赋值 便于接下来使用
			start[j] = end[j];
	}
	for (int i = 1; i <= 54; i++)
	{
		if (i != 1) printf(" ");
		printf("%c%d", mp[(start[i] - 1) / 13], (start[i] - 1) % 13 + 1);//输出花色和对应字符
	}
	return 0;
}

