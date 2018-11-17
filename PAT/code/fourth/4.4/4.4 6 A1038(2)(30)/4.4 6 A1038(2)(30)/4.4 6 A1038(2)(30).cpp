// 4.4 6 A1038(2)(30).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 10010;
string s[maxn];
bool cmp(string a, string b)
{
	return a + b < b + a;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n, cmp);
	string ans;
	for (int i = 0; i < n; i++)
		ans += s[i];
	while (ans.size() != 0 && ans[0] == '0')
		ans.erase(ans.begin());
	if (ans.size() == 0) cout << 0;
	else cout << ans;
	return 0;
}

