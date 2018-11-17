// 5.1 3 A1104(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	double v, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &v);
		ans += v*i*(n + 1 - i);
	}
	printf("%.2f\n", ans);
	return 0;
}

