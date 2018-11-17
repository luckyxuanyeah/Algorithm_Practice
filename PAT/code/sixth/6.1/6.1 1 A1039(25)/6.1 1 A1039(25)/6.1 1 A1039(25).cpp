// 6.1 1 A1039(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "vector"
using namespace std;
const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[M];
int getId(char name[])
{
	int id = 0;
	for (int i = 0; i < 3; i++)
		id = id * 26 + (name[i] - 'A');
	id = id * 10 + name[3] - '0';
	return id;
}
int main()
{
	int n, k;
	char name[5];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		int courseNum, x;
		scanf("%d%d", &courseNum, &x);
		for (int i = 0; i < x; i++)
		{
			scanf("%s", name);
			int id = getId(name);
			selectCourse[id].push_back(courseNum);
		}
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name);
		int id = getId(name);
		sort(selectCourse[id].begin(), selectCourse[id].end());
		printf("%s %d", name, selectCourse[id].size());
		for (int j = 0; j < selectCourse[id].size(); j++)
			printf(" %d", selectCourse[id][j]);
		printf("\n");
	}
	return 0;
}