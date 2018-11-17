// 4.4 4 A1037(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}
int main()
{
	int nc, np;
	int c[100010] = {}, p[100010] = {};
	scanf("%d", &nc);
	int count1 = 0, count2 = 0;
	for (int i = 0; i < nc; i++){
		scanf("%d", &c[i]);
		if (c[i]<0)
			count1++;
	}
	scanf("%d", &np);
	for (int i = 0; i < np; i++){
		scanf("%d", &p[i]);
		if (p[i] < 0)
			count2++;
	}
	sort(c, c + nc, cmp);
	sort(p, p + np, cmp);
	int max = 0, j = 0;
	for (int i = 0; i < nc; i++)
	{
		if (c[i] < 0 && p[j] < 0){
			max = max + c[i] * p[j];
			j++;
		}
	}
	int k = nc-1, q = np-1;
	while (q >= count2 && k >= count1){
		max = c[k] * p[q] + max; 
		k--;
		q--;
	}
	printf("%d\n", max);
	return 0;
}

