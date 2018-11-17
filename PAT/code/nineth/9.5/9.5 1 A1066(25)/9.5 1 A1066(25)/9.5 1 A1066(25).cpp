// 9.5 1 A1066(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int maxn = 210;
struct node{
	int data, height;
	node* lchild;
	node* rchild;
};
int in[maxn];
node* newNode(int v)
{
	node* Node = new node;
	Node->data = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
int getHeight(node* root)
{
	if (root == NULL) return 0;
	return root->height;
}
int getBalanceFactor(node* root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void updateHeight(node* root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void L(node* &root)
{
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node* &root)
{
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root, int v)
{
	if (root == NULL)
	{
		root = newNode(v);
		return;
	}
	if (v < root->data)
	{
		insert(root->lchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == 2)
		{
			if (getBalanceFactor(root->lchild) == 1)
				R(root);
			else if (getBalanceFactor(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(root->rchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2)
		{
			if (getBalanceFactor(root->rchild) == -1)
				L(root);
			else if (getBalanceFactor(root->rchild) == 1)
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}
node* create(int data[], int n)
{
	node* root = NULL;
	for (int i = 0; i < n; i++)
		insert(root, data[i]);
	return root;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	node* root = create(in, n);
	printf("%d\n",root->data);
	return 0;
}