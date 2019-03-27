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
    int maxn = INT_MIN;
int dfs(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int leftmax = dfs(root->left);
	int rightmax = dfs(root->right);
	int curmax = root->val;
	if (leftmax > 0)
		curmax += leftmax;
	if (rightmax > 0)
		curmax += rightmax;
	if (curmax > maxn)
		maxn = curmax;
	return max(root->val, max(root->val + leftmax, root->val + rightmax));
}

int maxPathSum(TreeNode* root)
{
	if (root == NULL)
		return 0;
	dfs(root);
	return maxn;
}
};
//Runtime: 48 ms, faster than 16.68% of C++ online submissions for Binary Tree Maximum Path Sum.
//Memory Usage: 24.2 MB, less than 95.65% of C++ online submissions for Binary Tree Maximum Path Sum.
//Next challenges:Path Sum  Path Sum IV  Longest Univalue Path
