#include "iostream"
using namespace std;
const int maxn=110;
struct caozuo{
    int opt;
    long long x;
};
int main()
{
    int n;
    long long X;
    scanf("%d%lld",&n,&X);
    caozuo A[maxn];
    long long ans=X;
    for(int i=0;i<n;i++)
        scanf("%d%lld",&A[i].opt,&A[i].x);
    for(int i=n-1;i>=0;i--)
    {
        if(A[i].opt==1)
            ans=ans-A[i].x;
        else if(A[i].opt==2)
            ans=ans+A[i].x;
        else if(A[i].opt==3)
            ans=ans/A[i].x;
        else if(A[i].opt==4)
            ans=ans*A[i].x;
    }
    printf("%lld",ans);
    return 0;
}
