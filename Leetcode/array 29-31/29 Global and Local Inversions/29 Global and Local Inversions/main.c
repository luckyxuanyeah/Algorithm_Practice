//
//  main.c
//  29 Global and Local Inversions
//
//  Created by Ivana_xuan on 2018/4/7.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#define N 5000
int array[3];
int visited[3];
int isIdealPermutation(int ASize)
{
    if(ASize==0 || ASize==1 ||ASize==2 )
        return 1;
    for(int i=0;i<ASize;i++)
    {
        if(array[i]>array[i+1] && i+1<ASize && visited[i]==0 && visited[i+1]==0)
        {
            int temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
            visited[i]=1;
            visited[i+1]=1;
        }
    }
    int count=0;
    for(int i=0;i<ASize;i++)
    {
        if(array[i]+1==array[i+1] && i+1<ASize)
            count++;
    }
    if(count==ASize-1 )
        return 1;
    else
        return 0;
}
int main()
{
    //array=(int *)malloc(N*sizeof(int));
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    array[0]=a;
    array[1]=b;
    array[2]=c;
    printf("%d\n",isIdealPermutation(3));
    return 0;
}
