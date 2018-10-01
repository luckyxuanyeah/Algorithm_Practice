//
//  main.c
//  Split Strings
//
//  Created by Ivana_xuan on 2018/4/2.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
char str[1000],s1[1000],s2[1000],s3[1000];

int main()
{
    for(int time=1;time<=10;++time)
    {
        scanf("%s",str);//输入字符串一样的！！！
        int length=0;
        while(str[length]!='\0')
            length++;
        int a1=0,a2=0,a3=0;
        for(int i=0;i<length;i++)
        {
            if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
                s1[a1++]=str[i];
            else if(str[i]>=48 && str[i]<=57)
                s2[a2++]=str[i];
            else
                s3[a3++]=str[i];
        }
        s1[a1]='\0',s2[a2]='\0',s3[a3]='\0';//特别重要啊
        printf("%s\n%s\n%s",s1,s2,s3);
    }
    return 0;
}
