/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* findleftRight(TreeNode* root)
{
	if (root->left == NULL && root->right == NULL)
		return root;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* temp = q.front();
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp->right != NULL)
			q.push(temp->right);
		else if (temp->left != NULL)
			q.push(temp->left);
	}
	return temp;
}

void flatten(TreeNode* root)
{
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return;
	if (root->left != NULL)
	{
		findleftRight(root->left)->right = root->right;
		root->right = root->left;
		root->left = NULL;
	}
	flatten(root->left);
	flatten(root->right);
}
};

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Flatten Binary Tree to Linked List.
//Memory Usage: 11.8 MB, less than 5.00% of C++ online submissions for Flatten Binary Tree to Linked List.
//Next challenges:Flatten a Multilevel Doubly Linked List
