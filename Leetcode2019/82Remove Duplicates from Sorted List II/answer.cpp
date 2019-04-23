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
    ListNode* deleteDuplicates(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* newhead = new ListNode(0);
	newhead->next = head;
	ListNode* pre = newhead;
	ListNode* cur = pre->next;
	while (cur->next!= NULL)
	{
		if (cur->next->val != cur->val)
		{
			if (pre->next == cur)
				pre = cur;
			else
				pre->next = cur->next;
		}
		cur = cur->next;
	}
	if (pre->next != cur)
		pre->next = cur->next;
	return newhead->next;
}
};
//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Remove Duplicates from Sorted List II.
//Memory Usage: 9.1 MB, less than 52.91% of C++ online submissions for Remove Duplicates from Sorted List II.
//Next challenges:Reverse Nodes in k-Group   Palindrome Linked List   Next Greater Node In Linked List
