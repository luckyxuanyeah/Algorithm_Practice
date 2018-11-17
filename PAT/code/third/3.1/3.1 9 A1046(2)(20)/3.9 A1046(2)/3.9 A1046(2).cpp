// 3.9 A1046(2).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int MAX = 100005;

int main()
{
	int n,sum=0;
	scanf("%d", &n);
	int dis[MAX] = {}, a[MAX];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum = sum + a[i];
		dis[i] = sum;//预处理dis数组
	}
	int query,left,right;
	scanf("%d", &query);
	for (int j = 0; j < query; j++)
	{
		scanf("%d%d", &left, &right);
		if (left>right)
			swap(left, right);
		int temp = dis[right-1] - dis[left-1];
		printf("%d\n", min(temp, sum - temp));
	}
	return 0;
}

