#include "stdio.h"
#include "algorithm"
using namespace std;

int N, M, S, D;
const int MAXN = 510;
const int INF = 100000000;
int edge[MAXN][MAXN];
int cost[MAXN][MAXN];
bool vis[MAXN] = { false };
int dis[MAXN];
int pre[MAXN];
int sum[MAXN];
void Dijstra()
{
	fill(dis, dis + N, INF);
	fill(sum, sum + N, INF);
	dis[S] = 0;
	sum[S] = 0;
	for (int i = 0; i < N; i++)
	{
		int u = -1;
		int min = INF;
		for (int j = 0; j < N; j++)
		{
			if (vis[j] == false && dis[j] < min)
			{
				u = j;
				min = dis[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < N; v++)
		{
			if (edge[u][v] != INF && vis[v] == false)
			{
				if (dis[v] > dis[u] + edge[u][v])
				{
					dis[v] = dis[u] + edge[u][v];
					pre[v] = u;
					sum[v] = sum[u] + cost[u][v];
				}
				else if (dis[v] == dis[u] + edge[u][v] && sum[v] > sum[u] + cost[u][v])
				{
					pre[v] = u;
					sum[v] = sum[u] + cost[u][v];
				}
			}
		}
	}
}
void DFS(int now)
{
	if (now == S)
	{
		printf("%d ", S);
		return;
	}
	DFS(pre[now]);
	printf("%d ", now);
}
int main()
{
	scanf("%d %d %d %d", &N, &M, &S, &D);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			edge[i][j] = INF;
			cost[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int u, v, Edge, Cost;
		scanf("%d %d", &u, &v);
		scanf("%d %d", &Edge, &Cost);
		edge[u][v] = edge[v][u] = Edge;
		cost[u][v] = cost[v][u] = Cost;
	}
	for (int i = 0; i < N; i++)
		pre[i] = i;
	Dijstra();
	DFS(D);
	printf("%d %d", dis[D], sum[D]);
	return 0;
}
