/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*> m;
Node* cloneGraph(Node* node)
{
	if (node == nullptr)
		return nullptr;
	if (m.count(node))
		return m[node];
	Node* clone = new Node(node->val, {});
	m[node] = clone;
	for (Node* n : node->neighbors)
		clone->neighbors.push_back(cloneGraph(n));
	return clone;
}

};

//Runtime: 28 ms, faster than 99.89% of C++ online submissions for Clone Graph.
//Memory Usage: 16.6 MB, less than 66.80% of C++ online submissions for Clone Graph.
//Next challenges:Copy List with Random Pointer
