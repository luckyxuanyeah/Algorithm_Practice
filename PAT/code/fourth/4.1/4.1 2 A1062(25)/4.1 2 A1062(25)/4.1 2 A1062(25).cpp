// 4.1 2 A1062(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;

struct student{
	int id, score_d, score_c, score;
}people[100000], temp[100000];
bool cmp(student a, student b)
{
	if(a.score!=b.score) return a.score > b.score;
	else
	{
		if (a.score_d != b.score_d) 
			return a.score_d > b.score_d;
		else 
			return a.id < b.id;
	}
}
int main()
{
	int n, l, h;
	int m = 0, m1 = 0, m2 = 0, m3 = 0, m4 = 0;
	bool M1[100000] = { false }, M2[100000] = { false }, M3[100000] = { false },
		M4[100000] = { false };
	scanf("%d%d%d", &n, &l, &h);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &people[i].id, &people[i].score_d, &people[i].score_c);
		people[i].score = people[i].score_d + people[i].score_c;
		if (people[i].score_d >= l && people[i].score_c >= l)
		{
			m++;
			if (people[i].score_d >= h && people[i].score_c >= h)
			{
				m1++;
				M1[i] = true;
			}
			else if (people[i].score_d >= h && people[i].score_c < h)
			{
				m2++;
				M2[i] = true;
			}
			else if (people[i].score_d < h && people[i].score_c < h
				&& people[i].score_d >= people[i].score_c)
			{
				m3++;
				M3[i] = true;
			}
			else {
				m4++;
				M4[i] = true;
			}
		}
	}
	printf("%d\n", m);
	int count = m1 - 1, count1 = m2 + m1 - 1, count2 = m1 + m2 + m3 - 1, 
		count3 = m1 + m2 + m3 + m4 - 1;
	for (int i = 0; i < n; i++)
	{
		if (M1[i] == true)
			temp[count--] = people[i];
		else if (M2[i] == true)
			temp[count1--] = people[i];
		else if (M3[i] == true)
			temp[count2--] = people[i];
		else if (M4[i] == true)
			temp[count3--] = people[i];
	}
	sort(temp, temp + m1, cmp);
	sort(temp + m1, temp + m1 + m2, cmp);
	sort(temp + m1 + m2, temp + m1 + m2 + m3, cmp);
	sort(temp + m1 + m2 + m3, temp + m1 + m2 + m3 + m4, cmp);
	for (int i = 0; i < m; i++)
		printf("%d %d %d\n", temp[i].id, temp[i].score_d, temp[i].score_c);
	return 0;
}

