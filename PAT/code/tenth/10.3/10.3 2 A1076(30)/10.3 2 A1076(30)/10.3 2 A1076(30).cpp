// 10.3 2 A1076(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "queue"
#include "vector"
using namespace std;
const int maxn = 1010;
struct node{
	int id;
	int layer;
};
vector<node> Adj[maxn];
bool inq[maxn] = { false };
int n, l, k;
int BFS(int s, int L)
{
	int numForward = 0;
	queue<node> q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while (!q.empty())
	{
		node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for (int i = 0; i < Adj[u].size(); i++)
		{
			node next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if (inq[next.id] == false && next.layer<=L)
			{
				q.push(next);
				inq[next.id] = true;
				numForward++;
			}
		}
	}
	return numForward;
}
int main()
{
	scanf("%d%d", &n, &l);
	node temp;
	int numFollow, idFollow;
	for (int i = 1; i <= n; i++)
	{
		temp.id = i;
		scanf("%d", &numFollow);
		for (int j = 0; j < numFollow; j++)
		{
			scanf("%d", &idFollow);
			Adj[idFollow].push_back(temp);
		}
	}
	int numQuery, s;
	scanf("%d", &numQuery);
	for (int i = 0; i < numQuery; i++)
	{
		memset(inq, false, sizeof(inq));
		scanf("%d", &s);
		int numForward = BFS(s, l);
		printf("%d\n", numForward);
	}
	return 0;
}

