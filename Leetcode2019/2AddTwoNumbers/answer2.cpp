//2019.06.15记录：使用一个while循环进行加和，在while循环中使用if判断某个链表是否为空；创建新头节点的时候要注意，使用一个额外指针来进行后续链表的构建，头结点需要额外设置。
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* newhead = NULL;
	ListNode* temp;
	int add = 0, sum = 0;
	while (l1 != NULL || l2 != NULL || add != 0)
	{
		sum = add;
		if (l1 != NULL)
		{
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		if (newhead == NULL)
		{
			temp = new ListNode(sum%10);
			newhead = temp;
		}
		else if (newhead != NULL)
		{
			temp->next = new ListNode(sum % 10);
			temp = temp->next;
		}
		add = sum / 10;
	}
	return newhead;
}
//Runtime: 28 ms, faster than 71.54% of C++ online submissions for Add Two Numbers.
//Memory Usage: 10.4 MB, less than 49.17% of C++ online submissions for Add Two Numbers.
//Next challenges:Multiply Strings  Add Binary  Sum of Two Integers  Add Strings  Add Two Numbers II  Add to Array-Form of Integer
