// 508MostFrequentSubtreeSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include "vector"
#include "queue"
#include "map"
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int SUM(TreeNode* node)
{
	queue<TreeNode*> qq;
	int num = 0;
	qq.push(node);
	while (!qq.empty())
	{
		TreeNode* temp = qq.front();
		qq.pop();
		num += temp->val;
		if (temp->left != NULL)
			qq.push(temp->left);
		if (temp->right != NULL)
			qq.push(temp->right);
	}
	return num;
}
vector<int> findFrequentTreeSum(TreeNode* root) 
{
	vector<int> ans;
	while (root == NULL)
		return ans;
	queue<TreeNode*> q;
	map<int, int> mp;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		int a = SUM(temp);
		map<int, int>::iterator it = mp.find(a);
		if (it == mp.end())
			mp[a] = 1;
		else
			mp[a]++;
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}
	int maxxxn = 0;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (maxxxn < it->second)
		{
			ans.clear();
			maxxxn = it->second;
			ans.push_back(it->first);
		}
		else if (maxxxn == it->second)
			ans.push_back(it->first);
	}
	return ans;
}
int main()
{
	TreeNode* root=new TreeNode(5);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(-3);
	root->left = node1;
	root->right = node2;
	vector<int> a = findFrequentTreeSum(root);
	return 0;
}

//Runtime: 64 ms, faster than 7.88% of C++ online submissions for Most Frequent Subtree Sum.
//Memory Usage: 45.2 MB, less than 5.71% of C++ online submissions for Most Frequent Subtree Sum.
//Next challenges:Subtree of Another Tree
