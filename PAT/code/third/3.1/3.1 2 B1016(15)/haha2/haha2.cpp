// haha2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	long long A, B;
	int Da, Db;
	long long pa = 0, pb = 0;
	scanf("%lld%d%lld%d", &A, &Da, &B, &Db);
	int a = 0, b = 0;
	while (A != 0)
	{
		if (A % 10 == Da)
			pa = pa * 10 + Da;
		A = A / 10;
	}
	while (B != 0)
	{
		if (B % 10 == Db)
			pb = pb * 10 + Db;
		B = B / 10;
	}
	printf("%lld\n", pa+pb);
	return 0;
}