// 4.4 1 B1020(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
struct Info{
	double store, money;
	double cost;
}goods[1001];
bool cmp(Info a, Info b)
{
	return a.cost > b.cost;
}
int main()
{
	int n;
	double g;
	scanf("%d%lf", &n, &g);
	for (int i = 0; i < n; i++)
		scanf("%lf", &goods[i].store);
	for (int i = 0; i < n; i++)
		scanf("%lf", &goods[i].money);
	for (int i = 0; i < n; i++)
		goods[i].cost = goods[i].money / goods[i].store;
	sort(goods, goods + n, cmp);
	double total = 0;
	for (int i = 0; i < n; i++){
		if (goods[i].store <= g){
			g -= goods[i].store;
			total += goods[i].money;
		}
		else{
			total += goods[i].cost*g;
			break;
		}
	}
	printf("%.2f\n", total);
	return 0;
}

