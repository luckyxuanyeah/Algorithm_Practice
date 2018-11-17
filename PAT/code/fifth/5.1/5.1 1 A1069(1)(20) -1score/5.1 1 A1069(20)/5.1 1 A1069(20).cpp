// 5.1 1 A1069(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
bool cmp_increase(int a, int b)
{
	return a < b;
}
bool cmp_decrease(int c, int d)
{
	return c > d;
}
int main()
{
	int n;
	scanf("%d", &n);
	int ans = n;
	int a[4] = {};
	int i = 0;
	while(n!=0)
	{
		a[i] = n % 10;
		n = n / 10;
		i++;
	}
	if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3])
		printf("%04d - %04d = %04d\n", ans, ans,ans-ans);
	else
	{
		while (ans != 6174)
		{
			int b[4] = {};
			int j = 0;
			while (ans != 0)
			{
				b[j] = ans % 10;
				ans = ans / 10;
				j++;
			}
			sort(b, b + 4, cmp_decrease);
			int ans1 = 0, ans2 = 0;
			for (int k = 0; k < 4; k++)
				ans1 = ans1 * 10 + b[k];
			sort(b, b + 4, cmp_increase);
			for (int k = 0; k < 4; k++)
				ans2 = ans2 * 10 + b[k];
			ans = ans1 - ans2;
			printf("%04d - %04d = %04d\n", ans1, ans2, ans);
		}
	}
	return 0;
}

