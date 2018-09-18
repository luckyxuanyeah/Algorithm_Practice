//
//  main.c
//  Max matrix
//
//  Created by Ivana_xuan on 2018/3/31.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
int matrix[100][100];
int maxRow,maxCol;
int line[100];

void Count(int row)
{
    for(int j=maxCol-1;j>=0;j--)
    {
        for(int i=row;i>=0;i--)
        {
            if(matrix[i][j]==1)
                line[j]+=1;
            else
                break;
        }
    }
}

int maxRectangle()
{
    int min=10000,temp=0;
    int ans=0;
    int number=0;
    for(int i=maxCol-1;i>=0;i--)
    {
        if(line[i]!=0)
        {
            temp=line[i];
            if(temp<min)
            {
                if(ans<number*min)
                    ans=number*min;
                min=temp;
            }
            number++;
        }
        else if(line[i]==0)
        {
            if(ans<number*min)
                ans=number*min;
            number=0;
            min=10000;
        }
        if(i==0 && ans<number*min)
            ans=number*min;
    }
    return ans;
}

int main()
{
    int time;
    for(time=1;time<=10;++time)
    {
        scanf("%d%d",&maxRow,&maxCol);
        for(int i=0;i<maxRow;i++)
        {
            for(int j=0;j<maxCol;j++)
                scanf("%d",&matrix[i][j]);
        }
        /*
        for(int i=0;i<maxRow;i++)
        {
            for(int j=0;j<maxCol;j++)
                 printf("%d ",matrix[i][j]);
            printf("\n");
        }
         */
        int max=0;
        for(int i=maxRow-1;i>=0;i--)
        {
            Count(i);
            int k=maxRectangle();
            if(max<k)
                max=k;
            for(int i=0;i<maxRow;i++)
                line[i]=0;
        }
       
        printf("#%d %d\n",time,max);
        
        for(int i=0;i<maxRow;i++)
        {
            for(int j=0;j<maxCol;j++)
                matrix[i][j]=0;
        }
        for(int i=0;i<maxCol;i++)
            line[i]=0;
    }
    return 0;
}
