//
//  main.c
//  Triplet sum in array
//
//  Created by Ivana_xuan on 2018/3/24.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

int n,x,ansN;
int array[200];

void quicksort(int l,int r)
{
    int i,j,x,temp;
    if(l<r)
    {
        i=l;
        j=r;
        x=array[l];
        while(i<j)
        {
            while(j>=l && array[j]>x)
                j--;
            if(i<j)
            {
                temp=array[i];
                array[i++]=array[j];
                array[j]=temp;
            }
            while(i<=r && array[i]<x)
                i++;
            if(i<j)
            {
                temp=array[j];
                array[j--]=array[i];
                array[i]=temp;
            }
        }
        array[i]=x;
        quicksort(l, i-1);
        quicksort(j+1, r);
    }
}

int getSumNum(int sum,int k)
{
    int i,j;
    for(i=0,j=n-1;i<j;)
    {
        if(array[i]+array[j]==sum && i!=k && j!=k)
            return 1;
        else if(array[i]+array[j]>sum)
            j--;
        else
            i++;
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        scanf("%d%d",&n,&x);
        for(int i=0;i<n;i++)
            scanf("%d",&array[i]);
        
        quicksort(0,n-1);
        
        printf("#%d ",time);
        for(int i=0;i<n;i++)
        {
            ansN=getSumNum(x-array[i],i);
            if(ansN==1)
                break;
            //printf("%d ",ansN);
        }
        if(ansN==1)
            printf("1\n");
        else
            printf("0\n");
        for(int i=0;i<n;i++)
            array[i]=0;
    }
    return 0;
}
