// 10.4 1 A1003(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
const int maxn = 510;
const int INF = 1000000000;

int n, m, G[maxn][maxn];
int d[maxn], w[maxn], num[maxn], rescue[maxn];
bool vis[maxn] = { false };
void Dijkstra(int s)
{
	fill(d, d + maxn, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	w[s] = rescue[s];
	d[s] = 0;
	num[s] = 1;
	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < min)
			{
				u = j;
				min = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != INF)
			{
				if (d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + rescue[v];
					num[v] = num[u];
				}
				else if (d[u] + G[u][v] == d[v]){
					if (w[u] + rescue[v]>w[v])
						w[v] = w[u] + rescue[v];
					num[v] += num[u];
				}
			}
		}
	}
}
int main()
{
	int c1, c2;
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++)
		scanf("%d", &rescue[i]);
	int a, b, k;
	fill(G[0], G[0] + maxn*maxn, INF);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &k);
		G[a][b] = G[b][a] = k;
	}
	Dijkstra(c1);
	printf("%d %d\n", num[c2], w[c2]);
	return 0;
}

