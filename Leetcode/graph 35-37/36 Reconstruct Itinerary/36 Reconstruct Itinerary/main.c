//
//  main.c
//  36 Reconstruct Itinerary
//
//  Created by Ivana_xuan on 2018/4/8.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */


int Judge(char* a,char *b)//a小于b返回-1，a大于b返回1，相等返回0
{
    int i=0;
    while(i<3)
    {
        if(a[i]<b[i])
            return -1;
        else if(a[i]==b[i])
            i++;
        else if(a[i]>b[i])
            return 1;
    }
    return 0;
}

char** findItinerary(char*** tickets, int ticketsRowSize, int ticketsColSize, int* returnSize)
{
    char** array;
    array=(char**)malloc(*returnSize*sizeof(char*));
    for(int i=0;i<*returnSize;i++)
        array[i]=(char*)malloc(3*sizeof(char));
    int visit[ticketsRowSize];
    for(int i=0;i<ticketsRowSize;i++)
        visit[i]=0;
    int in=0,out=0;
    array[in++]="JFK";
    int pos=0;
    while(in<ticketsRowSize+1)
    {
        char* start=array[out];
        for(int i=0;i<ticketsRowSize;i++)
        {
            if(visit[i]==0)
            {
                if(Judge(tickets[i][0],start)==0 && pos!=i)
                {
                    for(int j=1;j<ticketsColSize;j++)
                    {
                        if(Judge(tickets[pos][0],start)==0)
                        {
                            int p=Judge(tickets[pos][j],tickets[i][j]);
                            if(p==0)
                                continue;
                            else if(p==-1)
                            {
                                array[in]=tickets[pos][j];
                                break;
                            }
                            else if(p==1)
                            {
                                pos=i;
                                array[in]=tickets[i][j];
                                break;
                            }
                        }
                        else
                        {
                            pos=i;
                            array[in]=tickets[pos][j];
                        }
                        
                    }
                }
            }
        }
        visit[pos]=1;
        in++;
        out++;
    }
    return array;
}

int main(int argc, const char * argv[])
{
    
    char*** ticket;
    int num1,num2;
    scanf("%d%d",&num1,&num2);
    ticket=(char***)malloc(num1*sizeof(char**));
    for(int i=0;i<num1;i++)
    {
        ticket[i]=(char**)malloc(num2*sizeof(char*));
        for(int j=0;j<3;j++)
            ticket[i][j]=(char*)malloc(sizeof(char));
    }
    for(int i=0;i<num1;i++)
    {
        for(int j=0;j<num2;j++)
            scanf("%s",ticket[i][j]);
    }
    int b=6;
    int * a=&b;
    char ** ans=findItinerary(ticket, num1, num2, a);
    for(int i=0;i<b;i++)
        printf("%s*",ans[i]);
    
    return 0;
}
