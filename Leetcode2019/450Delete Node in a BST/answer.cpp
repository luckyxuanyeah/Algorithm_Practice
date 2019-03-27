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
   TreeNode* findmin(TreeNode* root)
{
	if (root->left == NULL)
		return root;
	else
		return findmin(root->left);
}
TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == NULL)
		return root;
	if (key < root->val)
		root->left = deleteNode(root->left, key);
	else if (key > root->val)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else
		{
			TreeNode* temp = findmin(root->right);
			root->val = temp->val;
			root->right=deleteNode(root->right, root->val);
		}
	}
	return root;
}
};
//Runtime: 48 ms, faster than 9.69% of C++ online submissions for Delete Node in a BST.
//Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Delete Node in a BST.
//Next challenges:Split BST
