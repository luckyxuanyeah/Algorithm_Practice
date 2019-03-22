class Solution {
public:
   bool isBipartite(vector<vector<int>>& graph) 
{
	int visit[110] = { 0 }, mark[110] = { 0 };
	bool judge = true;
	int n = graph.size();
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			queue<int> q;
			q.push(i);
			mark[i] = 1;
			visit[i] = 1;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int v = 0; v < graph[u].size(); v++)
				{
					if (visit[graph[u][v]] == 0)
					{
						if (mark[u] == 1)
							mark[graph[u][v]] = -1;
						else if(mark[u]==-1)
							mark[graph[u][v]] = 1;
						visit[graph[u][v]] = 1;
						q.push(graph[u][v]);
					}
					else if (visit[graph[u][v]] == 1)
					{
						if (mark[u] == mark[graph[u][v]])
						{
							judge = false;
							break;
						}
					}
				}
				if (judge == false)
					break;
			}
		}
	}
	return judge;
}
};

//Runtime: 28 ms, faster than 80.87% of C++ online submissions for Is Graph Bipartite?.
//Memory Usage: 12.2 MB, less than 18.18% of C++ online submissions for Is Graph Bipartite?.
//Next challenges:Word Ladder II  Nested List Weight Sum II  Robot Room Cleaner
