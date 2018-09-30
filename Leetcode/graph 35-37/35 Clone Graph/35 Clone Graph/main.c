//
//  main.c
//  35 Clone Graph
//
//  Created by Ivana_xuan on 2018/4/8.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#define NEIGHBORS_MAX_SIZE 100

struct UndirectedGraphNode {
    int label;
    struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
    int neighborsCount;
};

int isSame(struct UndirectedGraphNode *node,int num,struct UndirectedGraphNode *array[])
{
    for(int i=0;i<num;i++)
    {
        if(node->label==array[i]->label)
            return 1;
    }
    return 0;
}

struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph)
{
    if(graph==NULL)
        return graph;
    struct UndirectedGraphNode *queue[NEIGHBORS_MAX_SIZE];//存放原来的点
    struct UndirectedGraphNode *queue1[NEIGHBORS_MAX_SIZE];//存放新建的点
    int in=0,in1=0,out=0,out1=0;
    queue[in++]=graph;
    
    struct UndirectedGraphNode *graph1=(struct UndirectedGraphNode*)malloc(sizeof(struct UndirectedGraphNode));
    graph1->neighborsCount=graph->neighborsCount;
    graph1->label=graph->label;
    for(int i=0;i<graph1->neighborsCount;i++)
        graph1->neighbors[i]=NULL;
    
    queue1[in1++]=graph1;
    int visit[NEIGHBORS_MAX_SIZE]={0};
    while(out<in)
    {
        if(queue[out]!=NULL && queue1[out1]!=NULL && visit[out1]==0)
        {
            if(queue[out]->neighborsCount!=0)
            {
                for(int i=0;i<queue[out]->neighborsCount;i++)
                {
                    if(isSame(queue[out]->neighbors[i],in,queue)==0)
                    {
                        queue[in++]=queue[out]->neighbors[i];
                        
                        queue1[out1]->neighbors[i]=(struct UndirectedGraphNode*)malloc(sizeof(struct UndirectedGraphNode));
                        queue1[out1]->neighbors[i]->label=queue[out]->neighbors[i]->label;
                        queue1[out1]->neighbors[i]->neighborsCount=queue[out]->neighbors[i]->neighborsCount;
                        for(int j=0;j<queue1[out1]->neighbors[i]->neighborsCount;j++)
                            queue1[out1]->neighbors[i]->neighbors[j]=NULL;
                        queue1[in1++]=queue1[out1]->neighbors[i];
                    }
                }
                visit[out1]=1;
            }
        }
        out++;
        out1++;
    }
    return graph1;
}

int main()
{
    struct UndirectedGraphNode *a=(struct UndirectedGraphNode*)malloc(sizeof(struct UndirectedGraphNode));
    struct UndirectedGraphNode *b=(struct UndirectedGraphNode*)malloc(sizeof(struct UndirectedGraphNode));
    struct UndirectedGraphNode *c=(struct UndirectedGraphNode*)malloc(sizeof(struct UndirectedGraphNode));
    a->label=0;
    a->neighborsCount=2;
    a->neighbors[0]=b;
    a->neighbors[1]=c;
    
    b->label=1;
    b->neighborsCount=2;
    b->neighbors[0]=a;
    b->neighbors[1]=c;
    c->label=2;
    c->neighborsCount=3;
    c->neighbors[0]=a;
    c->neighbors[1]=b;
    c->neighbors[2]=c;
    
    struct UndirectedGraphNode *ans=cloneGraph(a);
    printf("%d\n%d\n%d\n%d\n%d\n",ans->label,ans->neighborsCount,ans->neighbors[0]->label,ans->neighbors[0]->neighborsCount,ans->neighbors[1]->label);
    return 0;
}
