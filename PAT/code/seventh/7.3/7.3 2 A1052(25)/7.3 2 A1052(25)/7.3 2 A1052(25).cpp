// 7.3 2 A1052(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int maxn = 100010;
struct Node{
	int address,key, next;
	bool flag;
}node[maxn];
bool cmp(Node a, Node b)
{
	if (a.flag == false || b.flag == false)
		return a.flag > b.flag;
	else
		return a.key < b.key;
}
int main()
{
	for (int i = 0; i < maxn; i++)
		node[i].flag = false;
	int n, L;
	scanf("%d%d", &n, &L);
	int address;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d",&node[address].key, &node[address].next);
		node[address].address = address;
	}
	int count = 0, p = L;
	while (p != -1)
	{
		node[p].flag = true;
		count++;
		p = node[p].next;
	}
	if (count == 0)
		printf("0 -1\n");
	else{
		sort(node, node + maxn, cmp);
		printf("%d %05d\n", count, node[0].address);
		for (int i = 0; i < count; i++){
			if (i!= count - 1)
				printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
			else if (i == count - 1)
				printf("%05d %d -1\n", node[i].address, node[i].key);
		}
	}
	return 0;
}