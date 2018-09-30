//
//  main.c
//  Check Bipartite or not
//
//  Created by Ivana_xuan on 2018/3/25.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

int M,N,E;
int graph[1001][1001];
int color[1001];
int sum=0;

int isSafe(int cur)
{
    for(int i=1;i<=N;i++)
    {
        if(graph[i][cur]==1 && color[i]==color[cur])
            return 0;
    }
    return 1;
}

int BFS(int x)
{
    if(x>N)
    {
        sum++;
        return 1;
    }
    else
    {
        for(int i=1;i<=M;i++)
        {
            color[x]=i;
            if(isSafe(x)==1)
            {
                if(BFS(x+1)==1)
                {
                    //printf("%d",x);
                    return 1;
                }
            }
            color[x]=0;
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        scanf("%d%d%d",&N,&M,&E);
        int a,b;
        for(int i=0;i<E;i++)
        {
            scanf("%d%d",&a,&b);
            graph[a][b]=graph[b][a]=1;
        }
        printf("#%d\n",time);
        if (BFS(1)==1)//输出一种填充颜色情况下的 相同顶点的样例
        {
            int j=1;
            while(j<=M)
            {
                for(int i=1;i<=N;i++)
                {
                    if(color[i]==j)
                        printf("%d ",i);
                }
                printf("\n");
                j++;
            }
        }
        else
            printf("-1\n");
        for(int i=0;i<=E;i++)
        {
            for(int j=0;j<=E;j++)
                graph[i][j]=0;
        }
        for(int i=0;i<=E;i++)
            color[i]=0;
        sum=0;
    }
    return 0;
}
