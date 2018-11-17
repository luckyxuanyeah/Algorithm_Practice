// 3.4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int n;
	scanf("%d", &n);
	int a1, a2, b1, b2;
	int c=0, d=0;
	while (n--)
	{
		scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
		if (a1 + b1 == a2&&a1 + b1 != b2)
			d++;
		if (a1 + b1 == b2&&a1 + b1 != a2)
			c++;
	}
	printf("%d %d", c, d);
	return 0;
}

