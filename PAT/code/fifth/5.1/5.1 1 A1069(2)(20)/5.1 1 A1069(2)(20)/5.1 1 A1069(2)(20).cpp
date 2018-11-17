// 5.1 1 A1069(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
void to_array(int n, int num[])
{
	for (int i = 0; i < 4; i++)
	{
		num[i] = n % 10;
		n = n / 10;
	}
}
int to_number(int num[])
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum = sum * 10 + num[i];
	return sum;
}

int main()
{
	int n, min, max;
	scanf("%d", &n);
	int num[5];
	while (1)
	{
		to_array(n, num);
		sort(num, num + 4);
		min = to_number(num);
		sort(num, num + 4, cmp);
		max = to_number(num);
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);
		if (n == 6174 || n == 0) break;
	}
	return 0;
}

