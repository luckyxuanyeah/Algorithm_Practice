// 6.1 2 A1047(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "vector"
#include "algorithm"
#include "string.h"
using namespace std;
const int maxn = 40010;
const int maxc = 2510;
vector<int> courseNum[maxc];
char name[maxn][5];
bool cmp(int a,int b)
{
	return strcmp(name[a], name[b]) < 0;
}
int main()
{
	int n, k, c, courseId;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d", name[i], &c);
		for (int j = 0; j < c; j++){
			scanf("%d", &courseId);
			courseNum[courseId].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		printf("%d %d\n", i, courseNum[i].size());
		sort(courseNum[i].begin(), courseNum[i].end(), cmp);
		for (int j = 0; j < courseNum[i].size(); j++)
			printf("%s\n", name[courseNum[i][j]]);
	}
	return 0;
}