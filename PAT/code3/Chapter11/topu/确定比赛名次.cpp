#include "iostream"
#include "vector"
#include "queue"
using namespace std;
const int MAXN = 510;
int N, M;
vector<int> edge[MAXN];
int inDegree[MAXN] = { 0 };
struct cmp{
	bool operator () (int a, int b)
	{
		return a > b;
	}
};
priority_queue<int, vector<int>, cmp> q;

void topologicalSort()
{
	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int u = q.top();
		num++;
		if (num < N)
			printf("%d ", u);
		else if (num == N)
			printf("%d", u);
		q.pop();
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			inDegree[v]--;
			if (inDegree[v] == 0)
				q.push(v);
		}
		edge[u].clear();
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		inDegree[v]++;
	}
	topologicalSort();
	return 0;
}
