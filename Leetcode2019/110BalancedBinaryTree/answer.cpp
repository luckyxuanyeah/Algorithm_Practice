#include <iostream>
#include "vector"
#include "queue"
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getNum(TreeNode* root,int& level)
{
	if (root == NULL)
		return;
	if(level<root->val)
		level = root->val;
	getNum(root->left,level);
	getNum(root->right,level);
}
bool isBalanced(TreeNode* root)
{
	if (root == NULL)
		return true;
	int level1 = 0, level2 = 0;
	getNum(root->left, level1);
	getNum(root->right, level2);
	int distance = level1 - level2;
	if (distance > 1 || distance < -1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(3);
	queue<TreeNode*> q;
	root->val = 1;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* now = q.front();
		q.pop();
		if (now->left != NULL)
		{
			now->left->val = now->val + 1;
			q.push(now->left);
		}
		if (now->right != NULL)
		{
			now->right->val = now->val + 1;
			q.push(now->right);
		}
	}
	cout << isBalanced(root) << endl;
	return 0;
}

//另外一种解法 java
//Runtime: 8 ms, faster than 5.25% of Java online submissions for Balanced Binary Tree.
//Memory Usage: 39.3 MB, less than 70.30% of Java online submissions for Balanced Binary Tree.
//Next challenges:Maximum Depth of Binary Tree
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null)
		    return true;
	    int distance = getNum(root.left)-getNum(root.right);
	    if (distance > 1 || distance < -1)
		    return false;
	    else
		    return isBalanced(root.left) && isBalanced(root.right);
    }
    public static int getNum(TreeNode root)
    {
	    if (root == null)
		    return 0;
        int level=0;
        LinkedList<TreeNode> list=new LinkedList<TreeNode>();
        list.add(root);
        int first=0;
        int last=1;
        while(first<list.size())
        {
            last=list.size();
            while(first<last)
            {
                if(list.get(first).left!=null)
                    list.add(list.get(first).left);
                if(list.get(first).right!=null)
                    list.add(list.get(first).right);
                first++;
            }
            level++;
        }
        return level;
    }
}
