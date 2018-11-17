// 4.1 7 A1075(2)(25).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
const int maxn = 10010;
struct Student{
	int id;
	int score[6];
	bool flag;
	int total_score;
	int solve;
}stu[maxn];
int n, k, m;
int full[6];
bool cmp(Student a, Student b)
{
	if (a.total_score != b.total_score) return a.total_score > b.total_score;
	else if (a.solve != b.solve) return a.solve > b.solve;
	else return a.id < b.id;
}
void init()
{
	for (int i = 1; i <= n; i++)
	{
		stu[i].id = i;
		stu[i].total_score = 0;
		stu[i].solve = 0;
		stu[i].flag = false;
		memset(stu[i].score, -1, sizeof(stu[i].score));
	}
}
int main()
{
	scanf("%d%d%d", &n, &k, &m);
	init();
	for (int i = 1; i <= k; i++)
		scanf("%d", &full[i]);
	int u_id, p_id, score_obtained;
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &u_id, &p_id, &score_obtained);
		if (score_obtained != -1)
			stu[u_id].flag = true;
		if (score_obtained == -1 && stu[u_id].score[p_id] == -1)
			stu[u_id].score[p_id] = 0;
		if (score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id])
			stu[u_id].solve++;
		if (score_obtained>stu[u_id].score[p_id])
			stu[u_id].score[p_id] = score_obtained;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (stu[i].score[j] != -1)
				stu[i].total_score = stu[i].total_score + stu[i].score[j];
		}
	}
	sort(stu + 1, stu + n + 1, cmp);
	int r = 1;
	for (int i = 1; i <= n && stu[i].flag==true; i++)
	{
		if (i > 1 && stu[i].total_score != stu[i - 1].total_score)
			r = i;	
		printf("%d %05d %d", r, stu[i].id, stu[i].total_score);
		for (int j = 1; j <= k; j++)
		{
			if (stu[i].score[j] == -1)
				printf(" -");
			else printf(" %d", stu[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}

