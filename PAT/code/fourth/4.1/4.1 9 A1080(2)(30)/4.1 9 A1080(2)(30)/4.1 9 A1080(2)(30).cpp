// 4.1 9 A1080(2)(30).cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
struct Student{
	int id, Ge, Gi, sum;
	int r, cho[6];
}stu[40010];
struct school{
	int quota, stuNow, id[40010], lastNum;
}sch[110];
bool cmp(Student a, Student b)
{
	if (a.sum != b.sum) return a.sum > b.sum;
	else return a.Ge > b.Ge;
}
bool cmpId(int a, int b)
{
	return stu[a].id < stu[b].id;
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &sch[i].quota);
		sch[i].stuNow = 0;
		sch[i].lastNum = -1;
	}
	for (int i = 0; i < n; i++)
	{
		stu[i].id = i;
		scanf("%d%d", &stu[i].Ge, &stu[i].Gi);
		stu[i].sum = stu[i].Ge + stu[i].Gi;
		for (int j = 0; j < k; j++)
			scanf("%d", &stu[i].cho[j]);
	}
	sort(stu, stu + n, cmp);
	for (int i = 0; i < n; i++)
	{
		if (i>0 && stu[i].sum == stu[i - 1].sum && stu[i].Ge == stu[i - 1].Ge)
			stu[i].r = stu[i - 1].r;
		else stu[i].r = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int choice = stu[i].cho[j];
			int num = sch[choice].stuNow;
			int last = sch[choice].lastNum;
			if (num < sch[choice].quota || (last != -1 && stu[i].r == stu[last].r))
			{
				sch[choice].id[num] = i;
				sch[choice].lastNum = i;
				sch[choice].stuNow++;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (sch[i].stuNow>0)
		{
			sort(sch[i].id, sch[i].id + sch[i].stuNow, cmpId);
			for (int j = 0; j < sch[i].stuNow; j++)
			{
				printf("%d", stu[sch[i].id[j]].id);
				if (j < sch[i].stuNow - 1)
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}