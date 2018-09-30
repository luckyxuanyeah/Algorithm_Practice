//
//  main.c
//  3 otherSolution
//
//  Created by Ivana_xuan on 2018/3/20.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#define MaxVex 100

typedef int VexType;
typedef int weightType;

typedef struct EdgeNode //边表结点
{
    int adjVex;//邻接点域，存顶点对应下标
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode //顶点表结点
{
    VexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MaxVex];

typedef struct
{
    AdjList adjlist;
    int numN,numE;
}GraphAdjList;

int main()
{
    
    return 0;
}
