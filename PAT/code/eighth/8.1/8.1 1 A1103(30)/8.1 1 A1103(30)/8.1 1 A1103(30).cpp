// 8.1 1 A1103(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
#include "vector"
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int n, k, p, maxSum = -1;
vector<int> fac, temp, ans;
int power(int index)
{
	int temp = 1;
	for (int i = 0; i < p; i++)
		temp = temp * index;
	return temp;
}
void init()
{
	int i = 0, temp = 0;
	while (temp <= n)
	{
		fac.push_back(temp);
		temp = power(++i);
	}
}
void DFS(int index, int nowK, int sumRequire, int sumNow)
{
	if (nowK == k && sumRequire == n)
	{
		if (sumNow > maxSum)
		{
			maxSum = sumNow;
			ans = temp;
		}
		return;
	}
	if (nowK > k || sumRequire > n)
		return;
	if (index - 1 >= 0)
	{
		temp.push_back(index);
		DFS(index, nowK + 1, sumRequire + fac[index], sumNow + index);
		temp.pop_back();
		DFS(index - 1, nowK, sumRequire, sumNow);
	}
}
int main()
{
	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if (maxSum == -1) printf("Impossible\n");
	else
	{
		printf("%d = ", n);
		for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
		{
			printf("%d^%d", *it, p);
			if (it != ans.end() - 1)
				printf(" + ");
			else printf("\n");
		}
	}
	return 0;
}