/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head,*node,*pre;
        head=new ListNode(0);
        head->next=NULL;
        pre=head;
        int temp=0;
        while(l1!=NULL && l2!=NULL)
        {
            node=new ListNode((l1->val+l2->val+temp)%10);//新建的一个链表节点，将这个节点需要和之前的链表连接起来
            temp=(l1->val+l2->val+temp)/10;
            node->next=NULL;
            l1=l1->next;
            l2=l2->next;
            pre->next=node;
            pre=node;
        }
        while(l1==NULL && l2!=NULL)
        {
            node=new ListNode((l2->val+temp)%10);
            temp=(l2->val+temp)/10;
            node->next=NULL;
            l2=l2->next;
            pre->next=node;
            pre=node;
        }
        while(l1!=NULL && l2==NULL)
        {
            node=new ListNode((l1->val+temp)%10);
            temp=(l1->val+temp)/10;
            node->next=NULL;
            l1=l1->next;
            pre->next=node;
            pre=node;
        }
        if(l1==NULL && l2==NULL && temp!=0)//这里需要注意，一定不要忘记两个数如果一样需要再加上进位呀！！！
        {
            node=new ListNode(temp%10);
            temp=temp/10;
            node->next=NULL;
            pre->next=node;
            pre=node;
        }
        return head->next;
    }
};

//Runtime: 40 ms, faster than 97.14% of C++ online submissions for Add Two Numbers.
//	Memory Usage : 19.1 MB, less than 63.01% of C++ online submissions for Add Two Numbers.
//	Next challenges :
//		 Multiply Strings
//			 Add Binary
//			 Sum of Two Integers
//			 Add Strings
//			 Add Two Numbers II
