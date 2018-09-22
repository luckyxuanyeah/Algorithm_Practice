//
//  main.c
//  max matrix(newnew)
//
//  Created by Ivana_xuan on 2018/4/2.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
int matrix[100][100];
int ans;

int find_Rect(int x,int y,int matrixRowSize,int matrixColSize)
{
    int length=0,width=0;
    for(int i=y;i<matrixColSize;i++)
    {
        if(matrix[x][i]==1)
            length++;
        else
            break;
    }
    for(int i=x;i<matrixRowSize;i++)
    {
        for(int j=y;j<y+length-1;j++)
        {
            if(matrix[i][j]==0 && j!=y)
            {
                length=j-y;
                width=i-x-1;
                if(length*width>ans)
                    ans=length*width;
            }
            else if(matrix[i][j]==0 && j==y)
            {
                width=i-x;
                if(length*width>ans)
                    ans=length*width;
                break;
            }
            if(matrix[i][j]==1 && i==matrixRowSize-1 && j==y+length-1)
            {
                if((i-x+1)*(j-y+1)>ans)
                    ans=(i-x+1)*(j-y+1);
            }
        }
    }
    return ans;
}


int maximalRectangle(int matrixRowSize, int matrixColSize)
{
    int max=0;
    for(int i=0;i<matrixRowSize;i++)
    {
        for(int j=0;j<matrixColSize;j++)
        {
            if(matrix[i][j]==1)
            {
                int tmp=find_Rect(i,j,matrixRowSize,matrixColSize);
                if(tmp>max)
                    max=tmp;
            }
        }
    }
    return max;
}

int main()
{
    int matrixRowSize,matrixColSize;
    scanf("%d%d",&matrixRowSize,&matrixColSize);
    for(int i=0;i<matrixRowSize;i++)
    {
        for(int j=0;j<matrixColSize;j++)
            scanf("%d",&matrix[i][j]);
    }
    for(int i=0;i<matrixRowSize;i++)
    {
        for(int j=0;j<matrixColSize;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    printf("%d\n",maximalRectangle(matrixRowSize, matrixColSize));
    
    return 0;
}
