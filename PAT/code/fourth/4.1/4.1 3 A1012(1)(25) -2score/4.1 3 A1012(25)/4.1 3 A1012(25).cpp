// 4.1 3 A1012(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;

struct student{
	int id, score_c, score_m, score_e, score_a;
	int rank_c, rank_m, rank_e, rank_a;
}people[2010], temp[2010];
bool cmp1(student a, student b)
{
	return a.score_a > b.score_a;
}
bool cmp2(student a, student b)
{
	return a.score_c > b.score_c;
}
bool cmp3(student a, student b)
{
	return a.score_m > b.score_m;
}
bool cmp4(student a, student b)
{
	return a.score_e > b.score_e;
}
int max(student a)
{
	int rank = a.rank_a;
	if (rank > a.rank_c)
		rank = a.rank_c;
	else if (rank > a.rank_m)
		rank = a.rank_m;
	else if (rank > a.rank_e)
		rank = a.rank_e;
	return rank;
}
char symbol(student a)
{
	char subject = 'A';
	int rank = a.rank_a;
	if (rank > a.rank_c){
		rank = a.rank_c;
		subject = 'C';
	}
	else if (rank > a.rank_m){
		rank = a.rank_m;
		subject = 'M';
	}
	else if (rank > a.rank_e){
		rank = a.rank_e;
		subject = 'E';
	}
	return subject;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &people[i].id, &people[i].score_c, &people[i].score_m, 
			&people[i].score_e);
		people[i].score_a = round((people[i].score_c + people[i].score_m + people[i].score_e) / 3.0);
	}
	for (int i = 0; i < m; i++)
		scanf("%d", &temp[i].id);
	sort(people, people + n, cmp1);
	people[0].rank_a = 1;
	for (int i = 1; i < n; i++)
	{
		if (people[i].score_a == people[i - 1].score_a)
			people[i].rank_a = people[i - 1].rank_a;
		else people[i].rank_a = i + 1;
	}
	sort(people, people + n, cmp2);	
	people[0].rank_c = 1;
	for (int i = 1; i < n; i++)
	{
		if (people[i].score_c == people[i - 1].score_c)
			people[i].rank_c = people[i - 1].rank_c;
		else people[i].rank_c = i + 1;
	}
	sort(people, people + n, cmp3);
	people[0].rank_m = 1;
	for (int i = 1; i < n; i++)
	{
		if (people[i].score_m == people[i - 1].score_m)
			people[i].rank_m = people[i - 1].rank_m;
		else people[i].rank_m = i + 1;
	}
	sort(people, people + n, cmp4);
	people[0].rank_e = 1;
	for (int i = 0; i < n; i++)
	{
		if (people[i].score_e == people[i - 1].score_e)
			people[i].rank_e = people[i - 1].rank_e;
		else people[i].rank_e = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int num = 0;
		for (int j = 0; j < n; j++)
		{	
			if (temp[i].id == people[j].id){
				printf("%d %c\n", max(people[j]), symbol(people[j]));
				break;
			}
			num++;
		}
		if (num==n)
			printf("N/A\n");
	}
	return 0;
}

