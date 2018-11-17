// 4.2 7 B1047(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	scanf("%d", &n);
	int score[1001][11] = {};
	int num1, num2, score1;
	for (int i = 0; i < n; i++){
		scanf("%d-%d %d", &num1, &num2, &score1);
		score[num1][num2] = score1;
	}
	int sum[1001] = {};
	for (int i = 1; i < 1001; i++)
	{
		for (int j = 1; j < 11; j++)
			sum[i] = score[i][j] + sum[i];
	}
	int k = 0;
	for (int i = 1; i < 1001; i++)
	{
		if (sum[i]>sum[k]){
			sum[k] = sum[i];
			k = i;
		}
	}
	printf("%d %d\n", k, sum[k]);
	return 0;
}

