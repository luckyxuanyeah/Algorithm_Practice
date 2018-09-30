//
//  main.c
//  Dijkstra
//
//  Created by Ivana_xuan on 2018/3/25.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

int edge[20][20];
int V,S;
int array[20];
int weight[20]={20001};

int count()
{
    int num=0;
    for(int i=0;i<V;i++)
    {
        if(array[i]!=-1)
            num++;
    }
    return num;
}

void Dijkstra(int S,int V)
{
    for(int i=0;i<V;i++)
    {
        if(edge[S][i]!=0)
            weight[i]=edge[S][i];
    }
    weight[S]=0;
    array[S]=S;
    
    int temp=20001,k=0;
    for(int i=0;i<V;i++)
    {
        if(i!=S && edge[S][i]<temp)
        {
            temp=edge[S][i];
            k=i;
        }
    }
    if(array[k]!=-1)
    {
        array[k]=k;
        weight[k]=temp;
    }
    while(count()<V)
    {
        for(int i=0;i<V;i++)
        {
            if(array[i]!=-1 && i!=S)
            {
                for(int j=0;j<V;j++)
                {
                    if(array[j]==-1 && i!=j && weight[i]+edge[i][j]<weight[j])
                        weight[j]=weight[i]+edge[i][j];
                }
            }
        }
        int temp2=20001,k2=0;
        for(int i=0;i<V;i++)
        {
            if(array[i]==-1 && weight[i]<temp2)
            {
                temp2=weight[i];
                k2=i;
            }
        }
        array[k2]=k2;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        scanf("%d",&V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
                scanf("%d",&edge[i][j]);
        }
        scanf("%d",&S);
        for(int i=0;i<V;i++)
            array[i]=-1;
        array[S]=S;
        
        Dijkstra(S,V);
        
        printf("#%d",time);
        for(int i=0;i<V;i++)
            printf(" %d",weight[i]);
        printf("\n");
        
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
                edge[i][j]=0;
        }
        for(int i=0;i<V;i++)
        {
            array[i]=-1;
            weight[i]=20001;
        }
    }
    return 0;
}
