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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
	    vector<int> valnum;
	    while (temp != NULL)
	    {
		    len++;
		    valnum.push_back(temp->val);
		    temp = temp->next;
	    }
        if (len == 0 || k==0 || len ==1 || k%len==0)
		    return head;
	    if (k > len)
		    k = k % len;
	    ListNode* newHead = new ListNode(valnum[valnum.size() - k]);
	    ListNode* pre = newHead;
	    ListNode* p;
	    if (k <= 1)
	    {
		    for (int i = 0; i < valnum.size() - k; i++)
		    {
			    p = new ListNode(valnum[i]);
			    pre->next = p;
			    pre = p;
		    }
	    }
	    else if (k > 1)
	    {
		    for (int i = valnum.size() - k + 1; i < valnum.size(); i++)
		    {
			    p = new ListNode(valnum[i]);
			    pre->next = p;
			    pre = p;
		    }
		    for (int i = 0; i < valnum.size() - k; i++)
		    {
			    p = new ListNode(valnum[i]);
			    pre->next = p;
			    pre = p;
		    }
	    }
        return newHead;
    }
};
//Runtime: 12 ms, faster than 99.75% of C++ online submissions for Rotate List.
//Memory Usage: 10.7 MB, less than 5.58% of C++ online submissions for Rotate List.
//Next challenges:Rotate Array   Split Linked List in Parts



// 61Rotate List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "vector"
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
int main()
{
	int k;
	cin >> k;
	ListNode* head=new ListNode(1);
	ListNode* node1 = new ListNode(2);
	head->next = node1;
	ListNode* node2 = new ListNode(3);
	node1->next = node2;
	ListNode* node3 = new ListNode(4);
	node2->next = node3;
	ListNode* node4 = new ListNode(5);
	node3->next = node4;
	ListNode* temp = head;
	int len = 0;
	vector<int> valnum;
	while (temp != NULL)
	{
		len++;
		valnum.push_back(temp->val);
		temp = temp->next;
	}
	if (len == 0 || k==0 || len ==1 || k%len==0)
		    return head;
	if (k > len)
		k = k % len;
	ListNode* newHead = new ListNode(valnum[valnum.size() - k]);
	ListNode* pre = newHead;
	ListNode* p;
	if (k <= 1)
	{
		for (int i = 0; i < valnum.size() - k; i++)
		{
			p = new ListNode(valnum[i]);
			pre->next = p;
			pre = p;
		}
	}
	else if (k > 1)
	{
		for (int i = valnum.size() - k + 1; i < valnum.size(); i++)
		{
			p = new ListNode(valnum[i]);
			pre->next = p;
			pre = p;
		}
		for (int i = 0; i < valnum.size() - k; i++)
		{
			p = new ListNode(valnum[i]);
			pre->next = p;
			pre = p;
		}
	}
	while (newHead != NULL)
	{
		cout << newHead->val << endl;
		newHead = newHead->next;
	}
    return 0; 
}
