// 9.2 3 A1102(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "queue"
#include "algorithm"
using namespace std;
const int maxn = 110;
struct node{
	int lchild;
	int rchild;
}Node[maxn];
int n, num = 0;
bool notRoot[maxn] = { false };
int pre[maxn], in[maxn], pos[maxn];
void print(int id)
{
	printf("%d", id);
	num++;
	if (num < n) printf(" ");
	else printf("\n");
}
void inOrder(int root)
{
	if (root == -1)
		return;
	inOrder(Node[root].lchild);
	print(root);
	inOrder(Node[root].rchild);
}
void BFS(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		print(now);
		if (Node[now].lchild != -1) q.push(Node[now].lchild);
		if (Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}
void postOrder(int root)
{
	if (root == -1)
		return;
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}
int strToNum(char c)
{
	if (c == '-') return -1;
	else
	{
		notRoot[c - '0'] = true;
		return c - '0';
	}
}
int findRoot()
{
	for (int i = 0; i < n; i++)
	{
		if (notRoot[i] == false)
			return i;
	}
}
int main()
{
	scanf("%d", &n);
	char lchild, rchild;
	for (int i = 0; i < n; i++)
	{
		scanf("%*c%c %c", &lchild,&rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	postOrder(root);
	BFS(root);
	num = 0;
	inOrder(root);
	return 0;
}

