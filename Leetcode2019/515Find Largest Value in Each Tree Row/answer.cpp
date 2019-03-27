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
    vector<int> largestValues(TreeNode* root)
{
	vector<int> ans;
	if (root == NULL)
		return ans;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int number = q.size(), maxn = INT_MIN;
		for (int i = 0; i< number; i++)
		{
			TreeNode* t = q.front();
			q.pop();
			maxn = max(maxn, t->val);
			if (t->left != NULL)
				q.push(t->left);
			if (t->right != NULL)
				q.push(t->right);
		}
		ans.push_back(maxn);
	}
	return ans;
}
};
//Runtime: 32 ms, faster than 18.27% of C++ online submissions for Find Largest Value in Each Tree Row.
//Memory Usage: 20.9 MB, less than 98.94% of C++ online submissions for Find Largest Value in Each Tree Row.
//Next challenges:Friend Circles  Construct String from Binary Tree  Two Sum IV - Input is a BST
