// 4.4 3 A1033(2)(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct station{
	double price, dis;
}st[maxn];
bool cmp(station a, station b)
{
	return a.dis < b.dis;
}
int main()
{
	int n;
	double Cmax, D, Davg;
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &st[i].price, &st[i].dis);
	st[n].dis = D;
	st[n].price = 0;
	sort(st, st + n, cmp);
	if (st[0].dis != 0)
		printf("The maximum travel distance = 0.00\n");
	else{
		int now = 0;
		double Max = Cmax*Davg, ans = 0, nowTank = 0;
		while (now < n)
		{
			int k = -1;
			double priceMin = INF;
			for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= Max; i++)
			{
				if (st[i].price < priceMin)
				{
					priceMin = st[i].price;
					k = i;
					if (priceMin < st[now].price)
						break;
				}
			}
			if (k == -1)
				break;
			double need = (st[k].dis - st[now].dis) / Davg;
			if (priceMin < st[now].price)
			{
				if (nowTank < need)
				{
					ans += (need - nowTank)*st[now].price;
					nowTank = 0;
				}
				else{
					nowTank -= need;
				}
			}
			else{
				ans += (Cmax - nowTank)*st[now].price;
				nowTank = Cmax - need;
			}
			now = k;
		}
		if (now == n)
			printf("%.2f\n", ans);
		else
			printf("The maximun travel distance = %.2f\n", st[now].dis + Max);
	}
	return 0;
}

