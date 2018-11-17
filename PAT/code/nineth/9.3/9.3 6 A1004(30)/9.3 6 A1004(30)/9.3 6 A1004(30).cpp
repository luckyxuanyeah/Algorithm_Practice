// 9.3 6 A1004(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;
const int maxn = 110;
vector<int> node[maxn];
int hashTable[maxn] = { 0 };
int max_h = 1;
void DFS(int index, int level)
{
	max_h = max(max_h, level);
	if (node[index].size() == 0)
	{
		hashTable[level]++;
		return;
	}
	for (int i = 0; i < node[index].size(); i++)
		DFS(node[index][i], level + 1);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int id, k, child;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			node[id].push_back(child);
		}
	}
	DFS(1, 1);
	printf("%d", hashTable[1]);
	for (int i = 2; i <= max_h; i++)
		printf(" %d", hashTable[i]);
	return 0;
}

