#include "iostream"
#include "algorithm"
using namespace std;

const long long mod = 1e9 + 7;
long long dp[5005][2][55];
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N, A, B;
		scanf("%d%d%d", &N, &A, &B);
		for (int i = 0; i <= N; i++)
		{
			for (int j = 0; j <= 50; j++)
				dp[i][0][j] = dp[i][1][j] = 0;
		}
		if (N == 1 && A == 1 && B == 1)
		{
			printf("26\n");
			continue;
		}
		dp[1][0][1] = 5, dp[1][1][1] = 21;
		for (int i = 2; i <= N; i++)
		{
			for (int j = 2; j <= min(A, i); j++)
				dp[i][0][j] = (dp[i][0][j] + dp[i - 1][0][j - 1] * 5 % mod) % mod;
			for (int j = 2; j <= min(B, i); j++)
				dp[i][1][j] = (dp[i][1][j] + dp[i - 1][1][j - 1] * 21 % mod) % mod;
			for (int k = 1; k <= min(B, i - 1); k++)
				dp[i][0][1] += dp[i - 1][1][k] * 5 % mod;
			for (int k = 1; k <= min(A, i - 1); k++)
				dp[i][1][1] += dp[i - 1][0][k] * 21 % mod;
		}
		long long ans = 0;
		//单词最长长度为N，可以不超过N，这个也算是单词！！！
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 50; j++) {
				if (j <= A) 
					ans = (ans + dp[i][0][j]) % mod;
				if (j <= B) 
					ans = (ans + dp[i][1][j]) % mod;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
