// 3.2 5 A1011(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
struct Info{
	double w, t, l;
}game[3];

double max(double a,double b,double c)
{
	double temp = b;
	if (b < a)
		temp = a;
	if (temp < c)
		temp = c;
	return temp;
}

char maxnum(double a, double b, double c)
{
	double temp = b;
	char num = 'T';
	if (b < a)
	{
		temp = a;
		num = 'W';
	}
	if (temp < c)
	{
		temp = c;
		num = 'L';
	}
	return num;
}

int main()
{
	for (int i = 0; i < 3; i++)
		scanf("%lf%lf%lf", &game[i].w, &game[i].t, &game[i].l);
	double maxn[3] = {};
	char maxnumber[3] = {};
	for (int i = 0; i < 3; i++)
	{
		maxn[i] = max(game[i].w, game[i].t, game[i].l);
		maxnumber[i] = maxnum(game[i].w, game[i].t, game[i].l);
	}	
	double profit = (maxn[0] * maxn[1] * maxn[2] * 0.65 -1) * 2;
	printf("%c %c %c %.2f", maxnumber[0], maxnumber[1], maxnumber[2], profit);
	return 0;
}

