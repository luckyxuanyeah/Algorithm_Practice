// 7.3 1 A1032(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
const int maxn = 100010;
struct Node{
	int next;
	char data;
	bool flag;
}node[maxn];
int main()
{
	for (int i = 0; i < maxn; i++)
		node[i].flag = false;
	int l1, l2, n;
	scanf("%d%d%d", &l1, &l2, &n);
	int address, next;
	char data;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}
	int p;
	for (p = l1; p != -1; p = node[p].next)
		node[p].flag = true;
	for (p = l2; p != -1; p = node[p].next)
	{
		if (node[p].flag == true)
			break;
	}
	if (p != -1)
		printf("%05d\n", p);
	else 
		printf("-1\n");
	return 0;
}

