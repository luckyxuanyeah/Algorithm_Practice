// 3.9 A1046(2).cpp : �������̨Ӧ�ó������ڵ㡣
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
		dis[i] = sum;//Ԥ����dis����
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

