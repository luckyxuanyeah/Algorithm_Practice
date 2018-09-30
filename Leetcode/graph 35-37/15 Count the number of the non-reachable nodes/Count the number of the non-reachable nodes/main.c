//
//  main.c
//  Count the number of the non-reachable nodes
//
//  Created by Ivana_xuan on 2018/3/27.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
int edge[1001][1001];
int visit[1001];
int N,E,start;

void DFS(int node)
{
    for(int i=0;i<N;i++)
    {
        if(edge[i][node]==1 && visit[i]==0)
        {
            visit[i]=1;
            DFS(i);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        scanf("%d%d%d",&N,&E,&start);
        int a,b;
        for(int i=0;i<E;i++)
        {
            scanf("%d%d",&a,&b);
            edge[a][b]=edge[b][a]=1;
        }
        DFS(start);
        int count=0;
        for(int i=0;i<N;i++)
        {
            if(visit[i]==0)
                count++;
        }
        printf("#%d %d\n",time,count);
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                edge[i][j]=0;
        }
        for(int i=0;i<N;i++)
            visit[i]=0;
        
    }
    return 0;
}
