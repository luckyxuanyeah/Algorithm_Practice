/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
{
	if (head == NULL || head->next==NULL)
		return false;
	ListNode* temp = head;
	ListNode* temp2 = head->next;
	while (temp != temp2)
	{
		if (temp2==NULL||temp2->next==NULL)
			return false;
		temp = temp->next;
		temp2 = temp2->next->next;
	}
	return true;
}
};

//Runtime: 12 ms, faster than 99.32% of C++ online submissions for Linked List Cycle.
//Memory Usage: 9.7 MB, less than 64.15% of C++ online submissions for Linked List Cycle.
//Next challenges:Linked List Cycle II  Happy Number
