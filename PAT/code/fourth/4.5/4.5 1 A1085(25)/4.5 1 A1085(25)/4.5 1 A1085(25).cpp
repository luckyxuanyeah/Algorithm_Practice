// 4.5 1 A1085(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;

const int maxn = 100001;
int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	int a[maxn];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int j = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
		ans = max(ans, j - i);
	}
	printf("%d\n", ans);
	return 0;
}