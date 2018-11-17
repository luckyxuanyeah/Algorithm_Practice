// 4.1 6 A1055(2)(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
const int maxn = 100010;
struct person{
	char name[9];
	int age, netWorth;
}per[maxn], valid[maxn];
int age[maxn] = { 0 };
bool cmp(person a, person b)
{
	if (a.netWorth != b.netWorth) return a.netWorth > b.netWorth;
	else if (a.age != b.age) return a.age < b.age;
	else if (a.name != b.name) return strcmp(a.name, b.name) < 0;
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s%d%d", &per[i].name, &per[i].age, &per[i].netWorth);
	sort(per, per + n, cmp);
	int validnum = 0;
	for (int i = 0; i < n; i++)
	{
		if (age[per[i].age] < 100)
		{
			age[per[i].age]++;
			valid[validnum++] = per[i];
		}
	}
	int m, age1, age2;
	for (int i = 1; i <= k; i++){
		scanf("%d%d%d", &m, &age1, &age2);
		printf("Case #%d:\n", i);
		int printNum = 0;
		for (int j = 0; j < validnum && printNum < m; j++)
		{
			if (valid[j].age >= age1 && valid[j].age <= age2)
			{
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].netWorth);
				printNum++;
			}
		}
		if (printNum == 0)
			printf("None\n");
	}
	return 0;
}

