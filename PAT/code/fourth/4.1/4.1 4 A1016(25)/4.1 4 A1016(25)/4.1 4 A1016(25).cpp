// 4.1 4 A1016(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;

int toll[25];
struct people{
	char name[22];
	int month, dd, hh, mm;
	bool status;
}per[1010],temp;
bool cmp(people a, people b)
{
	int s= strcmp(a.name, b.name);
	if (s != 0) return s < 0;
	else if (a.month != b.month) return a.month<b.month;
	else if (a.dd != b.dd) return a.dd < b.dd;
	else if (a.hh != b.hh) return a.hh < b.hh;
	else return a.mm < b.mm;
}
void getsans(int on, int off, int& time, int& money)
{
	temp = per[on];
	while (temp.dd < per[off].dd || temp.hh < per[off].hh || temp.mm < per[off].mm)
	{
		time++;
		money += toll[temp.hh];
		temp.mm++;
		if (temp.mm >= 60)
		{
			temp.mm = 0;
			temp.hh++;
		}
		if (temp.hh >= 24)
		{
			temp.hh = 0;
			temp.dd++;
		}
	}
}
int main()
{
	for (int i = 0; i < 24; i++)
		scanf("%d", &toll[i]);
	int n;
	scanf("%d", &n);
	char line[10];
	for (int i = 0; i < n; i++){
		scanf("%s", per[i].name);
		scanf("%d:%d:%d:%d", &per[i].month, &per[i].dd, &per[i].hh, &per[i].mm);
		scanf("%s", line);
		if (strcmp(line, "on-line") == 0)
			per[i].status = true;
		else per[i].status = false;
	}
	sort(per, per + n, cmp);
	int on = 0, off, next;
	while (on<n)
	{
		int needPrint = 0;
		next = on;
		while (next < n && strcmp(per[next].name, per[on].name) == 0)
		{
			if (needPrint == 0 && per[next].status == true)
				needPrint = 1;
			else if (needPrint == 1 && per[next].status == false)
				needPrint = 2;
			next++;
		}
		if (needPrint < 2)
		{
			on = next;
			continue;
		}
		int allmoney = 0;
		printf("%s ", per[on].name);
		printf("%02d\n", per[on].month);
		while (on < next)
		{
			while (on < next - 1 && !(per[on].status == true && per[on + 1].status == false))
				on++;
			off = on + 1;
			if (off == next)
			{
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", per[on].dd, per[on].hh, per[on].mm);
			printf("%02d:%02d:%02d ", per[off].dd, per[off].hh, per[off].mm);
			int time = 0, money = 0;
			getsans(on, off, time, money);
			allmoney += money;
			printf("%d $%.2f\n", time, money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", allmoney / 100.0);
	}
	return 0;
}

