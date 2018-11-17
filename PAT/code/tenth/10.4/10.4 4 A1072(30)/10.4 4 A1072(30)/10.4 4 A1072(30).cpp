// 10.4 4 A1072(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
const int maxH = 1020;
const int INF = 1000000000;
int n, m, k, Ds, G[maxH][maxH];
int d[maxH];
bool vis[maxH] = { false };
void Dijkstra(int s)
{
	memset(vis, false, sizeof(vis));
	fill(d, d + maxH, INF);
	d[s] = 0;
	for (int i = 0; i < n + m; i++)
	{
		int u = -1, min = INF;
		for (int j = 1; j <= m + n; j++)
		{
			if (vis[j] == false && d[j] < min)
			{
				u = j;
				min = d[j];
			}
			if (u == -1) return;
			vis[u] = true;
			for (int v = 1; v <= n + m; v++)
			{
				if (vis[v] == false && G[u][v] != INF)
				{
					if (d[u] + G[u][v] < d[v])
						d[v] = d[u] + G[u][v];
				}
			}
		}
	}
}
int getID(char str[])
{
	int i = 0, len = strlen(str), id = 0;
	while (i < len)
	{
		if (str[i] != 'G')
			id = id * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == 'G') 
		return n + id;
	else 
		return id;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &Ds);
	int u, v, w;
	char p1[5], p2[5];
	fill(G[0], G[0] + maxH*maxH, INF);
	for (int i = 0; i < k; i++)
	{
		scanf("%s %s %d", p1, p2, &w);
		u = getID(p1);
		v = getID(p2);
		G[u][v] = G[v][u] = w;
	}
	double ansDis = -1, ansAvg = INF;
	int ansId = -1;
	for (int i = n + 1; i <= n+m; i++)
	{
		double minDis = INF, avg = 0;
		Dijkstra(i);
		for (int j = 1; j <= n; j++)
		{
			if (d[j] > Ds)
			{
				minDis = -1; 
				break;
			}
			if (d[j] < minDis)
				minDis = d[j];
			avg += 1.0*d[j] / n;
		}
		if (minDis == -1) continue;
		if (minDis>ansDis)
		{
			ansId = i;
			ansDis = minDis;
			ansAvg = avg;
		}
		else if (minDis == ansDis && avg < ansAvg)
		{
			ansId = i;
			ansAvg = avg;
		}
	}
	if (ansId == -1) printf("No Solution\n");
	else
	{
		printf("G%d\n", ansId - n);
		printf("%.1f %.1f\n", ansDis, ansAvg);
	}
	return 0;
}