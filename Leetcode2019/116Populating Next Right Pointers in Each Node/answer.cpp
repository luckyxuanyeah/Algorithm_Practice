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
    void connectStep1(Node* root)
{
	if (root == NULL)
		return;
	if (root->left == NULL)
		return;
	root->left->next = root->right;
	connectStep1(root->left);
	connectStep1(root->right);
}

void connectStep2(Node* root)
{
	if (root == NULL)
		return;
	if (root->left == NULL)
		return;
	if (root->next != NULL)
		root->right->next = root->next->left;
	connectStep2(root->left);
	connectStep2(root->right);
}

Node* connect(Node* root)
{
	if (root == NULL)
		return NULL;
	connectStep1(root);
	connectStep2(root);
	return root;
}
};

//Runtime: 64 ms, faster than 77.91% of C++ online submissions for Populating Next Right Pointers in Each Node.
//Memory Usage: 27 MB, less than 53.12% of C++ online submissions for Populating Next Right Pointers in Each Node.
//Next challenges:Populating Next Right Pointers in Each Node II   Binary Tree Right Side View
