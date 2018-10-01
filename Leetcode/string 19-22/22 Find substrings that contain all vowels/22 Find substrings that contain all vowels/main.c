//
//  main.c
//  22 Find substrings that contain all vowels
//
//  Created by Ivana_xuan on 2018/4/2.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#define max 100000

int main(int argc, const char * argv[])
{
    char *str;
    str=(char*)malloc(max*sizeof(char));
    //str2=(char*)malloc(max*sizeof(char));
    scanf("%s",str);
    int length=0;
    while(str[length]!='\0')
        length++;
    for(int i=0;i<length;i++)
    {
        int count=0;
        for(int j=i;j<length;j++)
        {
            if(str[j]=='a'||str[j]=='e'||str[j]=='i'||str[j]=='o'||str[j]=='u')
                count++;
            else
                break;
            if(count>4)
            {
                int sum=0;
                int visited[5]={0};
                for(int k=j-count+1;k<=j;k++)
                {
                    if(str[k]=='a' && visited[0]==0)
                    {
                        visited[0]=1;
                        sum+=1;
                    }
                    if(str[k]=='e' && visited[1]==0)
                    {
                        visited[1]=1;
                        sum+=2;
                    }
                    if(str[k]=='i' && visited[2]==0)
                    {
                        visited[2]=1;
                        sum+=3;
                    }
                    if(str[k]=='o' && visited[3]==0)
                    {
                        visited[3]=1;
                        sum+=4;
                    }
                    if(str[k]=='u' && visited[4]==0)
                    {
                        visited[4]=1;
                        sum+=5;
                    }
                }
                if(sum==15)
                {
                    for(int m=j-count+1;m<=j;m++)
                        printf("%c",str[m]);
                    printf(" ");
                }
            }
        }
    }
    /*
    int i=0,count=0;
    int a=0;
    while(str[i]!='\0')
    {
        int number=0;
        while(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
        {
            if(count>0)
                printf(",");
            number++;
            i++;
            if(number>4)
            {
                count++;
                for(int j=i-count;j<count;j++)
                    printf("%c",str[j]);
                    str2[a++]=str[i];//为什么就是不走这里呢？？？？
            }
        }
        if(str[i]!='\0')
            i++;
    }
     */
    return 0;
}
