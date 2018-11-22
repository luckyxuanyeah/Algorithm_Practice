#include "iostream"
#include "vector"
#include "map"
#include "string"
using namespace std;

const int MAXV = 2010; //注意最大人数为2000（通话记录有1000个，因此可能有2000个人）
const int INF = 1000000000; //设置为无穷大
int Edge[MAXV][MAXV] = { 0 };
bool vis[MAXV] = { false };
bool visEdge[MAXV][MAXV] = { false };
map<string, int> mp;
map<int, string> mp2;
vector<int> NodeInDFS;
int NodeWeight[MAXV] = { 0 };
map<string, int> gangNameToNumber;
struct Node{
	string name;
	string endName;
	int time;
};
int sumNode, sumEdge, gangMax, gangHead;
void DFS(int u, int num)
{
	NodeInDFS.push_back(u);
	vis[u] = true;
	if (gangMax < NodeWeight[u])
	{
		gangMax = NodeWeight[u];
		gangHead = u;
	}
	for (int i = 1; i <= num; i++)
	{
		if (Edge[u][i] != 0 && vis[i] == false)
		{
			visEdge[u][i] = true;
			visEdge[i][u] = true;
			sumNode++;
			sumEdge += Edge[u][i];
			DFS(i, num);
		}
	}
}
void DFSTrave(int num,int MAX)
{
	for (int u = 1; u <= num; u++)
	{
		if (vis[u] == false)
		{
			NodeInDFS.clear();
			sumNode = 1;
			sumEdge = gangMax = gangHead = 0;
			DFS(u, num);
			for (int i = 0; i < NodeInDFS.size(); i++)
			{
				for (int j = 0; j < NodeInDFS.size(); j++)
				{
					if (Edge[NodeInDFS[i]][NodeInDFS[j]] != 0 && visEdge[NodeInDFS[i]][NodeInDFS[j]] == false)
					{
						sumEdge += Edge[NodeInDFS[i]][NodeInDFS[j]];
						visEdge[NodeInDFS[i]][NodeInDFS[j]] = true;
						visEdge[NodeInDFS[i]][NodeInDFS[j]] = true;
					}
				}
			}
			if (sumNode > 2 && sumEdge > MAX)
				gangNameToNumber[mp2[gangHead]] = sumNode;
		}
	}
}
int main()
{
	int N, K, count = 0;
	vector<Node> InitialArray;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		Node temp;
		cin >> temp.name >> temp.endName >> temp.time;
		if (mp.count(temp.name) == 0)
		{
			mp[temp.name] = ++count;
			mp2[count] = temp.name;
		}
		if (mp.count(temp.endName) == 0)
		{
			mp[temp.endName] = ++count;
			mp2[count] = temp.endName;
		}
		if (InitialArray.size() != 0)
		{
			bool isDul = false;
			for (int j = 0; j < InitialArray.size(); j++)
			{
				if ((InitialArray[j].name == temp.name&&InitialArray[j].endName == temp.endName) || (InitialArray[j].name == temp.endName&&InitialArray[j].endName == temp.name))
				{
					InitialArray[j].time += temp.time;
					isDul = true;
				}
			}
			if (isDul == false)
				InitialArray.push_back(temp);
		}
		else
			InitialArray.push_back(temp);
	}
	for (int i = 0; i < InitialArray.size(); i++)
	{
		Edge[mp[InitialArray[i].name]][mp[InitialArray[i].endName]] = InitialArray[i].time;
		Edge[mp[InitialArray[i].endName]][mp[InitialArray[i].name]] = InitialArray[i].time;
		NodeWeight[mp[InitialArray[i].name]] += InitialArray[i].time;
		NodeWeight[mp[InitialArray[i].endName]] += InitialArray[i].time;
	}
	DFSTrave(count,K);
	cout << gangNameToNumber.size() << endl;
	if (gangNameToNumber.size() != 0)
	{
		for (map<string, int>::iterator it = gangNameToNumber.begin(); it != gangNameToNumber.end(); it++)
			cout << it->first << " " << it->second << endl;
	}
	return 0;
}
