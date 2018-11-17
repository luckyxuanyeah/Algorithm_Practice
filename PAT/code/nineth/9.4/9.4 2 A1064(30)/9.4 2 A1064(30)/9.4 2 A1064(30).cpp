// 9.4 2 A1064(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int maxn = 1010;
int n, number[maxn], CBT[maxn], index = 0;
void inOrder(int root)
{
	if (root > n) return;
	inOrder(root * 2);
	CBT[root] = number[index++];
	inOrder(root * 2 + 1);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &number[i]);
	sort(number, number + n);
	inOrder(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", CBT[i]);
		if (i < n) printf(" ");
	}
	return 0;
}

