/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    void helper(Node* root)
{
	if (root == NULL)
		return;
	Node* temp = root->next;
	while (temp != NULL)
	{
		if (temp->left != NULL)
		{
			temp = temp->left;
			break;
		}
		if (temp->right != NULL)
		{
			temp = temp->right;
			break;
		}
		temp = temp->next;
	}
	if (root->left != NULL)
		root->left->next = root->right != NULL ? root->right : temp;
	if (root->right != NULL)
		root->right->next = temp;
	helper(root->right);
    helper(root->left);
}
Node* connect(Node* root)
{
	helper(root);
	return root;
}
};

//Runtime: 432 ms, faster than 42.08% of C++ online submissions for Populating Next Right Pointers in Each Node II.
//Memory Usage: 66.7 MB, less than 52.43% of C++ online submissions for Populating Next Right Pointers in Each Node II.
//Next challenges:The Maze III   Average of Levels in Binary Tree    Search in a Binary Search Tree
