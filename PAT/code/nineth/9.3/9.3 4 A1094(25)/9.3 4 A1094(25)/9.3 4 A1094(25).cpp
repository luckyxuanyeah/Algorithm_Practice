// 9.3 4 A1094(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "vector"
using namespace std;
const int maxn = 110;
vector<int> child[maxn];
int hashTable[maxn] = { 0 };
int n, m;
void DFS(int index, int level)
{
	hashTable[level]++;
	for (int i = 0; i < child[index].size(); i++)
		DFS(child[index][i], level + 1);
}
int main()
{
	int n, m, k, id;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &id, &k);
		int temp;
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &temp);
			child[id].push_back(temp);
		}
	}
	DFS(1, 1);
	int maxLevel = -1, maxValue = 0;
	for (int i = 0; i < maxn; i++)
	{
		if (hashTable[i]>maxValue)
		{
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d\n", maxValue, maxLevel);
	return 0;
}

