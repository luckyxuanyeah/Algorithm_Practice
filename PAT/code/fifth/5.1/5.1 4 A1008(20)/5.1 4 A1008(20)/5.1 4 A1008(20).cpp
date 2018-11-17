// 5.1 4 A1008(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 101;
const int time1 = 6, time2 = -4, time3 = 5;
int main()
{
	int n;
	scanf("%d", &n);
	int floor[maxn];
	for (int i = 0; i < n; i++)
		scanf("%d", &floor[i]);
	int now = 0, time = 0;
	for (int i = 0; i < n; i++)
	{
		if (floor[i] - now>0)
		{
			time = time + (floor[i] - now)*time1 + time3;
			now = floor[i];
		}
		else if (floor[i] - now < 0){
			time = time + (floor[i] - now)*time2 + time3;
			now = floor[i];
		}
		else if (floor[i] - now == 0)
			time = time + time3;
	}
	printf("%d\n", time);
	return 0;
}

