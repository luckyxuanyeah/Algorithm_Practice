#include "iostream"
#include "algorithm"
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int A[100010]={0},B[100010]={0};
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    sort(A+1,A+n+1);
    int i=0,j=n;
    long long ans=0;
    int count=0;
    while(i<j)
    {
        B[count++]=A[i++];
        B[count++]=A[j--];
    }
    B[count]=A[j];
    for(int i=1;i<=n;i++)
        ans+=(B[i]-B[i-1])*(B[i]-B[i-1]);
    printf("%lld",ans);
    return 0;
}
