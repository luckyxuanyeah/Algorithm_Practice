// 9.2 1 A1020(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "queue"
using namespace std;
const int maxn = 40;
int pre[maxn], in[maxn], post[maxn];
int n;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* create(int posL, int posR, int inL, int inR)
{
	if (posL > posR)
		return NULL;
	node* root = new node;
	root->data = pre[posR];
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (in[k] == pre[posR])
			break;
	}
	int numLeft = k - inL;
	root->lchild = create(posL, posL + numLeft - 1, inL, k - 1);
	root->rchild = create(posL + numLeft, posR - 1, k + 1, inR);
	return root;
}
int num = 0;
void layerOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n) printf(" ");
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &pre[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &in[i]);
	node* root = create(1, n, 1, n);
	layerOrder(root);
	return 0;
}

