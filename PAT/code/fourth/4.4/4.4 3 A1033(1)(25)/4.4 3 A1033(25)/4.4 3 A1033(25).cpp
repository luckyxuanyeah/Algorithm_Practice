// 4.4 3 A1033(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
struct Info{
	double Pi, Di;
}gas[510][\=
];
bool cmp(Info a, Info b)
{
	return a.Di < b.Di;
}
int main()
{
	double Cmax, D, Davg;
	int n;
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &gas[i].Pi, &gas[i].Di);
	sort(gas, gas + n, cmp);
	if (gas[0].Di != 0)
		printf("The maximum travel distance = 0.00\n");
	else{
		double maxPass = 0, maxTend = Cmax*Davg, minPrice = 0;
		int num = 0;
		while (maxPass < D){
			double price = 1000;
			int i = num, num2 = num;
			while (gas[i].Di <= maxTend)
				i++;
			for (int j = num2; j < i; j++)
			{
				if (gas[j].Pi < price){
					price = gas[j].Pi;
					num = j;
				}
			}
			minPrice = gas[num2].Pi*gas[num].Di + minPrice;
			maxPass = gas[num].Di + maxPass;
			maxTend = maxTend + gas[num].Di;
			if (maxPass < D && num==n-1){
				printf("The maximum travel distance = %.2f\n", maxPass);
				break;
			}
		}
		if (maxPass==D)
			printf("%.2f\n", minPrice);
	}
	return 0;
}

