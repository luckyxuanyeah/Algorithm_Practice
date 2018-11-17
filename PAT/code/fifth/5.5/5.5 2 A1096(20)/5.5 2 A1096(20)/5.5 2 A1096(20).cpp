// 5.5 2 A1096(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "algorithm"

typedef long long ll;
int main()
{
	ll n;
	scanf("%lld", &n);
	ll sqr = (ll)sqrt(1.0*n);
	ll ansI = 0, ansLen = 0;
	for (ll i = 2; i <= sqr; i++)
	{
		ll temp = 1, j = i;
		while (1)
		{
			temp *= j;
			if (n%temp != 0) break;
			if (j - i + 1 > ansLen)
			{
				ansI = i;
				ansLen = j - i + 1;
			}
			j++;
		}
	}
	if (ansLen == 0)
		printf("1\n%lld", n);
	else
	{
		printf("%lld\n", ansLen);
		for (ll i = 0; i < ansLen; i++)
		{
			printf("%lld", ansI + i);
			if (i < ansLen - 1)
				printf("*");
		}
	}
	return 0;
}