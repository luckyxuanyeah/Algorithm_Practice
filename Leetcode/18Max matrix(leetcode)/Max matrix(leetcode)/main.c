//
//  main.c
//  Max matrix(leetcode)
//
//  Created by Ivana_xuan on 2018/4/1.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize)
{
    int max=0;
    for(int i=matrixRowSize-1;i>=0;i--)
    {
        int line[100]={0};
        for(int j=matrixColSize-1;j>=0;j--)
        {
            for(int k=i;k>=0;k--)
            {
                if(matrix[k][j]-'0'==1)
                    line[j]+=1;
                else
                    break;
            }
        }
        int min=10000,temp=0;
        int ans=0;
        int number=0;
        for(int j=matrixColSize-1;j>=0;j--)
        {
            if(line[j]!=0)
            {
                temp=line[j];
                if(temp<min)
                {
                    if(ans<number*min)
                        ans=number*min;
                    min=temp;
                }
                number++;
            }
            else if(line[j]==0)
            {
                if(ans<number*min)
                    ans=number*min;
                number=0;
                min=10000;
            }
            if(j==0 && ans<number*min)
                ans=number*min;
        }
        if(max<ans)
            max=ans;
    }
    return max;
}

int main()
{
    int matrixRowSize,matrixColSize;
    scanf("%d%d",&matrixRowSize,&matrixColSize);
    for(int i=0;i<matrixRowSize;)
    scanf("%d",martix[i][j])
    return 0;
}
