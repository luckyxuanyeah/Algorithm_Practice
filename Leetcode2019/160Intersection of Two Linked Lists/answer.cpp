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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode*a = headA;
	ListNode* b = headB;
	while(a!=b)
	{
		if (a == NULL)
			a = headB;
		else
			a = a->next;
		if (b == NULL)
			b = headA;
		else
			b = b->next;
	}
	return a;
}
};
//Runtime: 52 ms, faster than 98.24% of C++ online submissions for Intersection of Two Linked Lists.
//Memory Usage: 16.9 MB, less than 17.23% of C++ online submissions for Intersection of Two Linked Lists.
//Next challenges:Minimum Index Sum of Two Lists
