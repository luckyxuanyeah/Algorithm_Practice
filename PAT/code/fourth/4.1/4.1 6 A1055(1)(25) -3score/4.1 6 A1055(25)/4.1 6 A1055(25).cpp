// 4.1 6 A1055(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct person{
	char name[9];
	int age, netWorth;
}per[maxn];
struct query{
	int num, age1, age2;
}que[maxn];
bool cmp1(person a, person b)
{
	return a.age > b.age;
}
bool cmp2(person a, person b)
{
	if (a.netWorth != b.netWorth) return a.netWorth > b.netWorth;
	else if (a.age != b.age) return a.age < b.age;
	else if (a.name != b.name) return strcmp(a.name, b.name) < 0;
}
bool judge(person a,int p,int q)
{
	return (a.age >= p && a.age <= q);
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s%d%d", per[i].name, &per[i].age, &per[i].netWorth);
	sort(per, per + n, cmp1);
	for (int i = 0; i < k; i++)
		scanf("%d%d%d", &que[i].num, &que[i].age1, &que[i].age2);
	for (int i = 0; i < k;i++){
		int m = 0, min = 0, max = 0;
		for (int j = 0; j < n; j++){
			if (judge(per[j], que[i].age1, que[i].age2) == true){
				min = j;
				break;
			}
		}
		for (int j = min; j < n;j++){
			if (judge(per[j], que[i].age1, que[i].age2) == true)
				m++;
		}
		max = min + m;
		sort(per + min, per + max, cmp2);
		if (m == 0){
			printf("Case #%d:\n", i + 1);
			printf("None\n");
		}
		else
		{
			printf("Case #%d:\n", i + 1);
			if (m < que[i].num)
				que[i].num = m;
			for (int j = 0; j < que[i].num; j++)
				printf("%s %d %d\n", per[j + min].name, per[j + min].age, per[j + min].netWorth);
		}
	}
	return 0;
}