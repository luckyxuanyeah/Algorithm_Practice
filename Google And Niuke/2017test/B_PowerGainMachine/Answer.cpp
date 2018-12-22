#include <iostream>
#include <vector>
using namespace std;

long long n,ceng;
vector<char> temp;
long long layer()
{
    long long number=0,t=0;
    while(t<n)
    {
        t=2*t+2;
        number++;
    }
    return number;
}

int main()
{
    scanf("%lld",&n);
    ceng=layer();
    long long t=n;
    while(t!=0)
    {
        if(t%2==0)
        {
            temp.push_back('G');
            t=(t-2)/2;
        }
        else if(t%2==1)
        {
            temp.push_back('N');
            t=(t-1)/2;
        }
    }
    for(long long i=ceng-1;i>=0;i--)
        printf("%c",temp[i]);
    return 0;
}
