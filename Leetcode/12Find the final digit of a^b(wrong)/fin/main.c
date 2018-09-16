//
//  main.c
//  fin
//
//  Created by Ivana_xuan on 2018/3/26.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>


int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        int temp=a%10;
        if(temp==0||temp==1||temp==5||temp==6)
            printf("%d\n",temp);
        else
        {
            int k=1;
            int array[10]={-1};
            int sum=temp;
            while(array[k-1]!=temp)
            {
                array[k++]=(sum*temp)%10;
                sum=sum*temp;
            }
            int temp2=b%(k-1);
            int ans=1;
            for(int i=1;i<=temp2;i++)
                ans*=temp;
            printf("%d\n",ans%10);
        }
        
    }
    return 0;
}
