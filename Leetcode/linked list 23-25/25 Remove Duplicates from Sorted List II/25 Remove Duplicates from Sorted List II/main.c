//
//  main.c
//  25 Remove Duplicates from Sorted List II
//
//  Created by Ivana_xuan on 2018/4/3.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

#include <stdio.h>
#include <malloc/malloc.h>
struct ListNode
{
     int val;
     struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head==NULL)
        return head;
    struct ListNode* helper=(struct ListNode*)malloc(sizeof(struct ListNode));//定义一个前驱指针
    helper->next=head;
    struct ListNode* cur=head;
    struct ListNode* pre=helper;
    while(cur!=NULL)
    {
        while(cur->next!=NULL && pre->next->val==cur->next->val)
            cur=cur->next;
        if(pre->next==cur)
            pre=pre->next;
        else
            pre->next=cur->next;
        cur=cur->next;
    }
    
    return helper->next;
    
    /*
    int *array;
    array=(int *)malloc(len*sizeof(int));
    int number=0;
    int temp=cur->val;
    while(cur!=NULL)
    {
        
        if(temp!=cur->next->val)
        {
            cur=cur->next;
            temp=cur->val;
        }
        else if(cur->val==cur->next->val)
        {
            temp=cur->val;
            struct ListNode* link=cur;
            while(temp==cur->next->val)
                cur=cur->next;
            link=cur->next;
            int count=1;
            struct ListNode* p=cur;
            int temp=p->val;
            p=p->next;
            while(p->val==temp)
            {
                count++;
                p=p->next;
            }
            for(int i=0;i<count;i++)
                cur=cur->next;
        }
    }
    struct ListNode* Newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* q=Newhead;
    int i=0;
    while(i!=number)
    {
        q->val=array[i];
        q=q->next;
        i++;
    }
     */
}

int main(int argc, const char * argv[])
{
    return 0;
}
