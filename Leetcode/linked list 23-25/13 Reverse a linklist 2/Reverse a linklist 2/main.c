//
//  main.c
//  Reverse a linklist 2
//
//  Created by Ivana_xuan on 2018/3/27.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node* reverse(struct Node *head)
{
    struct Node *temp1,*temp2,*temp3;
    temp1=NULL;
    temp2=head;
    temp3=head->next;
    
    while(temp3!=NULL)
    {
        temp2->next=temp1;
        temp1= temp2;
        temp2=temp3;
        temp3=temp3->next;
    }
    
    temp2->next=temp1;
    return temp2;
}

int main()
{
    int N;
    scanf("%d",&N);
    struct Node *p;
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    p=(struct Node*)malloc(sizeof(struct Node));
    head->next=p;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&p->data);
        if(i<N-1)
        {
            p->next=(struct Node*)malloc(sizeof(struct Node));
            p=p->next;
        }
        else if(i==N-1)
            p->next=NULL;
    }
    struct Node *newHead;
    newHead=reverse(head);
    for(int i=0;i<N;i++)
    {
        printf("%d ",newHead->data);
        newHead=newHead->next;
    }
    return 0;
}
