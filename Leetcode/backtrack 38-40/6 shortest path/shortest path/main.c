//
//  main.c
//  shortest path
//
//  Created by Ivana_xuan on 2018/3/23.
//  Copyright © 2018年 Ivana_xuan. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>

typedef int datatype;

const int INF=10000;
int n,m,X,Y;
int bestans,bestans1,bestans2,ans1,ans2,number1,number2;
int matrix[20][20];

struct point{
    int x,y;
}p;

struct point visited1[400];
struct point visited2[400];//不要忘记写struct

int ABS(int a,int b)
{
    int c=0;
    if(a-b<0)
        c=b-a;
    else
        c=a-b;
    return c;
}

int same1(int d)
{
    int c=0;
    while(c<d)
    {
        if(visited1[c].x==visited1[d].x && visited1[c].y==visited1[d].y)
            return 1;
        c++;
    }
    return 0;
}

int same2(int d)
{
    int c=0;
    while(c<d)
    {
        if(visited2[c].x==visited2[d].x && visited2[c].y==visited2[d].y)
            return 1;
        c++;
    }
    return 0;
}

void backtrack1(struct point a)
{
    //printf("%d %d\n",a.x,a.y);
    
    if(((ABS(a.x,X)==1 && a.y==Y) || (a.x==X && ABS(a.y,Y)==1)) && matrix[X][Y]==1)
    {
        struct point temp=visited1[number1];
        visited1[number1].x=X;
        visited1[number1].y=Y;
        
        //printf("%d%d\n",visited[number].x,visited[number].y);
        //printf("%d\n\n",number);
        
        //printf("%d\n",same(number));
        if(same1(number1)==0 && ans1+1<bestans1)
        {//表示和之前的点坐标不相同
            bestans1=ans1+1;
            //printf("@%d\n",bestans1);
        }
        visited1[number1]=temp;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                struct point temp=visited1[number1];//不要忘记struct
                visited1[number1].x=i;
                visited1[number1].y=j;
                if(((ABS(i,a.x)==1 && j==a.y)|| (i==a.x && ABS(j,a.y)==1))&& matrix[i][j]==1 && same1(number1)==0 && ans1+1<=bestans1)
                {
                    ans1=ans1+1;
                    
                    //printf("%d ",ans);
                    
                    backtrack1(visited1[number1++]);
                    ans1=ans1-1;
                }
                visited1[number1]=temp;
            }
        }

    }
}




void backtrack2(struct point a)
{
    if(((ABS(a.x,X)==1 && a.y==Y) || (a.x==X && ABS(a.y,Y)==1)) && matrix[X][Y]==1)
    {
        struct point temp=visited2[number2];
        visited2[number2].x=X;
        visited2[number2].y=Y;
    
        if(same2(number2)==0 && ans2+1<bestans2)
            bestans2=ans2+1;

        visited2[number2]=temp;
    }
    else
    {
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                struct point temp=visited2[number2];//不要忘记struct
                visited2[number2].x=i;
                visited2[number2].y=j;
                if(((ABS(i,a.x)==1 && j==a.y)|| (i==a.x && ABS(j,a.y)==1))&& matrix[i][j]==1 && same2(number2)==0 && ans2+1<=bestans2)
                {
                    ans2=ans2+1;
                    
                    //printf("%d ",ans);
                    
                    backtrack2(visited2[number2++]);
                    ans2=ans2-1;
                }
                visited2[number2]=temp;
            }
        }
        
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int time=1;time<=T;++time)
    {
        bestans1=bestans2=INF;
        ans1=ans2=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                scanf("%d",&matrix[i][j]);
        }
        scanf("%d%d",&X,&Y);
        
        visited1[0].x=0;
        visited1[0].y=0;
        number1=1;
        backtrack1(visited1[0]);
        
        visited2[0].x=0;
        visited2[0].y=0;
        number2=1;
        backtrack2(visited2[0]);
        if(bestans1<bestans2)
            bestans=bestans1;
        else
            bestans=bestans2;
        
        if(matrix[0][0]==0)//当起始点为不通时
            printf("-1\n");
        else if(X==0 && Y==0)//当终点为起始点时
            printf("0\n");
        else if(bestans==INF)//当找不到路经时
            printf("-1\n");
        else
            printf("#%d %d\n",time,bestans);
        
        //printf("#%d %d\n",time,bestans);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                matrix[i][j]=0;
        }
        for(int i=0;i<n*m;i++)
        {
            visited1[i].x=0;
            visited1[i].y=0;
            visited2[i].x=0;
            visited2[i].y=0;
        }
    }
    return 0;
}
