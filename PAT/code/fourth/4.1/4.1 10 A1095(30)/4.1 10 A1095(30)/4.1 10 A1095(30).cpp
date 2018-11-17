// 4.1 10 A1095(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "string"
#include <algorithm>	
#include <map>
using namespace std;
const int maxn = 10010;
struct Info{
	char plate_id[8];
	int time;
	char status[4];
}all[maxn], valid[maxn];
int num = 0;
bool cmp(Info a, Info b)
{
	int c = strcmp(a.plate_id, b.plate_id);
	if (c!=0) return c < 0;
	else return a.time < b.time;
}
map<string, int> parkTime;
int change(int hh, int mm, int ss)
{
	return hh * 3600 + mm * 60 + ss;
}
bool cmpTime(Info a, Info b)
{
	return a.time < b.time;
}
int main()
{
	int n, k, hh, mm, ss;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d:%d:%d %s", all[i].plate_id, &hh, &mm, &ss, all[i].status);
		all[i].time = change(hh, mm, ss);
	}
	sort(all, all + n, cmp);
	int maxTime = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if (!strcmp(all[i].plate_id, all[i + 1].plate_id) && !strcmp(all[i].status, "in")
			&& !strcmp(all[i + 1].status, "out"))
		{
			valid[num++] = all[i];
			valid[num++] = all[i + 1];
			int inTime = all[i + 1].time - all[i].time;
			if (parkTime.count(all[i].plate_id) == 0)
				parkTime[all[i].plate_id] = 0;
			parkTime[all[i].plate_id] += inTime;
			maxTime = max(maxTime, parkTime[all[i].plate_id]);
		}
	}
	sort(valid, valid + num, cmpTime);
	int now = 0, numCar = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = change(hh, mm, ss);
		while (now < num && valid[now].time <= time)
		{
			if (!strcmp(valid[now].status, "in")) numCar++;
			else numCar--;
			now++;
		}
		printf("%d\n", numCar);
	}
	map<string, int>::iterator it;
	for (it = parkTime.begin(); it != parkTime.end(); it++)
	{
		if (it->second == maxTime)
			printf("%s ", it->first.c_str());
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600/60, maxTime % 60);
	return 0;
}

