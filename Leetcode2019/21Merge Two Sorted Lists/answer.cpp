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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	ListNode* head = NULL;
	if (l1->val > l2->val)
	{
		head = new ListNode(l2->val);
		l2 = l2->next;
	}
	else if (l1->val <= l2->val)
	{
		head = new ListNode(l1->val);
		l1 = l1->next;
	}
	ListNode* temp = head;
	while (l1!=NULL && l2!=NULL)
	{
		if (l1->val > l2->val)
		{
			temp->next = new ListNode(l2->val);
			temp = temp->next;
			l2 = l2->next;
		}
		else if (l1->val <= l2->val)
		{
			temp->next = new ListNode(l1->val);
			temp = temp->next;
			l1 = l1->next;
		}
	}
	if (l1 != NULL)
		temp->next = l1;
	else if (l2 != NULL)
		temp->next = l2;
	return head;
}
};
//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
//Memory Usage: 9 MB, less than 99.71% of C++ online submissions for Merge Two Sorted Lists.
//Next challenges:Merge Sorted Array  Sort List  Shortest Word Distance II
