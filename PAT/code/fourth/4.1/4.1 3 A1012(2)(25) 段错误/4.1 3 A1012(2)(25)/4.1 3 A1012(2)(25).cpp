// 4.1 3 A1012(2)(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "algorithm"
#include "cmath"
using namespace std;

struct student{
	int id;
	int grade[4];
}stu[2010];

char course[4] = { 'A', 'C', 'M', 'E' };
int now;

bool cmp(student a, student b)
{
	return a.grade[now] > b.grade[now];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int rank[10000000][4] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0);
	}
	for (now = 0; now < 4; now++)
	{
		sort(stu, stu + n, cmp);
		rank[stu[0].id][now] = 1;
		for (int i = 0; i < n; i++)
		{
			if (stu[i].grade[now] == stu[i - 1].grade[now])
				rank[stu[i].id][now] = rank[stu[i - 1].id][now];
			else
				rank[stu[i].id][now] = i + 1;
		}
	}
	int query;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &query);
		if (rank[query][0] == 0)
			printf("N/A\n");
		else
		{
			int k = 0;
			for (int j = 0; j < 4; j++)
			{
				if (rank[query][j] < rank[query][k])
					k = j;
			}
			printf("%d %c\n", rank[query][k], course[k]);
		}
	}
	return 0;
}

