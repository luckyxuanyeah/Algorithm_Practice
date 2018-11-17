// haha1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int T;
	long long a, b, c;
	scanf("%d", &T);
	int i = 1;
	while (T--)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a + b > c)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
		i++;
	}
	return 0;
}
