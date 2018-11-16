//
//  main.c
//  test 3.29(sha)
//
//  Created by Ivana_xuan on 2018/3/30.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>

long long a,b,c,k;
long long ansN;
long long array[64];

long long chengfang(long long number)
{
    long long sum=1;
    for(int i=1;i<=array[number];i++)
        sum=sum*2;
    return sum;
}

long long judge(long long n1)
{
    if(n1==1)
        return array[0];
    else
    {
        for(int i=1;i<=63;i++)
        {
            if(n1>=chengfang(array[i]) && n1<=chengfang(array[i+1])-1)
                return array[i];
        }
    }
    return 0;
}


long long ans(long long n)
{
    long long m=judge(n);
    long long ANS=a*n;
    if(ANS<n)
        return -1;
    long long ANS2=b*n;
    if(ANS2<n)
        return -1;
    ANS2=ANS2*m;
    if(ANS2<n)
        return -1;
    if(c==0)
    {
        ANS=ANS+ANS2;
        if(ANS<n)
            return -1;
    }
    else
    {
        long long ANS3=c*n;
        if(ANS3<n)
            return -1;
        ANS3=ANS3*n;
        if(ANS3<n)
            return -1;
        ANS3=ANS3*n;
        if(ANS3<n)
            return -1;
        ANS=ANS+ANS2+ANS3;
        if(ANS<n)
            return -1;
    }
    return ANS;
}

long long getNum(long long p,long long q)
{
    long long num=0;
    while(p<q)
    {
        num=(q+p)/2;
        //printf("@@@@%lld\n",num);
        long long z=0;
        z=ans(num);
        if(z==-1)
            q=num-1;
        else if(z==k)
        {
            //printf("$%lld ",z);
            return num;
        }
        else if(z>k)
        {
            //printf("^%lld ",z);
            q=num-1;
        }
        else if(z<k)
        {
            //printf("@%lld ",z);
            p=num+1;
        }
    }
    if(ans(p)==k)
    {
        //printf("!!!!%lld",ans(p));
        return p;
    }
    return 0;
}

int main()
{
    int time;
    for(time=1;time<=10;++time)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
        long long end=9223372036854775806;
        for(int i=0;i<64;i++)
            array[i]=i;
        ansN=getNum(1,end);
        printf("#%d %lld\n",time,ansN);
    }
    return 0;
}
