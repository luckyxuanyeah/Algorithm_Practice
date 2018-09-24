//
//  main.c
//  array 3sum
//
//  Created by Ivana_xuan on 2018/4/18.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <malloc/malloc.h>

void quicksort(int l,int r,int* nums)
{
    int i,j,temp,x;
    if(l<r) //如果quicksort传进来的参数是l<r 这个时候才进行快速排序 否则为只剩一个数字
    {
        i=l;
        j=r;
        x=nums[l];
        while(i<j)//为一次确定位置的过程 i==j时结束 不要忘了这一步骤！！！
        {
            while(j>=l && nums[j]>x)//不要忘记j的界限，不能小于l
                j--;
            if(j>i)//如果j==i那么就剩一个数字
            {
                temp=nums[i];
                nums[i++]=nums[j];//i++千万不能忘！！！！
                nums[j]=temp;
            }
            while(i<=r && nums[i]<x)//不要忘记i的界限，不能大于r
                i++;
            if(i<j)
            {
                temp=nums[j];
                nums[j--]=nums[i];//j--千万不能忘！！！！
                nums[i]=temp;
            }
        }
        nums[i]=x;//将值赋给nums[i]不能忘记！！！
        quicksort(l, i-1, nums);
        quicksort(j+1, r, nums);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int** returnArray=(int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6);//分配的大小注意！！
    int top=0;
    if(numsSize<3)//如果数组中小于3个数
    {
        *returnSize=0;
        return returnArray;
    }
    quicksort(0, numsSize-1, nums);//快速排序时间复杂度nlog(n)
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>0)//如果现在遍历到的数值为正
            break;
        if(i>0 && nums[i]==nums[i-1])//如果遍历到的数值和左边的数值一样 就结束这次循环 这里对i进行判断
            continue;
        int sum=0-nums[i];
        for(int j=i+1,k=numsSize-1;j<k;)
        {
            if(nums[j]+nums[k]==sum)
            {
                top++;//存入到第top个位置
                returnArray[top]=(int*)malloc(sizeof(int)*3);
                returnArray[top][0]=nums[i];
                returnArray[top][1]=nums[j];
                returnArray[top][2]=nums[k];
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])//注意如果这个数和左边的数一致 就j++
                    j++;
                while(j<k && nums[k]==nums[k+1])//注意如果这个数和右边的数一样 就k--
                    k--;
            }
            else if(nums[j]+nums[k]>sum)//注意这里的条件是大的时候k--！！！
                k--;
            else      "这里是除了上面的情况都"j++"！！！"
                j++;
        }
    }
    *returnSize=top+1;
    return returnArray;
}


int main()
{
    for(int i=0;i<6;i++)
        scanf("%d",&nums[i]);
    //int num=2;
    //int* returnSize=&num;
    int **array=threeSum();
    for(int i=0;i<2;i++)
        printf("%d%d%d\n",array[i][0],array[i][1],array[i][2]);
    return 0;
}
