class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
{
	if (n <= 1)
		return {0};
	vector<unordered_set<int>> graph(n);
	for (int i = 0; i < edges.size(); i++)
	{
		graph[edges[i].first].insert(edges[i].second);
		graph[edges[i].second].insert(edges[i].first);
	}
	vector<int> current;
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].size() == 1)
			current.push_back(i);
	}
	while (true)
	{
		vector<int> next;
		for (int i:current)
		{
			for (int j:graph[i])
			{
				graph[j].erase(i);
				if (graph[j].size() == 1)
					next.push_back(j);
			}
		}
		if (next.empty())
			break;
		current = next;
	}
	return current;
}

};
//Runtime: 80 ms, faster than 63.73% of C++ online submissions for Minimum Height Trees.
//Memory Usage: 26.1 MB, less than 43.04% of C++ online submissions for Minimum Height Trees.
//Next challenges:Shortest Distance from All Buildings   Reconstruct Itinerary   Keys and Rooms
