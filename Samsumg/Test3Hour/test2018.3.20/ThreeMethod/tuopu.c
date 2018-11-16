//
//  main.c
//  test 3.20(tuopu)
//
//  Created by Ivana_xuan on 2018/3/23.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

int edge[1001][1001];
int ansN,V,E,in,out;
int ans[1001];
int dui[1001],vis[1001],sort[1001],visited[1001];

int judge1()
{
    for(int i=1;i<=V;i++)
    {
        int sum=0;
        for(int j=1;j<=V;j++)
            sum=edge[j][i]+sum;
        if(sum==0 && visited[i]==0)
        {
            visited[i]=1;
            return i;
        }
    }
    return 0;
}
int judge2()
{
    for(int i=1;i<=V;i++)
    {
        int sum=0;
        for(int j=1;j<=V;j++)
            sum=edge[i][j]+sum;
        if(sum==0 && visited[i]==0)
        {
            visited[i]=1;
            return i;
        }
    }
    return 0;
}

int iscircle()
{
    int num=0;
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            num=num+edge[i][j];
            if(num!=0)
                return i;
        }
    }
    return 0;
}

void findcircle(int a)
{
        in=0;
        out=0;
        dui[in++]=a;
        vis[a]=1;
        while(out<in)
        {
            int v=dui[out++];
            for(int i=1;i<=V;i++)
            {
                if(edge[v][i]==1 && vis[i]==0)
                {
                    vis[i]=1;
                    dui[in++]=i;
                }
            }
        }
}

int main()
{
    int time;
    for(time=1;time<=10;++time)
    {
        scanf("%d%d",&V,&E);
        int a,b;
        for(int i=0;i<E;i++)
        {
            scanf("%d%d",&a,&b);
            edge[a][b]=1;
        }
        int n=judge1();
        while(n!=0)
        {
            for(int i=1;i<=V;i++)
                edge[n][i]=0;
            n=judge1();
        }
        int m=judge2();
        while(m!=0)
        {
            for(int i=1;i<=V;i++)
                edge[i][m]=0;
            m=judge2();
        }
        printf("#%d",time);
        if(iscircle()!=0)
        {
            int node=iscircle();
            findcircle(node);
            for(int i=0;i<in;i++)
                sort[dui[i]]=dui[i];
            int j=0;
            for(int i=1;i<=V;i++)
            {
                if(sort[i]!=0)
                    ans[j++]=sort[i];
            }
            ansN=in;
        }
        else
        {
            ansN=0;
            printf("%d\n",ansN);
        }
        
        if(ansN!=0)
        {
            for(int i=0;i<ansN;i++)
                printf(" %d",ans[i]);
            printf("\n");
        }
        
        ansN=0;
        in=0;
        out=0;
        for(int i=0;i<=V;i++)
        {
            for(int j=0;j<=V;j++)
                edge[i][j]=0;
        }
        for(int i=0;i<=V;i++)
        {
            ans[i]=0;
            dui[i]=0;
            vis[i]=0;
            sort[i]=0;
            visited[i]=0;
        }
    }
    return 0;
}
