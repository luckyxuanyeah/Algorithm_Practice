// 10.3 3 A1013(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "vector"
using namespace std;
const int maxn = 1010;
bool inq[maxn];
vector<int> G[maxn];
int n, m, k, currentPoint;
void DFS(int v)
{
	if (v == currentPoint)
		return;
	inq[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (inq[G[v][i]] == false)
			DFS(G[v][i]);
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int num1, num2;
		scanf("%d%d", &num1, &num2);
		G[num1].push_back(num2);
		G[num2].push_back(num1);
	}
	for (int query = 0; query < k; query++)
	{
		scanf("%d", &currentPoint);
		memset(inq, false, sizeof(inq));
		int block = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i != currentPoint && inq[i] == false)
			{
				DFS(i);
				block++;
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}

