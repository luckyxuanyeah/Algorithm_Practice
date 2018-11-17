// 9.3 1 A1053(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "vector"
#include "algorithm"
using namespace std;
const int maxn = 110;
struct node{
	int W;
	vector<int> child;
}Node[maxn];
int n, m, s;
int path[maxn];
bool cmp(int a, int b)
{
	return Node[a].W > Node[b].W;
}
void DFS(int index, int numNode, int nowSum)
{
	if (nowSum > s) return;
	if (nowSum == s)
	{
		if (Node[index].child.size() != 0) return;
		for (int i = 0; i < numNode; i++)
		{
			printf("%d", Node[path[i]].W);
			if (i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++)
	{
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, nowSum + Node[child].W);
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &Node[i].W);
	int id, k, number;
	for (int i = 0; i < m; i++){
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++){
			scanf("%d", &number);
			Node[id].child.push_back(number);
		}
		sort(Node[id].child.begin(), Node[id].child.end(), cmp);
	}
	path[0] = 0;
	DFS(0, 1, Node[0].W);
	return 0;
}

