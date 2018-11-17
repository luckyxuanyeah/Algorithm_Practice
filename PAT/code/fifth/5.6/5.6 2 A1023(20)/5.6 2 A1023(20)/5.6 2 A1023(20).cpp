// 5.6 2 A1023(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
struct bign{
	int d[1010];
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
bign multi(bign a, int b)
{
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}
void print(bign a)
{
	for (int i = a.len - 1; i >= 0; i--)
		printf("%d", a.d[i]);
}
int main()
{
	char str[21];
	scanf("%s", str);
	bign a = change(str);
	bign c = multi(a, 2);
	int count1[10] = {}, count2[10] = {};
	bool hash1[10] = { false }, hash2[10] = { false };
	for (int i = 0; i < a.len; i++)
	{
		count1[a.d[i]]++;
		hash1[a.d[i]] = true;
	}
	for (int i = 0; i < c.len; i++)
	{
		count2[c.d[i]]++;
		hash2[c.d[i]] = true;
	}
	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		if ((hash1[i] == true && hash2[i] == false) || (hash1[i] == false && hash2[i] == true))
		{
			printf("No\n");
			break;
		}
		else if (hash1[i] == hash2[i])
		{
			if (count1[i] == count2[i])
			{
				num = i;
				continue;
			}
			else if (count1[i] != count2[i])
			{
				printf("No\n");
				break;
			}
		}
	}
	if (num == 9) printf("Yes\n");
	print(c);
	return 0;
}