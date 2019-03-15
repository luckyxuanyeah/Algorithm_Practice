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
   struct node {
	TreeNode *node;
	int layer;
};
int findBottomLeftValue(TreeNode* root)
{
	int ans = 0;
	queue<node*> q, q1;
	node* Root = new node;
	Root->layer = 1;
	Root->node = root;
	q.push(Root);
	int maxn = 0;
	while (!q.empty())
	{
		node* temp = q.front();
		if (maxn < temp->layer)
			maxn = temp->layer;
		q.pop();
		node* temp1 = new node;
		node* temp2 = new node;
		if (temp->node->left != NULL)
		{
			temp1->layer = temp->layer + 1;
			temp1->node = temp->node->left;
			q.push(temp1);
		}
		if (temp->node->right != NULL)
		{
			temp2->layer = temp->layer + 1;
			temp2->node = temp->node->right;
			q.push(temp2);
		}
	}
	q1.push(Root);
	while (!q1.empty())
	{
		node* temp = q1.front();
		q1.pop();
		if (temp->layer == maxn)
		{
			ans = temp->node->val;
			break;
		}
		node* temp1 = new node;
		node* temp2 = new node;
		if (temp->node->left != NULL)
		{
			temp1->layer = temp->layer + 1;
			temp1->node = temp->node->left;
			q1.push(temp1);
		}
		if (temp->node->right != NULL)
		{
			temp2->layer = temp->layer + 1;
			temp2->node = temp->node->right;
			q1.push(temp2);
		}
	}
	return ans;
}

};

//使用层序遍历一定能够遍历到最左边的数，而且这个时候队列中只有一个元素。但是注意的是，为了最后弹出的是最左边的数，遍历顺序是从右到左

//Runtime: 24 ms, faster than 58.38% of C++ online submissions for Find Bottom Left Tree Value.
//Memory Usage: 23.2 MB, less than 5.56% of C++ online submissions for Find Bottom Left Tree Value.
//Next challenges:Sum Root to Leaf Numbers  Largest BST Subtree  Increasing Order Search Tree
