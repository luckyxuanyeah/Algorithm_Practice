// 3.2 4 B1032.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
const int max = 100010;
struct Info{
	int num;
	int score;
}school[max];
int main()
{
	int n,a,b;
	scanf("%d", &n);
	school[max].score = {};
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		school[a].score = school[a].score + b;
		school[a].num = a;
	}
	int ScoreMax = 0, k = 0;
	for (int j = 1; j <= 100000; j++)
	{
		if (ScoreMax < school[j].score)
		{
			ScoreMax = school[j].score;
			k = j;
		}
	}
	printf("%d %d", k, school[k].score);
	return 0;
}

