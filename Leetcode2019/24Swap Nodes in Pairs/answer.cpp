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
    ListNode* swapPairs(ListNode* head)
{
        if(head==NULL)
            return NULL;
	ListNode* pre = head;
	ListNode* cur = head->next;
	while (cur != NULL)
	{
		int temp = cur->val;
		cur->val = pre->val;
		pre->val = temp;
		if (cur != NULL)
		{
			cur = cur->next;
			if (cur != NULL)
				cur = cur->next;
		}
		if (pre != NULL)
		{
			pre = pre->next;
			if (pre != NULL)
				pre = pre->next;
		}
	}
	return head;
}
};

//Runtime: 12 ms, faster than 39.67% of C++ online submissions for Swap Nodes in Pairs.
//Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Swap Nodes in Pairs.
//Next challenges:Reverse Nodes in k-Group
