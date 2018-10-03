//
//  main.c
//  Unique BST's
//
//  Created by Ivana_xuan on 2018/3/24.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

int N,ansN;


int DC_number(int n)
{
    if(n<=1)
        return 1;
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=DC_number(i-1)*DC_number(n-i);
    return sum;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        scanf("%d",&N);
        
        ansN=DC_number(N);
        
        printf("#%d %d\n",time,ansN);
        
    }
    return 0;
}
