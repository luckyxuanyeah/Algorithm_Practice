// 9.4 1 A1043(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "vector"
using namespace std;
vector<int> orign, pre, preM;
int n;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* newNode(int v)
{
	node* Node = new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
void insert(node* &root, int data)
{
	if (root == NULL)
	{
		root = newNode(data);
		return;
	}
	if (data < root->data) insert(root->lchild, data);
	else insert(root->rchild, data);
}
void preOrder(node* root,vector<int>&vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}
void preOrderMirror(node* root, vector<int>&vi)
{
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->rchild, vi);
	preOrderMirror(root->lchild, vi);
}
int sum = 0;
void postOrder(node* root)
{
	if (root == NULL)
		return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d", root->data);
	sum++;
	if (sum < n)
		printf(" ");
}
int sum1 = 0;
void postOrderMirror(node* root)
{
	if (root == NULL)
		return;
	postOrderMirror(root->rchild);
	postOrderMirror(root->lchild);
	printf("%d", root->data);
	sum1++;
	if (sum1 < n)
		printf(" ");
}
int main()
{
	scanf("%d", &n);
	node* root = NULL;
	int data;
	for (int i = 0; i < n; i++){
		scanf("%d", &data);
		orign.push_back(data);
		insert(root, data);
	}
	preOrder(root, pre);
	preOrderMirror(root, preM);
	if (orign == pre)
	{
		printf("YES\n");
		postOrder(root);
	}
	else if (orign == preM){
		printf("YES\n");
		postOrderMirror(root);
	}
	else printf("NO\n");
	return 0;
}

