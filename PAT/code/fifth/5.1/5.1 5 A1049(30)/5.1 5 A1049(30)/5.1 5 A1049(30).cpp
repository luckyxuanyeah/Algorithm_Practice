// 5.1 5 A1049(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	scanf("%d", &n);
	int a = 1, ans = 0;
	int left, now, right;
	while (n/a != 0)
	{
		left = n / (a * 10);
		now = n / a % 10;
		right = n%a;
		if (now == 0) ans += left*a;
		else if (now == 1) ans += left*a + right + 1;
		else ans += (left + 1)*a;
		a *= 10;
	}
	printf("%d\n", ans);
	return 0;
}

