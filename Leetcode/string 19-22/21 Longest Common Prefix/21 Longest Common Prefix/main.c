//
//  main.c
//  21 Longest Common Prefix
//
//  Created by Ivana_xuan on 2018/4/2.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.

//编写一个函数，在字符串数组中查找最长公共前缀字符串

#include <stdio.h>
char strs[30][100];


char* longestCommonPrefix(int strsSize)
{
    if(strsSize<=0)//特殊情况要考虑到
        return "";
    char *subString;
    subString=strs[0];
    for(int i=1;i<strsSize;i++)
    {
        int j=0;
        while(subString[j]!='\0' && strs[i][j]!='\0' && subString[j]==strs[i][j])//注意是循环
            j++;
        subString[j]='\0';
    }
    return subString;
}

int main()
{
    for(int i=0;i<2;i++)
        scanf("%s",strs[i]);
    printf("%s\n",longestCommonPrefix(2));
    return 0;
}
