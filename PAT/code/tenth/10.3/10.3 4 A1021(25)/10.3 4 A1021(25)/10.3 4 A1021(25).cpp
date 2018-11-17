// 10.3 4 A1021(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
using namespace std;
const int maxn = 10010;
vector<int> Adj[maxn];

bool isRoot[maxn];
int father[maxn];
int findFather(int x)
{
	while (x != father[x])
		x = father[x];
	return x;
}
void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB)
		father[faA] = faB;
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
		father[i] = i;
}
int calBlock(int n)
{
	int block = 0;
	for (int i = 1; i <= n; i++)
		isRoot[findFather(i)] = true;
	for (int i = 1; i <= n; i++)
	{
		if (isRoot[i] == true)
			block++;
	}
	return block;
}
int maxH = 0;
vector<int> temp, ans;
void DFS(int u, int Height, int pre)
{
	if (Height > maxH)
	{
		temp.clear();
		temp.push_back(u);
		maxH = Height;
	}
	else if (Height == maxH)
		temp.push_back(u);
	for (int i = 0; i < Adj[u].size(); i++)
	{
		if (Adj[u][i] == pre) continue;
		DFS(Adj[u][i], Height + 1, u);
	}
}
int main()
{
	int n, a, b;
	scanf("%d", &n);
	init(n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
		Union(a, b);
	}
	int block = calBlock(n);
	if (block != 1)
		printf("Error: %d components\n", block);
	else
	{
		DFS(1, 1, -1);
		ans = temp;
		DFS(ans[0], 1, -1);
		for (int i = 0; i < temp.size(); i++)
			ans.push_back(temp[i]);
		sort(ans.begin(), ans.end());
		printf("%d\n", ans[0]);
		for (int i = 1; i < ans.size(); i++){
			if (ans[i] != ans[i-1])
				printf("%d\n", ans[i]);
		}
	}
	return 0;
}

