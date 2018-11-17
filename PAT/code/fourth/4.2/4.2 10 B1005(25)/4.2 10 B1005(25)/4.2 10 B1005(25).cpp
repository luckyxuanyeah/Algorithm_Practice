// 4.2 10 B1005(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int k, t;
	scanf("%d", &k);
	int n[110];
	bool yes[10000] = { 0 };
	for (int i = 0; i < k; i++)
		scanf("%d", &n[i]);
	for (int i = 0; i < k; i++){
		t = n[i];
		while (t != 1)
		{
			if (t % 2 == 0)
				t = t / 2;
			else
				t = (t * 3 + 1) / 2;
			yes[t] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		if (yes[n[i]] == false)
			count++;
	}
	sort(n, n + k, cmp);
	for (int i = 0; i < k; i++)
	{
		if (yes[n[i]] == false){
			printf("%d", n[i]);
			count--;
			if (count >0)
				printf(" ");
		}
	}
	return 0;
}

