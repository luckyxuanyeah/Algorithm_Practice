//
//  main.c
//  text 3.20
//
//  Created by Ivana_xuan on 2018/3/20.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//
//#include <stdafx.h>
#include <stdio.h>
#include <malloc/malloc.h>

#define MAX 1000

int V, E, SUM;
int edge[1001][1001], edge2[1001][1001], edge3[1001][1001];
int vis[1001], visit[1001], visited[1001];
int dui[1001], Number[1001];
int list[1001];
int ans[1001], ansN;

int BFS_SUM()
{
    int out, in;
    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == 0)
        {
            in = 0;
            out = 0;
            dui[in++] = i;
            vis[i] = 1;
            while (out<in)
            {
                int v = dui[out++];
                Number[SUM]++;//每个子图中的节点个数
                edge3[SUM][v] = v;//每个子图中的节点存入数组
                for (int j = 1; j <= V; j++)//遍历v周围的节点
                {
                    if (edge2[v][j] == 1 && vis[j] == 0)
                    {
                        vis[j] = 1;
                        dui[in++] = j;
                    }
                }
            }
            SUM++;//子图的个数
        }
    }
    //printf("%d\n", SUM);   //子图的个数均数出正确
    return SUM;
}

typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
}Queue;

int isFull(Queue *pQueue)
{
    if ((pQueue->rear + 1) % MAX == pQueue->front)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *pQueue)
{
    if (pQueue->front == pQueue->rear)
        return 1;
    else
        return 0;
}

void initQueue(Queue * pQueue)
{
    pQueue->pBase = (int *)malloc(sizeof(int)*MAX);
    pQueue->front = 0;
    pQueue->rear = 0;
}

int inQueue(Queue *pQueue, int value)
{
    if (isFull(pQueue) == 1)
        return 0;
    else
    {
        pQueue->pBase[pQueue->rear] = value;//队尾入元素
        pQueue->rear = (pQueue->rear + 1) % MAX;//队尾加1
        return 1;
    }
}

int outQueue(Queue *pQueue, int *pValue)
{
    if (isEmpty(pQueue) == 1)
        return 0;
    else
    {
        *pValue = pQueue->pBase[pQueue->front];//队列首出队
        pQueue->front = (pQueue->front + 1) % MAX;//队首加1
        return 1;
    }
}

int equal(int lis[], int a)
{
    int count = 0, count2 = 0;
    for (int j = 1; j <= V; j++)
    {
        if (lis[j] != 0)
        {
            count++;
            //printf("%d ",lis[j]);
        }
        if (lis[j] == edge3[a][j] && lis[j]!=0 && edge3[a][j]!=0)
        {
            count2++;
            //printf("%d ",edge3[a][j]);
        }
    }
    //printf("%d %d\n",count,count2);
    if (count == count2)
        return 1;
    else
        return 0;
}


int BFS(int n, int number)
{
    Queue queue;
    initQueue(&queue);
    inQueue(&queue, n);
    for (int i = 1; i <= V; i++)
        visited[i] = 0;
    visited[n] = -1;//给起始点设置一个特殊标记，如果回到了起始点，那么就是有环
    list[n] = n;
    int k;
    while (isEmpty(&queue) == 0)//队列不空则循环（空返回1）
    {
        outQueue(&queue, &k);
        //visited[k]=-1;
        for (int i = 1; i <= V; i++)
        {
            if (edge[k][i] == 1 && visited[i] == 0)
            {
                inQueue(&queue, i);
                //printf("%d ",i);
                visited[i] = 1;
                list[i] = i;
                number++;
            }
            else if (edge[k][i] == 1 && visited[i] == -1)
            {
                ansN = number;
                int j = 0;
                for (int i = 1; i <= V; i++)
                {
                    if (list[i] != 0)
                        ans[j++] = list[i];
                }
                //printf("%d\n",ansN);
                //for (int i = 0; i<ansN; i++)
                    //printf("%d ", ans[i]);
                
                return 1;//有环
            }
        }
    }

    for (int i = 0; i<SUM; i++)
    {
        if (number == Number[i] && visit[i] == 0)
        {
            if (equal(list, i) == 1)
            {
                for(int i=1;i<=V;i++)
                    list[i]=0;
                //for(int i=1;i<=V;i++)
                    //printf("%d\n",list[i]);
                visit[i] = 1;
                number = 1;
                return 0;//有效的无环图遍历
            }
        }
    }
    for (int i = 1; i <= V; i++)
        list[i] = 0;
    number = 1;
    return -1;//无效的遍历
}


int main()
{
    int time;
    for (time = 1; time <= 10; ++time)
    {
        scanf("%d%d", &V, &E);
        int a, b;
        for (int i = 0; i<E; i++)
        {
            scanf("%d%d", &a, &b);
            edge[a][b] = 1;
            edge2[a][b] = 1;
            edge2[b][a] = 1;
        }
        SUM = BFS_SUM();
        
        int number = 1;
        for (int k = 1; k <= V; k++)
        {
            int s = BFS(k, number);
            if (s == 1)
                break;
            else if (s == 0)
            {
                int count = 0;
                for (int i = 0; i<SUM; i++)
                {
                    if (visit[i] == 1)
                        count++;
                }
                if (count == SUM)
                {
                    ansN = 0;
                    //printf("%d ", ansN);
                    break;
                }
            }
            else if (s == -1)
                continue;
        }
        
        printf("#%d", time);
        if (ansN == 0)
            printf(" 0\n");
        else
        {
            for (int i = 0; i<ansN; i++)
                printf(" %d", ans[i]);
            printf("\n");
        }
        SUM = 0;
        for (int i = 0; i <= V; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                edge[i][j] = 0;
                edge2[i][j] = 0;
                edge3[i][j] = 0;
            }
        }
        for (int i = 0; i <= V; i++)
        {
            vis[i] = 0;
            visit[i] = 0;
            visited[i] = 0;
            dui[i] = 0;
            Number[i] = 0;
            list[i] = 0;
            ans[i] = 0;
        }
    }
    return 0;
}

