#include <stdio.h>

int n,x;
int array[200];
int ans[200][3];

typedef struct
{
    int c,d;
}node;

void quicksort(int l,int r)
{
    int i,j,x,temp;
    if(l<r)
    {
        i=l;
        j=r;
        x=array[(l+r)/2];
        while(1)
        {
            while(i<=r && array[i]<x)
                i++;
            while(j>=l && array[j]>x)
                j--;
            if(i>=j)
                break;
            else
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
        quicksort(l, i-1);
        quicksort(j+1, r);
    }
}

node getSumNum(int sum,int k)
{
    int i,j;
    for(i=0,j=n-1;i<j;)
    {
        if(array[i]+array[j]==sum && i!=k && j!=k)
        {
            node a;
            a.c=i;
            a.d=j;
            return a;
        }
        else if(array[i]+array[j]>sum)
            j--;
        else
            i++;
    }
    node b;
    b.c=0;
    b.d=0;
    return b;
}

node ansN;

int main()
{
    
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
    
    quicksort(0,n-1);
    
    int count=0;
    for(int i=0;i<n;i++)
    {
        ansN=getSumNum(x-array[i],i);
        if(ansN.c!=0 && ansN.d!=0)
        {
            ans[count][0]=array[i];
            ans[count][1]=array[ansN.c];
            ans[count][2]=array[ansN.d];
            count++;
        }
    }
    for(int i=0;i<count;i++)
        printf("%d,%d,%d\n",ans[i][0],ans[i][1],ans[i][2]);
    
    return 0;
}

