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
    
ListNode *detectCycle(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next!=NULL)//这里是&&的关系 两者必须都满足才可以 不满足一个就跳出
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow && fast != NULL)
			break;
	}
	if (fast != NULL && fast->next != NULL)
	{
		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
	return NULL;
}
	
//ListNode *detectCycle(ListNode *head)
//{
//	ListNode* fast = head;
//	ListNode* slow = head;
//	bool hasCycle = false;
//	while (fast != NULL && fast->next!=NULL)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//		if (fast == slow)
//		{
//			hasCycle = true;
//			break;
//		}
//	}
//	if (hasCycle==false)
//		return NULL;
//	else
//	{
//		fast = head;
//		while (fast != slow)
//		{
//			fast = fast->next;
//			slow = slow->next;
//		}
//		return fast;
//	}
//}

};
//Runtime: 12 ms, faster than 99.25% of C++ online submissions for Linked List Cycle II.
//Memory Usage: 9.8 MB, less than 42.29% of C++ online submissions for Linked List Cycle II.
//Next challenges:Find the Duplicate Number

//Runtime: 12 ms, faster than 81.95% of C++ online submissions for Linked List Cycle II.
//Memory Usage: 9.8 MB, less than 56.08% of C++ online submissions for Linked List Cycle II.
//Next challenges:Merge Sorted Array   Insertion Sort List   Linked List Components
