//
//  main.c
//  Longest Substring Without Repeating Characters
//
//  Created by Ivana_xuan on 2018/4/2.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#define MAX 100000


int same(int n,char* x)
{
    int m=0;
    while(m<n)
    {
        if(x[m]==x[n])
            return m;
        m++;
    }
    return -1;
}

int lengthOfLongestSubstring(char* s)
{
    int length=0,max=1;
    char* sub;
    sub=(char*)malloc(MAX*sizeof(char));//初始化指针型字符串数组
    while(s[length]!='\0')
        length++;
    if(length==0)
        return 0;
    int j=0;
    int pos=-1;
    for(int i=0;i<length;i++)
    {
        sub[j]=s[i];
        if(same(j,sub)==-1 && i!=length-1)
            j++;
        else if(same(j,sub)==-1 && i==length-1)
        {
            if(max<i-pos)
                max=i-pos;
        }
        else if(same(j,sub)!=-1)
        {
            int temp=pos;
            pos=same(j,sub);
            int count=0;
            for(int num=0;num<j;num++)
            {
                if(sub[num++]!='\0')
                    count++;
            }
            if(count>max)
                max=count;
            if(max<j-pos)
                max=j-pos;
            for(int k=temp;k<=pos;k++)
                sub[k]='\0';
            j++;
        }
    }
    return max;
}

int main()
{
    char* s;
    s=(char* )malloc(MAX*sizeof(char));
    scanf("%s",s);
    printf("%d\n",lengthOfLongestSubstring(s));
    return 0;
}
