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
    bool isSameTree(TreeNode* p, TreeNode* q) 
{
	if ((p != NULL && q == NULL) || (p == NULL && q != NULL))
		return false;
	else if (p == NULL && q == NULL)
		return true;
	queue<TreeNode*> q1;
	queue<TreeNode*> q2;
	q1.push(p);
	q2.push(q);
	while (!q1.empty() && !q2.empty())
	{
		TreeNode* temp1 = q1.front();
		TreeNode* temp2 = q2.front();
		q1.pop();
		q2.pop();
		if (temp1->val != temp2->val)
			return false;
		else
		{
			if (temp1->left != NULL && temp2->left != NULL)
			{
				q1.push(temp1->left);
				q2.push(temp2->left);
			}
			else if (temp1->left == NULL && temp2->left != NULL)
				return false;
			else if (temp1->left != NULL && temp2->left == NULL)
				return false;
			if (temp1->right != NULL && temp2->right != NULL)
			{
				q1.push(temp1->right);
				q2.push(temp2->right);
			}
			else if (temp1->right == NULL && temp2->right != NULL)
				return false;
			else if (temp1->right != NULL && temp2->right == NULL)
				return false;
		}

	}
	if (!q1.empty() && q2.empty())
		return false;
	else if (q1.empty() && !q2.empty())
		return false;
    return true;
    }
};
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Same Tree.
//Memory Usage: 10.2 MB, less than 43.21% of C++ online submissions for Same Tree.
//Next challenges:Binary Tree Zigzag Level Order Traversal  Path Sum II   Possible Bipartition
