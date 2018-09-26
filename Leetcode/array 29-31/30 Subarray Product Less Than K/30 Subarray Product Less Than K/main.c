//
//  main.c
//  30 Subarray Product Less Than K
//
//  Created by Ivana_xuan on 2018/4/7.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include<malloc/malloc.h>
#define MAX 50000
int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    int count=0;
    int pos=1;
    for(int i=0,j=0;j<numsSize;j++)
    {
        pos=pos*nums[j];
        while(pos>=k && i<=j)
            pos=pos/nums[i++];
        count=count+j-i+1;
    }
    /*超时 77/84
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        int time=0;
        long long product=nums[i];
        int cur=i;
        while(product<k && cur<numsSize)
        {
            cur++;
            time++;
            product=product*nums[cur];
        }
        count+=time;
    }
    */
    /*超时 47/84
    int i=1;
    while(i<=numsSize)
    {
        for(int j=0;j<numsSize;j++)
        {
            if(numsSize-j<i)
                break;
            long long product=1;
            int cur=j;
            int time=i;
            while(time!=0 && cur<numsSize && product<k)
            {
                product=product*nums[cur];
                cur++;
                time--;
            }
            if(product<k && cur-j==i)
                count++;
        }
        i++;
    }
     */
    return count;
}

int main(int argc, const char * argv[]) {
    int *nums;
    nums=(int *)malloc(MAX*sizeof(int));
    int NUM;
    scanf("%d",&NUM);
    for(int i=0;i<NUM;i++)
        scanf("%d",&nums[i]);
    int k;
    scanf("%d",&k);
    printf("%d\n",numSubarrayProductLessThanK(nums, NUM, k));
    return 0;
}
