// 4.6 4 A1048(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int maxn = 100010;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a[maxn];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int j = 0, k = n - 1;
	while (j < k)
	{
		if (a[j] + a[k]>m)
			k--;
		else if (a[j] + a[k] < m)
			j++;
		else if (a[j] + a[k] == m)
		{
			printf("%d %d\n", a[j], a[k]);
			break;
		}
	}
	if (j == k)
		printf("No Solution\n");
	return 0;
}

