#include <iostream>
#include "utility"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

vector<int> ans;
int number = 0;
vector<int> G[3000];
bool visit[3000] = { false };
int degree[3000] = { 0 };

void tuopu(int i, vector<pair<int, int>>& prerequisites,int& number)
{
	queue<int> q;
	q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		visit[u] = true;
		ans.push_back(u);
		q.pop();
		for (int k = 0; k < G[u].size(); k++)
		{
			int v = G[u][k];
			degree[v]--;
			if (degree[v] == 0)
				q.push(v);
		}
		G[u].clear();
		number++;
	}
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
	for (int i = 0; i < prerequisites.size(); i++)
	{
		int yi = prerequisites[i].first;
		int er = prerequisites[i].second;
		if (find(G[er].begin(), G[er].end(), yi) == G[er].end())
		{
			G[er].push_back(yi);
			degree[yi]++;
		}
	}
	for (int i = 0; i < numCourses; i++)
	{
		if (visit[i] == false && degree[i] == 0)
			tuopu(i, prerequisites, number);
	}
	if(number==numCourses)
		return ans;
	else
	{
		vector<int> kong;
		return kong;
	}
}

int main()
{
	int numCourses;
	cin >> numCourses;
	vector<pair<int, int>> prerequisites;
	pair<int, int> temp1(1,0);
	prerequisites.push_back(temp1);
	pair<int, int> temp2(2,0);
	prerequisites.push_back(temp2);
	pair<int, int> temp3(3,1);
	prerequisites.push_back(temp3);
	pair<int, int> temp4(3,2);
	prerequisites.push_back(temp4);
	vector<int> ans1 = findOrder(numCourses, prerequisites);
	for (int i = 0; i < ans.size(); i++)
		cout << ans1[i] << endl;
	return 0;
}

//Runtime: 24 ms, faster than 92.18% of C++ online submissions for Course Schedule II.
//Memory Usage: 12.6 MB, less than 68.42% of C++ online submissions for Course Schedule II.
//Next challenges:Alien Dictionary  Minimum Height Tree  Sequence Reconstruction  Course Schedule III
