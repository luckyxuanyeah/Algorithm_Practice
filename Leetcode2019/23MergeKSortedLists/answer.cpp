#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
	vector<ListNode*> lists;
	ListNode* head1 = new ListNode(1);
	ListNode* head2 = new ListNode(1);
	ListNode* head3 = new ListNode(2);
	ListNode* node1 = new ListNode(4);
	ListNode* node2 = new ListNode(5);
	lists.push_back(head1);
	lists.push_back(head2);
	lists.push_back(head3);
	lists[0]->next = node1;
	node1->next = node2;
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	lists[1]->next = node3;
	node3->next = node4;
	ListNode* node5 = new ListNode(6);
	lists[2]->next = node5;
  int count=0;
  for(int i=0;i<lists.size();i++)
        {
            if(lists[i]==NULL)
                count++;
        }
        if(count==lists.size())
            return NULL;
	vector<int> num;
	for (int i = 0; i < lists.size(); i++)
	{
		ListNode* now = lists[i];
		while (now != NULL)
		{
			num.push_back(now->val);
			now = now->next;
		}
	}
	sort(num.begin(), num.end());
	ListNode* p;
	ListNode* head = new ListNode(num[0]);
	ListNode* pre = head;
	for (int i = 1; i < num.size(); i++)
	{
		p = new ListNode(num[i]);
		pre->next = p;
		pre = p;
	}
	ListNode* node = head;
	while (node != NULL)
	{
		cout << node->val << endl;
		node = node->next;
	}
	return 0;
}
//Runtime: 28 ms, faster than 99.92% of C++ online submissions for Merge k Sorted Lists.
//Memory Usage: 12.8 MB, less than 13.86% of C++ online submissions for Merge k Sorted Lists.
//Next challenges:Merge Two Sorted Lists  Ugly Number II
