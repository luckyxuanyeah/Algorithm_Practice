//
//  main.c
//  stack
//
//  Created by Ivana_xuan on 2018/3/27.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>

#define MaxSize 10
typedef int datatype;

typedef struct
{
    datatype *data;
    int top;
}stack;
int realsize=MaxSize;
stack s;
void init(stack *s)
{
    s->data=(datatype*)malloc(sizeof(datatype)*MaxSize);
    s->top=-1;
}

int empty(stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}

datatype Top()
{
    if(empty(&s)==0)
        return s.data[s.top];
    else
        printf("栈空");
}

int main()
{
    
    return 0;
}
