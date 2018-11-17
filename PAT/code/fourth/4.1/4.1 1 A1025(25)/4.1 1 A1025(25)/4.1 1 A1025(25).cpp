// 4.1 1 A1025(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;

struct Info{
	char number[15];
	int score, local, rank2;
}student[30001];
bool cmp(Info a, Info b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.number, b.number) < 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	int k[101] = {};
	int num = 0, sum = 0;
	for (int j = 1; j <= n; j++)
	{
		scanf("%d", &k[j]);
		sum = k[j - 1] + sum;
		for (int i = 0; i < k[j]; i++){
			scanf("%s %d", student[i + sum].number, &student[i + sum].score);
			student[i + sum].local = j;
			num++;
		}
		sort(student + sum, student + k[j] + sum, cmp);
		student[sum].rank2 = 1;
		for (int i = 1; i < k[j]; i++)
		{
			if (student[i + sum].score == student[i + sum - 1].score)
				student[i + sum].rank2 = student[i + sum - 1].rank2;
			else
				student[i + sum].rank2 = i + 1;
		}
	}
	sort(student, student + num, cmp);
	printf("%d\n", num);
	int r = 1;
	for (int i = 0; i < num; i++)
	{		
		printf("%s ", student[i].number);
		if (i>0 && student[i].score != student[i - 1].score)
			r = i + 1;
		printf("%d %d %d\n", r, student[i].local, student[i].rank2);
	}
	return 0;
}

