//
//  main.c
//  TSP(back to 0)
//
//  Created by Ivana_xuan on 2018/3/28.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#define INF 2000001
int N,ansN,ans;
int edge[1000][1000];
int x[1000];

int same(int cur)
{
    int a=0;
    while(x[a]!=x[cur])
    {
        a++;
        if(a>=cur)
            return 0;
    }
    return 1;
}

void backtrack(int a)
{
    if(a==N-1)
    {
        for(int i=0;i<N;i++)
        {
            int g=x[a];
            x[a]=i;
            if(same(a)==0 && ans+edge[x[a-1]][i]+edge[i][0]<ansN)
            {
                ansN=ans+edge[x[a-1]][i]+edge[i][0];
                //printf("%d\n",ansN);
            }
            x[a]=g;
        }
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            int g=x[a];
            x[a]=i;
            if(same(a)==0 && ans+edge[x[a-1]][i]<=ansN)
            {
                ans=ans+edge[x[a-1]][i];
                //printf("%d",ans);
                backtrack(a+1);
                ans=ans-edge[x[a-1]][i];
            }
            x[a]=g;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        ansN=INF;
        ans=0;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                scanf("%d",&edge[i][j]);
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                printf("%d ",edge[i][j]);
            printf("\n");
        }
        x[0]=0;
        backtrack(1);
        printf("#%d %d\n",time,ansN);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                edge[i][j]=0;
        }
        for(int i=0;i<N;i++)
            x[i]=0;
    }
    return 0;
}
