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
	while (l1 != NULL && l2 != NULL)
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


ListNode* mergeKLists(vector<ListNode*>& lists)
{
	if (lists.size() == 0)
		return NULL;
	if (lists.size() & 1)
		lists.push_back(NULL);
	for (int i = 0; i < lists.size() / 2; i++)
		lists[i] = mergeTwoLists(lists[i * 2], lists[i * 2 + 1]);
	lists.resize(lists.size() / 2);
	if (lists.size() == 1)
		return lists[0];
	else
		return mergeKLists(lists);
}
};
//Runtime: 40 ms, faster than 46.48% of C++ online submissions for Merge k Sorted Lists.
//Memory Usage: 16.8 MB, less than 7.73% of C++ online submissions for Merge k Sorted Lists.
//Next challenges:Ugly Number II
