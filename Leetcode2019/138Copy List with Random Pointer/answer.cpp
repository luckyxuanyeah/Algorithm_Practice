/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> mp;
Node* copyRandomList(Node* head)
{
	if (head == NULL)
		return NULL;
	if (mp.count(head))
		return mp[head];
	Node* copy = new Node;
	mp[head] = copy;
	copy->val = head->val;
	copy->next = copyRandomList(head->next);
	copy->random = copyRandomList(head->random);
	return copy;
}
};
//Runtime: 48 ms, faster than 49.80% of C++ online submissions for Copy List with Random Pointer.
//Memory Usage: 22.3 MB, less than 5.21% of C++ online submissions for Copy List with Random Pointer.
//Next challenges:Reverse Nodes in k-Group  Reorder List   Repeated DNA Sequences
