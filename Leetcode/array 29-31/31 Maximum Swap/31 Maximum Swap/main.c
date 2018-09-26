//
//  main.c
//  31 Maximum Swap
//
//  Created by Ivana_xuan on 2018/4/8.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

int maximumSwap(int num)
{
    int array[10]={0};
    int k=0;
    while(num!=0)
    {
        array[k++]=num%10;
        num=num/10;
    }
    for(int i=k-1;i>=0;i--)
    {
        int max=array[i];
        int pos=i;
        for(int j=i-1;j>=0;j--)
        {
            if(max<array[j])
            {
                max=array[j];
                pos=j;
            }
            if(pos!=i)
            {
                if(max==array[j])
                    pos=j;
            }
        }
        if(pos!=i)
        {
            int temp=array[i];
            array[i]=array[pos];
            array[pos]=temp;
            break;
        }
    }
    int ans=0;
    for(int j=k-1;j>=0;j--)
        ans=ans*10+array[j];
    return ans;
}


int main()
{
    
    return 0;
}
