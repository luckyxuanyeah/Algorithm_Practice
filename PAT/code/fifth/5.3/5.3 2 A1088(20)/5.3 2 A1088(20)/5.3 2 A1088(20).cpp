// 5.3 2 A1088(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
typedef long long ll;
struct Fraction
{
	ll up, down;
}a, b;
ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}
Fraction reduction(Fraction result)
{
	if (result.down < 0){
		result.up = -result.up;
		result.down = -result.down;
	}
	if (result.up == 0) result.down = 1;
	else {
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}
Fraction add(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.down + b.up*a.down;
	result.down = a.down*b.down;
	return reduction(result);
}
Fraction subtract(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.down - b.up*a.down;
	result.down = a.down*b.down;
	return reduction(result);
}
Fraction product(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.up;
	result.down = a.down*b.down;
	return reduction(result);
}
Fraction devition(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.down;
	result.down = a.down*b.up;
	return reduction(result);
}
void show(Fraction r)
{
	r = reduction(r);
	if (r.up < 0) printf("(");
	if (r.down == 1) printf("%lld", r.up);
	else if (abs(r.up)>r.down) printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	else printf("%lld/%lld", r.up, r.down);
	if (r.up < 0) printf(")");
}
int main()
{
	scanf("%lld/%lld", &a.up, &a.down);
	scanf("%lld/%lld", &b.up, &b.down);
	show(a);
	printf(" + ");
	show(b);
	printf(" = ");
	show(add(a, b));
	printf("\n");
	show(a);
	printf(" - ");
	show(b);
	printf(" = ");
	show(subtract(a, b));
	printf("\n");
	show(a);
	printf(" * ");
	show(b);
	printf(" = ");
	show(product(a, b));
	printf("\n");
	show(a);
	printf(" / ");
	show(b);
	printf(" = ");
	if (b.up == 0) printf("Inf");
	else show(devition(a, b));
	printf("\n");
	return 0;
}

