// 6.2 1 A1063(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "set"
using namespace std;
set<int> number[51];
void compare(int x, int y)
{
	int Nc = 0, Nt = number[y].size();
	for (set<int>::iterator it = number[x].begin(); it != number[x].end(); it++)
	{
		if (number[y].find(*it) != number[y].end()) Nc++;
		else Nt++;
	}
	printf("%.1f%%\n", Nc *100.0 / Nt);
}
int main()
{
	int n, m, temp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &m);
		for (int j = 0; j < m; j++){
			scanf("%d", &temp);
			number[i].insert(temp);
		}
	}
	int k, str1, str2;
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		scanf("%d%d", &str1, &str2);
		compare(str1, str2);
	}
	return 0;
}