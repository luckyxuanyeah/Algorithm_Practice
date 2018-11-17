// 5.3 1 A1081(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "algorithm"
using namespace std;
typedef long long ll;
struct Fraction{
	ll up, down;
}f[110], sum;
ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}
Fraction reduction(Fraction a)
{
	if (a.up == 0) a.down = 1;
	else
	{
		int d = gcd(abs(a.up), abs(a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}
Fraction add(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.down + b.up*a.down;
	result.down = a.down*b.down;
	return reduction(result);
}
int main()
{
	int n;
	scanf("%d", &n);
	sum.up = 0, sum.down = 1;
	for (int i = 0; i < n; i++){

		scanf("%lld/%lld", &f[i].up, &f[i].down);
		sum = add(f[i], sum);
	}
	if (sum.down == 1) printf("%lld\n", sum.up);
	else if (abs(sum.up)>sum.down && sum.up%sum.down != 0)
		printf("%lld %lld/%lld\n", sum.up / sum.down, sum.up%sum.down, sum.down);
	else printf("%lld/%lld\n", sum.up, sum.down);
	return 0;
}

