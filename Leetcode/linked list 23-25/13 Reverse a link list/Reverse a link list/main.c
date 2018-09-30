//
//  main.c
//  Reverse a link list
//
//  Created by Ivana_xuan on 2018/3/26.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
int N;

struct linklist
{
    int data;
    struct linklist *next;
};
struct linklist *head;
int array[1000]={0};

int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        scanf("%d",&N);
        struct linklist *p;
        head=(struct linklist*)malloc(sizeof(struct linklist));
        p=(struct linklist*)malloc(sizeof(struct linklist));
        head->next=p;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&p->data);
            array[i]=p->data;
            if(i<N-1)
            {
                p->next=(struct linklist*)malloc(sizeof(struct linklist));
                p=p->next;
            }
            else if(i==N-1)
                p->next=NULL;
        }
        struct linklist *q;
        q=head->next;
        for(int i=N-1;i>=0;i--)
        {
            q->data=array[i];
            q=q->next;
        }
        printf("#%d",time);
        q=head->next;
        for(int i=0;i<N;i++)
        {
            printf(" %d",q->data);
            q=q->next;
        }
        printf("\n");
        head->next=NULL;
    }
    return 0;
}
