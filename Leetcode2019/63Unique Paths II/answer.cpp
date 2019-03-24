class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	long long dp[101][101] = { 0 };
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	for (int i = 1; i <= n; i++)
	{
		if (obstacleGrid[0][i-1] == 0)
			dp[1][i] = 1;
		else
			break;
	}
	for (int i = 1; i <= m; i++)
	{
		if (obstacleGrid[i-1][0] == 0)
			dp[i][1] = 1;
		else
			break;
	}
	for (int i = 2; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			if (obstacleGrid[i-1][j-1] == 0)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			else
				dp[i][j] = 0;
		}
	}
	return dp[m][n];
}
};
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
//Memory Usage: 9.3 MB, less than 45.38% of C++ online submissions for Unique Paths II.
//Next challenges:Unique Paths III
