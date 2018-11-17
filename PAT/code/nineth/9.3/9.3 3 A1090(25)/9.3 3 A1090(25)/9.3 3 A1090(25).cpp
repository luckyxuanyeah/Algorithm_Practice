// 9.3 3 A1090(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "vector"
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
int n, maxDepth = 0, num = 0;
double p, r;
void DFS(int index,int depth)
{
	if (child[index].size() == 0){
		if (depth > maxDepth)
		{
			maxDepth = depth;
			num = 1;
		}
		else if (depth == maxDepth)
			num++;
		return;
	}
	for (int i = 0; i < child[index].size(); i++)
		DFS(child[index][i], depth + 1);
}
int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	int father, root;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &father);
		if (father == -1)
			root = i;
		else
			child[father].push_back(i);
	}
	DFS(root, 0);
	printf("%.2f %d\n", p*pow(1 + r, maxDepth), num);
	return 0;
}

