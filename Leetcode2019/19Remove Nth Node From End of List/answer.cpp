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
    ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head->next == NULL)
		return NULL;
	ListNode* pre = head;
	ListNode* cur = head;
	for (int i = 0; i < n; i++)
		cur = cur->next;
	if (cur == NULL)
		return head->next;
	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = cur->next;
	}
	pre->next = pre->next->next;//你是猪吗直接下一个的下一个不就好了emmmm
	return head;
}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
//Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Remove Nth Node From End of List.
//Next challenges:Reorder List   Find the Duplicate Number   Fruit Into Baskets
