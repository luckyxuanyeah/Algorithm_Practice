//
//  main.c
//  24 Rotate List
//
//  Created by Ivana_xuan on 2018/4/3.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.

//Given a list, rotate the list to the right by k places, where k is non-negative.

#include <stdio.h>
#include <malloc/malloc.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    /*int count=0;
    struct ListNode* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    int *array;
    array=(int *)malloc(count*sizeof(int));
    struct ListNode* p=head;
    for(int i=0;i<count-k;i++)
    {
        array[i]=p->val;
        p=p->next;
    }
    struct ListNode* Newhead=(struct ListNode*)malloc(sizeof(struct ListNode));
    Newhead=p;
    Newhead->next=NULL;
    struct ListNode* temp2=Newhead;
    for(int i=0;i<k;i++)
        temp2=temp2->next;
    temp2=(struct ListNode*)malloc(sizeof(struct ListNode));
    for(int i=0;i<count-k;i++)
    {
        temp2->val=array[i];
        if(i<count-k-1)
        {
            temp2->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp2=temp2->next;
        }
        else
            temp2->next=NULL;
    }
    return Newhead;
     */
    if(head==NULL || head->next==NULL || k==0)//k的位置为0不需要翻转,只有一个或者只有两个不需要翻转
        return head;
    struct ListNode* cur=head;
    int len=1;
    while(cur->next!=NULL)
    {
        cur=cur->next;
        len++;
    }
    cur->next=head;
    k=len-k%len;
    while(k--)
        cur=cur->next;
    head=cur->next;
    cur->next=NULL;
    return head;
}

int main()
{
    
    return 0;
}
