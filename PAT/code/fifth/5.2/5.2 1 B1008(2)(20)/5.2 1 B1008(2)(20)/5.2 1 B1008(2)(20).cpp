// 5.2 1 B1008(2)(20).cpp : 定义控制台应用程序的入口点。
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
	int pos, next, temp;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	m = m%n;
	if (m != 0)
	{
		int d = gcd(n, m);
		for (int i = n - m; i < n - m + d; i++)
		{
			temp = a[i];
			pos = i;
			do{
				next = (pos - m + n) % n;
				if (next != i) a[pos] = a[next];
				else a[pos] = temp;
				pos = next;
			} while (pos != i);
		}
	}
	for (int i = 0; i < n; i++){
		printf("%d", a[i]);
		if (i < n - 1) printf(" ");
	}
	return 0;
}

