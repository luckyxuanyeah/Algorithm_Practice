//
//  main.c
//  commonansesor
//
//  Created by Ivana_xuan on 2018/3/19.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include "stdio.h"
#include "malloc/malloc.h"

typedef int ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;//struct一定要有
    struct BiTNode *parent;
}BiTNode, *BiTree;

BiTNode * commonAns(BiTNode * T, BiTNode * node1, BiTNode * node2)//返回BiTNode型的节点的指针（即地址）
{
    BiTNode * temp;
    while (node1 != NULL)
    {
        node1 = node1->parent;
        temp = node2;
        while (temp != NULL)
        {
            if (node1== temp->parent)
                return node1;
            temp = temp->parent;//看是否正确？？？
        }
    }
    return T;
}

void number(BiTree T, int &num)//先序遍历
{
    if (T!= NULL)
    {
        num++;
        number(T->lchild, num);
        number(T->rchild, num);
    }
}

int main() {
    BiTree T;
    T = (BiTree)malloc(sizeof(BiTNode));
    int V, E, a, b;
    scanf("%d%d%d%d", &V, &E, &a, &b);
    T->data = 1;
    BiTNode node[10001] = { 0 };//装入顶点
    for (int i = 0; i<E; i++)
    {
        int c, d;
        scanf("%d%d", &c, &d);
        if (node[c].data == c && node[c].lchild == NULL)//赋值号一定要写对
        {
            node[d].data = d;
            node[c].lchild = &node[d];//node[c].lchild是指针类型 node[d]是BiTNode类型 取地址赋值给node[c].lchild
            node[d].parent = &node[c];
        }
        else if (node[c].data == c && node[c].lchild != NULL)
        {
            node[d].data = d;
            node[c].rchild = &node[d];
            node[d].parent = &node[c];
        }
        else
        {
            node[c].data = c;
            node[d].data = d;
            node[c].lchild = &node[d];
            node[d].parent = &node[c];
        }
    }
    int num = 0;
    BiTNode *ans = commonAns(T, &node[a], &node[b]);
    number(ans, num);
    printf("%d %d\n", ans->data, num);
    return 0;
}
