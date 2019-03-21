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
 struct result{
	int include, not_include;
};
result find(TreeNode* root)
{
	result res;
	if (root == NULL)
	{
		res.include = 0;
		res.not_include = 0;
	}
	else
	{
		result ltree, rtree;
		ltree = find(root->left);
		rtree = find(root->right);
		res.include = ltree.not_include + rtree.not_include + root->val;
		res.not_include = max(ltree.include, ltree.not_include) + max(rtree.include, rtree.not_include);
	}
	return res;
}
int rob(TreeNode* root)
{
	result res;
	res = find(root);
	return max(res.include, res.not_include);
}
};

//Runtime: 28 ms, faster than 64.54% of C++ online submissions for House Robber III.
//Memory Usage: 20.7 MB, less than 83.85% of C++ online submissions for House Robber III.
//Next challenges:Remove Invalid Parentheses  Convert Binary Search Tree to Sorted Doubly Linked List  Smallest String Starting From Leaf
