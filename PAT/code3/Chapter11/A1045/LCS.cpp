#include "stdio.h"
#include "algorithm"
using namespace std;

const int MAX = 210;
const int INF = 10010;
int dp[MAX][INF];
int A[MAX], B[INF];
int main()
{
	int N, M, L;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &A[i]);
		dp[i][0] = 0;
	}
	scanf("%d", &L);
	for (int i = 1; i <= L; i++)
	{
		scanf("%d", &B[i]);
		dp[0][i] = 0;
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			if (A[i] == B[j])
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printf("%d", dp[M][L]);
	return 0;
}
