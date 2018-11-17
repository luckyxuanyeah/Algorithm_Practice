// 7.3 4 A1097(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int maxn = 100010;
const int TABLE = 1000010;
struct Node{
	int address, data, next;
	int order;
}node[maxn];
bool isExist[TABLE] = { false };
bool cmp(Node a, Node b)
{
	return a.order < b.order;
}
int main()
{
	for (int i = 0; i < maxn; i++)
		node[i].order = 2 * maxn;
	int first, n;
	scanf("%d%d", &first, &n);
	int address;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int delCount = 0, retainCount = 0, p = first;
	while (p != -1)
	{
		if (!isExist[abs(node[p].data)])
		{
			isExist[abs(node[p].data)] = true;
			node[p].order = retainCount++;
		}
		else
			node[p].order = maxn + delCount++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	int count = delCount + retainCount;
	for (int i = 0; i < count; i++)
	{
		if (i != count - 1 && i != retainCount-1)
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
		else printf("%05d %d -1\n", node[i].address, node[i].data);
	}
	return 0;
}