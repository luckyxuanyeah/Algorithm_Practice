//
//  main.c
//  Find the final digit of a^b
//
//  Created by Ivana_xuan on 2018/3/27.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#define max 10000000
int main()
{
    int ch;
    int number=0;
    int flag=1;
    int array[max]={0};
    int i=0;
    while((ch=getchar())!=EOF)
    {
        if(flag==1)
            break;
        putchar(ch);
        number++;
        array[i++]=ch;
        if(ch=='\n')
            flag=1;
    }
          
    return 0;
}
