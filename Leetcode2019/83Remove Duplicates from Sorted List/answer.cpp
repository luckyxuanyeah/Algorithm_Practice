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
	ListNode* cur = head->next;
	ListNode* pre = head;
	while (cur != NULL)
	{
		int now = pre->val;
		while (cur->val == now)
		{
			cur = cur->next;
			if (cur == NULL)
				break;
		}
		pre->next = cur;
		pre = cur;
	}
	return head;
}
};
//Runtime: 12 ms, faster than 100.00% of C++ online submissions for Remove Duplicates from Sorted List.
//Memory Usage: 9.2 MB, less than 69.45% of C++ online submissions for Remove Duplicates from Sorted List.
//Next challenges:Linked List Cycle  Insertion Sort List  Intersection of Two Linked Lists
