#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> preorder, inorder;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* newNode(int preL,int preR,int inL,int inR)
{
	if (preL > preR)
		return NULL;
	TreeNode* node = new TreeNode;
	node->val = preorder[preL];
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (inorder[k] == preorder[preL])
			break;
	}
	int numLeft = k - inL;
	node->left = newNode(preL+1, preL + numLeft, inL, k - 1);
	node->right = newNode(preL + 1 + numLeft, preR, k + 1, inR);
	return node;
}
int main()
{
	/*if (preorder.size() == 0)
		return NULL;*/
	preorder.push_back(3);
	preorder.push_back(9);
	preorder.push_back(20);
	preorder.push_back(15);
	preorder.push_back(7);
	inorder.push_back(9);
	inorder.push_back(3);
	inorder.push_back(15);
	inorder.push_back(20);
	inorder.push_back(7);
	int len = preorder.size();
	TreeNode* root = newNode(0, len - 1, 0, len - 1);
	printf("%d",root->val);
	return 0;
}
//Runtime: 24 ms, faster than 86.30% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//Memory Usage: 16.6 MB, less than 70.94% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//Next challenges:Construct Binary Tree from Inorder and Postorder Traversal


//another writetype!!!
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
    TreeNode* newNode(int preL,int preR,int inL,int inR,vector<int>& preorder, vector<int>& inorder)
    {
	    if (preL > preR)
		    return NULL;
	    TreeNode* node = new TreeNode(preorder[preL]);
	    int k;
	    for (k = inL; k <= inR; k++)
	    {
		    if (inorder[k] == preorder[preL])
			    break;
	    }
	    int numLeft = k - inL;
	    node->left = newNode(preL+1, preL + numLeft, inL, k - 1,preorder,inorder);
	    node->right = newNode(preL + 1 + numLeft, preR, k + 1, inR,preorder,inorder);
	    return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0)
            return NULL;
        int len = preorder.size();
        return newNode(0, len - 1, 0, len - 1,preorder,inorder);
    }
};
