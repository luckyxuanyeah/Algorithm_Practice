// 6.4 2 A1054(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "map"
using namespace std;
const int maxn = 17000000;
int main()
{
	int m, n, temp;
	scanf("%d%d", &m, &n);
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &temp);
			if (mp.find(temp) != mp.end()) mp[temp]++;
			else mp[temp] = 1;
		}
	}
	int large = 0, count = 0;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (large < it->second)
		{
			large = it->second;
			count = it->first;
		}
	}
	printf("%d\n", count);
	return 0;
}