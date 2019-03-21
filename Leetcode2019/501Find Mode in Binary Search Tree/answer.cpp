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
    vector<int> ans;
int maxCount = 0;
int tmp_count = 0;
int tmp_val = 0;
void inorder(TreeNode* root)
{
	if (root->left != NULL)
		inorder(root->left);
	if (ans.size() == 0)
	{
		ans = { root->val };//vector不只是有push_back和append！
		tmp_count = 1;
		maxCount = 1;
	}
	else
	{
		if (root->val == tmp_val)
		{
			tmp_count++;
			if (tmp_count > maxCount)
			{
				ans = { tmp_val };
				maxCount = tmp_count;
			}
			else if (tmp_count == maxCount)
				ans.push_back(tmp_val);
		}
		else
		{
			tmp_count = 1;
			if (tmp_count == maxCount)
				ans.push_back(root->val);
		}
	}
	tmp_val = root->val;
	if (root->right != NULL)
		inorder(root->right);
}

vector<int> findMode(TreeNode* root) 
{
	if (root == NULL)
		return ans;
	inorder(root);
	return ans;
}
};

//Runtime: 28 ms, faster than 97.85% of C++ online submissions for Find Mode in Binary Search Tree.
//Memory Usage: 23.3 MB, less than 80.58% of C++ online submissions for Find Mode in Binary Search Tree.
//Next challenges:Validate Binary Search Tree
