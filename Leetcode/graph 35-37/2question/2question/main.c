//
//  main.c
//  2question
//
//  Created by Ivana_xuan on 2018/3/20.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
const int INF=10000;
int edge[12][12];//距离矩阵
int node[24];//坐标数为节点数2倍
int x[12];//存放路径

int ABS(int a,int b)
{
    int c=0;
    if(a-b<0)
        c=b-a;
    else
        c=a-b;
    return c;
}

int same(int j)
{
    int m=0;
    /*
    while(m<j)
    {
        if(x[m]==x[j])
            return 0;
        m++;
    }
    return 1;
     */

    while(x[m]!=x[j])
    {
        m++;
        if(m>=j)
            return 0;
    }
    return 1;

}

int bestans=INF;
int ans=0;
int N;

void backtrack(int n)
{
    if(n==N)
    {
        for(int j=1;j<=N;j++)
        {
            int g=x[n];
            x[n]=j;
            if(same(n)==0 && ans+edge[x[n-1]][j]+edge[j][N+1]<bestans)
                bestans=ans+edge[x[n-1]][x[n]]+edge[x[n]][N+1];
            x[n]=g;
        }
    }
    else
    {
        for(int j=1;j<=N;j++)
        {
            int g=x[n];
            x[n]=j;
            if(same(n)==0 && ans+edge[x[n-1]][j]<=bestans)
            {
                ans=ans+edge[x[n-1]][x[n]];
                backtrack(n+1);
                ans=ans-edge[x[n-1]][x[n]];
            }
            x[n]=g;
        }
    }
}

int main()
{
    scanf("%d",&N);
    scanf("%d%d%d%d",&node[0],&node[1],&node[2*(N+1)],&node[2*(N+1)+1]);
    int i=2;
    while(i<=2*N)
    {
        scanf("%d%d",&node[i],&node[i+1]);
        i+=2;
    }
    for(int j=0;j<=N+1;j++)
    {
        for(int k=0;k<=N+1;k++)
        {
            edge[j][k]=ABS(node[2*j],node[2*k])+ABS(node[2*j+1],node[2*k+1]);
            //edge[k][j]=edge[j][k];
        }//计算距离矩阵不要有错!!!
    }

    for (int j = 0; j < N + 2; j++)
    {
        for (int k = 0; k < N + 2; k++)
        {
            printf("%d ", edge[j][k]);
        }
        printf("\n");
    }
    
    x[0]=0;
    backtrack(1);
    printf("%d\n",bestans);
    return 0;
}
