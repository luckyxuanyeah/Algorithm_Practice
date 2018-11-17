// 4.1 9 A1080(30).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
const int maxn = 40010;
struct Student{
	int Ge, Gi;
	int id;
	int school[10];
	int rank, total;
}stu[maxn];
struct School{
	int num;
	int receive[maxn];
}school[110];
bool cmp(Student a, Student b)
{
	if(a.total!=b.total) return a.total > b.total;
	else return a.Ge > b.Ge;
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
		scanf("%d", &school[i].num);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &stu[i].Ge, &stu[i].Gi);
		stu[i].id = i;
		stu[i].total = stu[i].Ge + stu[i].Gi;
		for (int j = 0; j < k; j++)
			scanf("%d", &stu[i].school[j]);
	}
	sort(stu, stu + n, cmp);
	for (int i = 1; i < n; i++){
		stu[0].rank = 1;
		if (stu[i].total == stu[i - 1].total && stu[i].Ge == stu[i - 1].Ge)
			stu[i].rank = stu[i - 1].rank;
		else
			stu[i].rank = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < maxn; j++)
			school[i].receive[j] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++){
			if (school[stu[i].school[j]].num>0 && stu[i].rank != stu[i + 1].rank)
			{
				school[stu[i].school[j]].receive[stu[i].id] = stu[i].id;
				school[stu[i].school[j]].num--;
				break;
			}
			else if (stu[i].rank == stu[i + 1].rank && school[stu[i].school[j]].num>0)
			{
				int p = 0;
				while (stu[i + p].rank == stu[i].rank)
					p++;
				for (int q = i; q< i + p; q++)
					school[stu[i].school[j]].receive[stu[q].id] = stu[q].id;
				if (school[stu[i].school[j]].num > 0){
					school[stu[i].school[j]].num = school[stu[i].school[j]].num - p;
					i = i + p-1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (school[i].receive[j] != -1)
				count++;		
		}
		if (count == 0)
			printf("\n");
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (school[i].receive[j] != -1){
					printf("%d", school[i].receive[j]);
					count--;
					if (count>0) printf(" ");
					else printf("\n");
				}
			}
		}
	}
	return 0;
}

