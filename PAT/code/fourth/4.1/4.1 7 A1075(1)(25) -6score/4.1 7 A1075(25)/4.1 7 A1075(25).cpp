// 4.1 7 A1075(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
const int maxn = 10010;
struct user_Info{
	int user_id, pro_id[6], par_score[6], total_score, num1, num2, rank;
	bool pass;
}user[maxn];
bool cmp(user_Info a, user_Info b)
{
	if (a.total_score != b.total_score) return a.total_score > b.total_score;
	else if (a.num1 != b.num1) return a.num1 > b.num1;
	else return a.user_id < b.user_id;
}
int main()
{
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	int score[5];
	for (int i = 1; i <= k; i++)
		scanf("%d", &score[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
			user[i].par_score[j] = -1;
		user[i].total_score = -1;
		user[i].pass = false;
	}
	user[maxn].num1 = {};
	int temp1 = 0, temp2 = 0, temp3 = 0;
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &temp1, &temp2, &temp3);
		user[temp1].user_id = temp1;
		user[temp1].pro_id[temp2] = temp2;
		if (temp3 >= 0 && temp3 > user[temp1].par_score[temp2]){
			user[temp1].par_score[temp2] = temp3;
			user[temp1].pass = true;
		}
		else if (temp3 == -1)
			user[temp1].par_score[temp2] = 0;
		if (user[temp1].par_score[temp2] == score[temp2])
			user[temp1].num1++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (user[i].par_score[j] >= 0)
				user[i].total_score = user[i].par_score[j] + user[i].total_score;
		}
	}
	sort(user+1, user + n+1, cmp);
	for (int i = 2; i <= n; i++)
	{
		user[1].rank = 1;
		if (i > 1 && user[i].total_score != user[i - 1].total_score)
			user[i].rank = i;
		else
			user[i].rank = user[i - 1].rank;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (user[i].pass == true)
				user[i].num2++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (user[i].num2 >0){
			printf("%d %05d %d ", user[i].rank, user[i].user_id, user[i].total_score+1);
			for (int j = 1; j <= k; j++){
				if (user[i].par_score[j] != -1)
					printf("%d", user[i].par_score[j]);
				else
					printf("-");
				if (j < k)
					printf(" ");
				else printf("\n");
			}
		}
	}
	return 0;
}

