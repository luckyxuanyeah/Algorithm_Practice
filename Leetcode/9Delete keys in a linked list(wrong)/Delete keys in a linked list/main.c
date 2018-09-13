//
//  main.c
//  Delete keys in a linked list
//
//  Created by Ivana_xuan on 2018/3/25.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>

int N,x;

struct Node
{
    int data;
    struct Node* next;//struct 不要忘了写
};

struct Node* head;//定义一个全局变量的链表list的头节点

struct Node* deleteAllOccurances(struct Node *head,int x)
{
    struct Node* p;
    struct Node* q;
    
    if(head->next->data==x)
        head->next=head->next->next;
    q=head;
    p=q->next;
        while(p!=NULL)
        {
            if(p->data==x)
            {
                q->next=p->next;
                p=p->next;
            }
            else
            {
                q=q->next;
                p=p->next;
            }
        }
    return head;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        scanf("%d",&N);
        struct Node *p;
        head=(struct Node*)malloc(sizeof(struct Node));
        p=(struct Node*)malloc(sizeof(struct Node));
        p=head->next;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&p->data);
            if(i<N-1)
            {
                p->next=(struct Node *)malloc(sizeof(struct Node));//申请下一个节点，并作了连接
                p=p->next;//将p节点移动到下一个位置
            }
        }
        struct Node* a;
        a=head->next;
        while(a!=NULL)
        {
            printf("%d ",a->data);
            a=a->next;
        }
        printf("\n");
        scanf("%d",&x);
        head=deleteAllOccurances(head,x);
        struct Node* q;
        q=head->next;
        printf("#%d ",time);
        while(q!=NULL)
        {
            printf("%d ",q->data);
            q=q->next;
        }
        printf("\n");
        
        /*
        for(int i=0;i<N;i++)
        {
            if(p->data!=x)
                printf(" %d",p->data);
            p=p->next;
        }
         
        printf("\n");
         */
    }
    return 0;
}
