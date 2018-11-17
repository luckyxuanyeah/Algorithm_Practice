// 5.4 3 A1015(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
const int maxn = 111;
bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
int d[maxn];
int main()
{
	int n, radix;
	while (scanf("%d", &n)!=EOF)
	{
		if (n < 0) break;
		scanf("%d", &radix);
		if (isPrime(n) == false)
			printf("No\n");
		else
		{
			int len = 0;
			do{
				d[len++] = n%radix;
				n /= radix;
			} while (n != 0);
			for (int i = 0; i < len; i++)
				n = n*radix + d[i];
			if (isPrime(n) == true) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

