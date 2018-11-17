// 4.4 6 A1038(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 10010;
bool cmp(string a, string b)
{
	return a < b;
}
int main()
{
	int n;
	scanf("%d", &n);
	string a[maxn];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, cmp);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		while (a[i][num] == a[i + 1][num])
			num++;
		if (a[i + 1][num] < a[i][0])
			swap(a[i], a[i + 1]);
	}
	if (a[0][0] == '0')
	{
		int len = a[0].length();
		for (int i = 0; i < len; i++)
			a[0][i] = a[0][i + 1];
	}
	string ans;
	for (int i = 0; i < n; i++)
		ans = ans + a[i];
	cout << ans;
	return 0;
}

