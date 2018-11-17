// 9.4 3 A1099(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "queue"
#include "algorithm"
using namespace std;
const int maxn = 110;
int n, orgin[maxn], num = 0;
struct node{
	int data;
	int lchild, rchild;
}Node[maxn];
void inOrder(int root)
{
	if (root == -1)
		return;
	inOrder(Node[root].lchild);
	Node[root].data = orgin[num++];
	inOrder(Node[root].rchild);
}
void BFS(int root)
{
	queue<int> q;
	q.push(root);
	num = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		printf("%d", Node[now].data);
		num++;
		if (num < n) printf(" ");
		if (Node[now].lchild != -1) q.push(Node[now].lchild);
		if (Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &Node[i].lchild, &Node[i].rchild);
	for (int i = 0; i < n; i++)
		scanf("%d", &orgin[i]);
	sort(orgin, orgin + n);
	inOrder(0);
	BFS(0);
	return 0;
}

