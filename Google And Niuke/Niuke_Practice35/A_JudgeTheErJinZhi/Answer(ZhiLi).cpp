#include "iostream"
#include "vector"
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        long long N, temp,count=0;
        scanf("%lld", &N);
        temp = N;
        vector<int> er;
        if (N % 2 == 1 || N == 0 || N == 1 || N == 2 || N == 3)
            printf("NO\n");
        else
        {
            while (temp != 0)
            {
                er.push_back(temp % 2);
                if (temp % 2 == 1)
                    count++;
                temp = temp / 2;
            }
            if (count == 1 || count == 2)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
