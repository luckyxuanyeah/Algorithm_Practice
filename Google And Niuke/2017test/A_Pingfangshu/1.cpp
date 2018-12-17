#include "iostream"
using namespace std;

int main()
{
    long long N;
    cin>>N;
    long long half=N/2;
    for(long long i=half;i>0;i--)
    {
        if(i*i<=N)
        {
            cout<<i*i<<endl;
            break;
        }
    }
    return 0;
}
