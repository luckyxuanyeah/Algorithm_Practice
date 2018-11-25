#include "iostream"
#include "vector"
#include "queue"
using namespace std;

const int MAXN = 1010;
struct Node{
	int node;
	int layer;
};
vector<Node> edge[MAXN];
int query, N, L;
int Query[MAXN] = { 0 };
bool vis[MAXN] = { false };
int Output[MAXN] = { 0 };
void BFS(int u, int number)
{
	queue<Node> q;
	Node start;
	start.node = u;
	start.layer = 0;
	Output[number] = 0;
	q.push(start);
	vis[start.node] = true;
	while (!q.empty())
	{
		Node temp = q.front();
		q.pop();
		for (int i = 0; i < edge[temp.node].size(); i++)
		{
			edge[temp.node][i].layer = temp.layer + 1;
			if (vis[edge[temp.node][i].node] == false && edge[temp.node][i].layer < L)
			{
				q.push(edge[temp.node][i]);
				Output[number]++;
				vis[edge[temp.node][i].node] = true;
			}
			else if (vis[edge[temp.node][i].node] == false && edge[temp.node][i].layer == L)
			{
				vis[edge[temp.node][i].node] = true;
				Output[number]++;
			}
			if (edge[temp.node][i].layer > L)
			{
				q.pop();
				break;
			}
		}
	}
}

int main()
{
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
	{
		int number;
		cin >> number;
		Node now;
		now.node = i;
		now.layer = -1;
		for (int j = 0; j < number; j++)
		{
			Node temp;
			cin >> temp.node;
			temp.layer = -1;
			edge[temp.node].push_back(now);
		}
	}
	cin >> query;
	for (int i = 0; i < query; i++)
	{
		cin >> Query[i];
	}
	for (int i = 0; i < query;i++)
	{
		BFS(Query[i], i);
		cout << Output[i] << endl;
		for (int j = 0; j <= N; j++)
			vis[j] = false;
	}
	return 0;
}
