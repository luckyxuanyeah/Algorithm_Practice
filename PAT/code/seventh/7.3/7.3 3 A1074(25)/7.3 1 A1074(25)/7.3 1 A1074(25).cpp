// 7.3 1 A1074(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int maxn = 100010;
struct Node{
	int address, data, next;
	int order;
}node[maxn];
bool cmp(Node a, Node b)
{
	return a.order < b.order;
}
int main()
{
	for (int i = 0; i < maxn; i++)
		node[i].order = maxn;
	int first, n, k;
	scanf("%d%d%d", &first, &n, &k);
	int address;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int count = 0, p = first;
	while (p != -1)
	{
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	for (int i = 0; i < count / k; i++)
	{
		for (int j = (i + 1)*k - 1; j>i*k; j--)
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		printf("%05d %d ", node[i*k].address, node[i*k].data);
		if (i < count / k - 1)
			printf("%05d\n", node[(i + 2)*k - 1].address);
		else
		{
			if (count%k == 0)
				printf("-1\n");
			else{
				printf("%05d\n", node[(i + 1)*k].address);
				for (int m = count / k*k; m < count; m++)
				{
					printf("%05d %d ", node[m].address, node[m].data);
					if (m < count - 1)
						printf("%05d\n", node[m + 1].address);
					else printf("-1\n");
				}
			}
		}
	}
	return 0;
}

