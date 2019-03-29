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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int inleft, int inright, int postleft, int postright)
{
	TreeNode* root = new TreeNode(postorder[postright]);
	if (inright == inleft)
		return root;
	int temp = 0;
	for (int i = inleft; i <= inright; i++)
	{
		if (inorder[i] == postorder[postright])
		{
			temp = i;
			break;
		}
	}
	if (temp - 1 >= inleft)
	{
		TreeNode* node1 = dfs(inorder, postorder, inleft, temp - 1, postleft, postleft + temp - 1 - inleft);
		root->left = node1;
	}
	if (temp + 1 <= inright)
	{
		TreeNode* node2 = dfs(inorder, postorder, temp + 1, inright, postleft + temp - inleft, postright - 1);
		root->right = node2;
	}
	return root;//这个return root一定不要忘记了啊
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
	if (inorder.size() == 0)
		return NULL;
	int len = postorder.size() - 1;
	TreeNode* root = dfs(inorder, postorder, 0, len, 0, len);
	return root;
}
};
//Runtime: 24 ms, faster than 78.90% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
//Memory Usage: 16.7 MB, less than 65.84% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
//Next challenges:Remove Invalid Parentheses   Target Sum   Sum of Subsequence Widths
