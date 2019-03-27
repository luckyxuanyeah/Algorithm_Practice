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
    void dfs(TreeNode* root, int& sum, int& temp)
{
	temp = temp * 10 + root->val;
	if (root->left == NULL && root->right == NULL)
	{
		sum += temp;
		return;
	}
	if (root->left != NULL)
	{
		dfs(root->left, sum, temp);
		temp = (temp - root->left->val) / 10;
	}
	if (root->right != NULL)
	{
		dfs(root->right, sum, temp);
		temp = (temp - root->right->val) / 10;
	}
}

int sumNumbers(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int sum = 0, temp = 0;
	dfs(root, sum, temp);
	return sum;
}
};

//Runtime: 8 ms, faster than 81.26% of C++ online submissions for Sum Root to Leaf Numbers.
//Memory Usage: 12.5 MB, less than 37.58% of C++ online submissions for Sum Root to Leaf Numbers.
//Next challenges:Path Sum   Binary Tree Maximum Path Sum   Smallest String Starting From Leaf
