#include <iostream>
#include "utility"
#include "algorithm"
#include "vector"
#include "queue"
using namespace std;

bool visit[3000] = { false };
int indegree[3000] = { 0 };
int number = 0;
void tuopu(int i, vector<int> G[], int& number)
{
	queue<int> q;
	q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		visit[u] = true;
		q.pop();
		for (int k = 0; k < G[u].size(); k++)
		{
			int v = G[u][k];
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);
		}
		G[u].clear();
		number++;
	}
}
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<int> G[3000];
	int num = prerequisites.size();
	for (int i = 0; i < num; i++)
	{
		int beg = prerequisites[i].second;
		int endd = prerequisites[i].first;
		if (find(G[beg].begin(), G[beg].end(), endd) == G[beg].end())
		{
			G[beg].push_back(endd);
			indegree[endd]++;
		}
	}
	for (int i = 0; i < numCourses; i++)
	{
		if (indegree[i] == 0 && visit[i] == false)
			tuopu(i, G, number);
	}
	if (number == numCourses)
		return true;
	else
		return false;
}
int main()
{
	vector<pair<int, int>> prerequisites;
	int numCourse;
	cin >> numCourse;
	pair<int, int> temp(1, 0);
	prerequisites.push_back(temp);
	pair<int, int> temp2(2, 1);
	prerequisites.push_back(temp2);
	bool ans = canFinish(numCourse, prerequisites);
	cout << ans << endl;
    return 0; 
}

//int num = prerequisites.size();
//int numbegin[10000], numend[10000];
//memset(numbegin, -1, sizeof(numbegin));
//memset(numend, -1, sizeof(numend));
//int count = 0;
//for (int i = 0; i < num; i++)
//{
//	if (numbegin[prerequisites[i].first] != -1)
//		continue;
//	else
//		numbegin[prerequisites[i].first] = prerequisites[i].first;
//	if (numend[prerequisites[i].second] != -1)
//		continue;
//	else
//		numend[prerequisites[i].second] = prerequisites[i].second;
//}
//for (int i = 0; i < numCourses; i++)
//{
//	if (numbegin[i] != -1 && numend[i] != -1)
//		count++;
//}
//if (count > 1)
//return false;
//else
//return true;

//Runtime: 20 ms, faster than 98.82% of C++ online submissions for Course Schedule.
//Memory Usage: 12.3 MB, less than 71.31% of C++ online submissions for Course Schedule.
//Next challenges:Course Schedule II   Graph Valid Tree   Minimum Height Trees  Course Schedule III
