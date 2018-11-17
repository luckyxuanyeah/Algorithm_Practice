// 5.5 1 A1059(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
using namespace std;
const int maxn = 100010;
bool isPrime(int n)
{
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int prime[maxn], pNum = 0;
void Find_Prime()
{
	for (int i = 1; i < maxn; i++)
	{
		if (isPrime(i) == true)
			prime[pNum++] = i;
	}
}
struct factor{
	int x, cnt;
}fac[10];
int main()
{
	Find_Prime();
	int num = 0;
	long long n;
	scanf("%lld", &n);
	long long sum = n;
	for (int i = 0; i < 10; i++){
		fac[i].cnt = 0;
		fac[i].x = 0;
	}
	int sqr = (int)sqrt(1.0*n);
	for (int i = 0; i < pNum && prime[i] <= sqr; i++)
	{
		if (n % prime[i] == 0)
		{
			fac[num].x = prime[i];
			fac[num].cnt = 1;
			n = n / prime[i];
			while (n%prime[i] == 0)
			{
				fac[num].cnt++;
				n = n / prime[i];
			}
			num++;
		}
	}
	bool change = false;
	if (n != 1)
	{
		fac[num].x = n;
		fac[num].cnt = 1;
		change = true;
		num++;
	}
	if (sum == 1)
		printf("1=1");
	else
	{
		printf("%lld=", sum);
		for (int i = 0; i < num; i++)
		{
			if (fac[i].cnt>1)
				printf("%d^%d", fac[i].x, fac[i].cnt);
			else if (fac[i].cnt == 1) printf("%d", fac[i].x);
			if (i < num - 1) printf("*");
		}
	}
	return 0;
}