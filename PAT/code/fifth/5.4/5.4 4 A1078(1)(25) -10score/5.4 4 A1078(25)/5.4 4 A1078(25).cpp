// 5.4 4 A1078(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "vector"
using namespace std;
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
const int maxn = 11111;
int main()
{
	int MSize, n;
	int a[maxn];
	scanf("%d%d", &MSize, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while(isPrime(MSize) == false)
		MSize++;
	bool Yes[maxn] = { false };
	char b[maxn] = {};
	for (int i = 0; i < n; i++)
	{
		if (Yes[a[i] % MSize] == false)
		{
			Yes[a[i] % MSize] = true;
			b[i] = a[i] % MSize + '0';
		}
		else if (Yes[a[i] % MSize] == true)
		{
			int j = 1;
			while (Yes[(a[i] + j*j) % MSize] == true && j < MSize)
				j++;
			if (j < MSize)
			{
				Yes[(a[i] + j*j) % MSize] = true;
				b[i] = (a[i] + j*j) % MSize + '0';
			}
			else if (j == MSize)
				b[i] = '-';
		}
	}
	for (int i = 0; i < n; i++){
		printf("%c", b[i]);
		if (i < n - 1)
			printf(" ");
		else if (i == n - 1) printf("\n");
	}
	return 0;
}

