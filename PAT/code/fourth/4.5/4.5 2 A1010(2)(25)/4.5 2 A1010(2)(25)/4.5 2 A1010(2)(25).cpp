// 4.5 2 A1010(2)(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
typedef long long ll;
ll map[256];
ll inf = (1ll << 63) - 1;
void init()
{
	for (char c = '0'; c <= '9'; c++)
		map[c] = c - '0';
	for (char c = 'a'; c <= 'z'; c++)
		map[c] = c - 'a' + 10;
}
ll convertNum10(char a[], ll radix, ll t)
{
	ll ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		ans = ans*radix + map[a[i]];
		if (ans<0 || ans>t) return -1;
	}
	return ans;
}
int cmp(char n2[], ll radix, ll t)
{
	int len = strlen(n2);
	ll num = convertNum10(n2, radix, t);
	if (num < 0) return 1;
	if (t>num) return -1;
	else if (t == num) return 0;
	else return 1;
}
ll binarySearch(char n2[], ll left, ll right, ll t)
{
	ll mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int flag = cmp(n2, mid, t);
		if (flag == 0) return mid;
		else if (flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
ll findLarge(char n2[])
{
	ll ans = -1;
	int len = strlen(n2);
	for (int i = 0; i < len; i++)
	{
		if (map[n2[i]]>ans)
			ans = map[n2[i]];
	}
	return ans + 1;
}
char n1[20], n2[20], temp[20];
int tag, radix;
int main()
{
	init();
	scanf("%s%s%d%d", n1, n2, &tag, &radix);
	if (tag == 2)
	{
		strcmp(temp, n1);
		strcmp(n1, n2);
		strcmp(n2, temp);
	}
	ll t = convertNum10(n1, radix, inf);
	ll low = findLarge(n2);
	ll high = max(low, t) + 1;
	ll ans = binarySearch(n2, low, high, t);
	if (ans == -1) printf("Impossible\n");
	else printf("%lld\n", ans);
	return 0;
}