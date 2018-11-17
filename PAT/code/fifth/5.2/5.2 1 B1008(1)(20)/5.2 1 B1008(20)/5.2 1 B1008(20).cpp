// 5.2 1 B1008(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}
const int maxn = 110;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a[maxn];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	m = m % n;
	int d = gcd(n, m);
	bool hash[maxn] = { false };
	int count = 0;
	if (m != 0){
		for (int i = n - m; i < n - m + d; i++)
		{
			int temp = a[i];
			while (hash[i] == false)
			{
				a[i] = a[(i - m + n) % n];
				hash[i] = true;
				i = (i - m + n) % n;
				count = i;
			}
			a[(count + m + n) % n] = temp;
		}
	}
	for (int i = 0; i < n; i++){
		printf("%d", a[i]);
		if (i < n - 1) printf(" ");
		else printf("\n");
	}
	return 0;
}

