class Solution {
public:
    int uniquePaths(int m, int n)
{
	int dp[101][101] = { 0 };
	for (int i = 1; i <= m; i++)
		dp[1][i] = 1;
	for (int j = 1; j <= n; j++)
		dp[j][1] = 1;
	dp[0][0] = 0, dp[0][1] = 0, dp[1][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
	return dp[n][m];
}
};
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths.
//Memory Usage: 8.2 MB, less than 78.55% of C++ online submissions for Unique Paths.
//Next challenges: Unique Paths II   Minimum Path Sum   Dungeon Game
