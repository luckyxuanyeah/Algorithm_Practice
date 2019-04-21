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
    ListNode* reverseList(ListNode* head) 
{
    if(head == NULL || head -> next == NULL)
		return head;
	ListNode* newhead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}
};
//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.
//Memory Usage: 9.4 MB, less than 5.41% of C++ online submissions for Reverse Linked List.
//Next challenges:Reverse Linked List II  Binary Tree Upside Down  Palindrome Linked List
