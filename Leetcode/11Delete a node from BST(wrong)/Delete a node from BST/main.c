//
//  main.c
//  Delete a node from BST
//
//  Created by Ivana_xuan on 2018/3/25.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

int N;
int array[50];



int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%d",&array[i]);
        
        
        
        printf("#%d ",time);
        
    }
    return 0;
}
