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
    vector<TreeNode*> digui(int start, int end)
{
	vector<TreeNode*> res;
	if (start > end)
	{
		res.push_back(NULL);
		return res;
	}
	for (int i = start; i <= end; i++)
	{
		vector<TreeNode*> left = digui(start, i - 1);
		vector<TreeNode*> right = digui(i + 1, end);
		for (int j1 = 0; j1 < left.size(); j1++)
		{
			for (int j2 = 0; j2 < right.size(); j2++)
			{
				TreeNode* now = new TreeNode(i);
				now->left = left[j1];
				now->right = right[j2];
				res.push_back(now);
			}
		}
	}
	return res;
}

vector<TreeNode*> generateTrees(int n)
{
    vector<TreeNode*> a;
    if(n<1)
        return a;
	return digui(1,n);
}
};
//Runtime: 40 ms, faster than 7.30% of C++ online submissions for Unique Binary Search Trees II.
//Memory Usage: 17.1 MB, less than 51.66% of C++ online submissions for Unique Binary Search Trees II.
//Next challenges:Different Ways to Add Parentheses
