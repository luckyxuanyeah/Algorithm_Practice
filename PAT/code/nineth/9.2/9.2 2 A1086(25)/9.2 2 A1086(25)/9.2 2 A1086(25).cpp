// 9.2 2 A1086(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "stack"
using namespace std;
const int maxn = 40;
int n, pos[maxn], pre[maxn], in[maxn];
struct node{
	int data;
	node* left;
	node* right;
};
node* create(int preL, int preR, int inL, int inR)
{
	if (preL > preR)
		return NULL;
	node* root = new node;
	root->data = pre[preL];
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (in[k] == pre[preL])
			break;
	}
	int numLeft = k - inL;
	root->left = create(preL + 1, preL + numLeft, inL, k - 1);
	root->right = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
int num = 0;
void posTraverse(node* root)
{
	if (root == NULL)
		return;
	posTraverse(root->left);
	posTraverse(root->right);
	printf("%d", root->data);
	num++;
	if (num < n)
		printf(" ");
}
int main()
{
	scanf("%d", &n);
	char str[5];
	stack<int> st;
	int x, preIndex = 0, inIndex = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "Push") == 0)
		{
			scanf("%d", &x);
			pre[preIndex++] = x;
			st.push(x);
		}
		else
		{
			in[inIndex++] = st.top();
			st.pop();
		}
	}
	node* root = create(0, n - 1, 0, n - 1);
	posTraverse(root);
	return 0;
}

