#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct Node{
	int node, edge;
};
const int MAXN = 510;
const int INF = 1000000000;
int N, M, C1, C2;
int NodeNumber[MAXN] = { 0 };
vector<Node> Edge[MAXN];
int NodeW[MAXN];
int dis[MAXN];
int MaxNum[MAXN] = { 0 };
int PathNum[MAXN] = { 0 };
bool vis[MAXN] = { false };
void Dijkstra()
{
	fill(dis, dis + MAXN, INF);
	fill(MaxNum, MaxNum + MAXN, 0);
	fill(PathNum, PathNum + MAXN, 0);
	dis[C1] = 0;
	MaxNum[C1] = NodeW[C1];
	PathNum[C1] = 1;
	for (int i = 0; i < N; i++)
	{
		int min = INF;
		int u = -1;
		for (int j = 0; j < N; j++)
		{
			if (dis[j] < min && vis[j] == false)
			{
				min = dis[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int j = 0; j < Edge[u].size(); j++)
		{
			int v = Edge[u][j].node;
			if (vis[v] == false)
			{
				if (dis[u] + Edge[u][j].edge < dis[v])
				{
					dis[v] = dis[u] + Edge[u][j].edge;
					MaxNum[v] = MaxNum[u] + NodeW[v];
					PathNum[v] = PathNum[u];
				}
				else if (dis[u] + Edge[u][j].edge == dis[v])
				{
					PathNum[v] = PathNum[u] + PathNum[v];
					if (MaxNum[v] < MaxNum[u] + NodeW[v])
					{
						MaxNum[v] = MaxNum[u] + NodeW[v];
					}
				}
			}
		}
	}
}
int main()
{
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++)
		cin >> NodeW[i];
	for (int i = 0; i < M; i++)
	{
		int c1, c2, l;
		Node temp1, temp2;
		cin >> c1 >> c2 >> l;
		temp1.node = c2;
		temp1.edge = l;
		Edge[c1].push_back(temp1);
		temp2.node = c1;
		temp2.edge = l;
		Edge[c2].push_back(temp2);
	}
	Dijkstra();
	cout << PathNum[C2] << " " << MaxNum[C2] << endl;
	return 0;
}
