class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
{
	int dp[1001][1001] = { 0 };
	int m = grid.size();
	int n = grid[0].size();
	for (int i = 1; i <= m; i++)
		dp[i][1] = dp[i - 1][1] + grid[i - 1][0];
	for (int i = 1; i <= n; i++)
		dp[1][i] = dp[1][i - 1] + grid[0][i - 1];
	for (int i = 2; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1])+grid[i-1][j-1];
	}
	return dp[m][n];
}
};
//Runtime: 28 ms, faster than 10% of C++ online submissions for Minimum Path Sum.
//Memory Usage: 14.6 MB, less than 23.90% of C++ online submissions for Minimum Path Sum.
//Next challenges:Dungeon Game    Cherry Pickup
