// 5.6 3 A1024(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++)
		a.d[i] = str[a.len - i - 1] - '0';
	return a;
}
bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++)
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0)
		c.d[c.len++] = carry;
	return c;
}
bool judge(bign a)
{
	for (int i = 0; i <= a.len / 2; i++)
	{
		if (a.d[i] != a.d[a.len - i - 1])
			return false;
	}
	return true;
}
bign reverse(bign a)
{
	bign b;
	b.len = a.len;
	for (int i = 0; i < a.len; i++)
		b.d[i] = a.d[a.len - 1 - i];
	return b;
}
void print(bign a)
{
	for (int i = a.len - 1; i >= 0; i--)
		printf("%d", a.d[i]);
}
int main()
{
	char str[1000];
	int T, k = 0;
	scanf("%s%d", str, &T);
	bign a = change(str);
	while (judge(a) == false && k < T)
	{
		bign b = reverse(a);
		a = add(a, b);
		k++;
	}
	print(a);
	printf("\n%d\n", k);
	return 0;
}

