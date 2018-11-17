// 9.3 1 A1079(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "vector"
using namespace std;
const int maxn = 100010;
int n;
double p, r, ans = 0;
struct node{
	double data;
	vector<int> child;
}Node[maxn];
void DFS(int index,int depth)
{
	if (Node[index].child.size() == 0)
	{
		ans += Node[index].data*pow(1 + r, depth);
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++)
		DFS(Node[index].child[i], depth + 1);
}
int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	int number, id;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		if (number == 0)
			scanf("%lf", &Node[i].data);
		else
		{
			for (int j = 0; j < number; j++){
				scanf("%d", &id);
				Node[i].child.push_back(id);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f\n", p*ans);
	return 0;
}

