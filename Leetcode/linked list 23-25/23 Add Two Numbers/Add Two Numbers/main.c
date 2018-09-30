//
//  main.c
//  Add Two Numbers
//
//  Created by Ivana_xuan on 2018/4/2.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.

//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <stdio.h>
#include <malloc/malloc.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* Head;
    Head=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    Head->next=l3;
    int temp=0;
    if(l1==NULL && l2==NULL)
        return NULL;
    else if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    else
    {
        while(l1!=NULL && l2!=NULL)
        {
            l3->val=(l1->val+l2->val+temp)%10;
            temp=(l1->val+l2->val+temp)/10;
            l1=l1->next;
            l2=l2->next;
            if(l1!=NULL && l2!=NULL)
            {
                l3->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                l3=l3->next;
            }
        }
        while(l1==NULL && l2!=NULL)
        {
            l3->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            l3=l3->next;
            l3->val=(l2->val+temp)%10;
            temp=(l2->val+temp)/10;
            l2=l2->next;
        }
        while(l1!=NULL && l2==NULL)
        {
            l3->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            l3=l3->next;
            l3->val=(l1->val+temp)%10;
            temp=(l1->val+temp)/10;
            l1=l1->next;
        }
        return Head->next;
    }
}

int main()
{
    struct ListNode* l1,*l2;
    struct ListNode* p,*q;
    l1=(struct ListNode*)malloc(sizeof(struct ListNode));
    l2=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=(struct ListNode*)malloc(sizeof(struct ListNode));
    q=(struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next=p;//特别重要
    for(int i=0;i<3;i++)
    {
        scanf("%d",&p->val);
        if(i<9)
        {
            p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            p=p->next;
        }
    }
    l2->next=q;
    for(int i=0;i<3;i++)
    {
        scanf("%d",&q->val);
        if(i<6)
        {
            q->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            q=q->next;
        }
    }
    struct ListNode * Node=addTwoNumbers(l1->next, l2->next);
    for(int i=0;i<3;i++)
    {
        printf("%d ",Node->val);
        Node=Node->next;
    }
    return 0;
}
