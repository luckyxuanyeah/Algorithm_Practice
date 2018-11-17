// 9.3 5 A1106(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "vector"
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
int n;
double p, r;
int minDepth = maxn, num = 0;
void DFS(int index, int depth)
{
	if (child[index].size() == 0)
	{
		if (depth < minDepth)
		{
			minDepth = depth;
			num = 1;
		}
		else if (depth == minDepth)
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
	int k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		int id;
		if (k == 0)
			child[i].size() == 0;
		else{
			for (int j = 0; j < k; j++)
			{
				scanf("%d", &id);
				child[i].push_back(id);
			}
		}
	}
	DFS(0, 0);
	printf("%.4f %d\n", p*pow(1 + r, minDepth), num);
	return 0;
}

