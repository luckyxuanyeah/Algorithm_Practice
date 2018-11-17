// 4.6 1 A1085(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
typedef long long ll;
const int maxn = 100001;
int d[maxn];
int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	sort(d, d + n);
	int count[maxn] = {};
	for (int i = 0; i < n; i++)
	{
		int j = n - 1;
		while (i <= j)
		{
			if ((ll)d[i] * p >= d[j])
			{
				count[i] = j - i + 1;
				break;
			}
			else if (d[i] * p < d[j])
				j--;
		}
	}
	int max = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (count[i]>max)
			max = count[i];
	}
	printf("%d\n", max);
	return 0;
}