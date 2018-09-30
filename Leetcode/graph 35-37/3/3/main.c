//
//  main.c
//  3
//
//  Created by Ivana_xuan on 2018/3/20.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//


#include "stdio.h"


int edge[1001][1001] = { 0 };

int main()
{
    int V, E;
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a][b] = 1;
    }
    int number = 0;
    int travel[1001] = { 0 };
    while (number < V)
    {
        for (int i = 1; i <= V; i++)
        {
            int num = 0;
            for (int j = 1; j <= V; j++)
                num += edge[j][i];
            if (num == 0 && travel[i]==0)
            {
                printf("%d ", i);
                travel[i] = 1;
                number++;
                for (int k = 1; k <= V; k++)
                    edge[i][k] = 0;
            }
        }
    }
    return 0;
}


