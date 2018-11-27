#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

const int MAXV = 1010;
const int INF = 1000000000;
int n, e, s;
struct Node{
	int node, edge;
};
vector<Node> Edge[MAXV];
bool vis[MAXV] = { false };
int dis[MAXV];
void Dijkstra()
{
	fill(dis, dis + MAXV, INF);
	dis[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int min = INF, next = -1;
		for (int j = 0; j < n; j++)
		{
			if (dis[j] < min && vis[j] == false)
			{
				min = dis[j];
				next = j;
			}
		}
		if (next == -1)
			return;
		vis[next] = true;
		for (int j = 0; j < Edge[next].size(); j++)
		{
			int v = Edge[next][j].node;
			if (vis[v] == false && dis[next] + Edge[next][j].edge < dis[v])
				dis[v] = dis[next] + Edge[next][j].edge;
		}
	}
}
int main()
{
	cin >> n >> e >> s;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		Node temp;
		temp.node = v;
		temp.edge = w;
		Edge[u].push_back(temp);
	}
	Dijkstra();
	for (int i = 0; i < n; i++)
	{
		cout << dis[i] << endl;
	}
	return 0;
}
