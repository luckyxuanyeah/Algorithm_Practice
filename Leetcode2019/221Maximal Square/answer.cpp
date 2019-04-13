class Solution {
public:

int maximalSquare(vector<vector<char>>& matrix)
{
    if (matrix.size() == 0)
		return 0;
	int x = matrix.size();
	int y = matrix[0].size();
	vector<vector<int>> dp(x,vector<int>(y));
	int max = 0;
	for (int i = 0; i < y; i++)
    {
        dp[0][i] = matrix[0][i] - 48;
        if(max<dp[0][i])
            max=dp[0][i];
    }
	for (int j = 0; j < x; j++)
    {
        dp[j][0] = matrix[j][0] - 48;
        if(max<dp[j][0])
            max=dp[j][0];
    }
	for (int i = 1; i < x; i++)
	{
		for (int j = 1; j < y; j++)
		{
			if (matrix[i][j] == '1')
			{
				if (dp[i][j - 1] > 0 && dp[i - 1][j] > 0 && dp[i - 1][j - 1] > 0)
				{
					dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
					if (max < dp[i][j])
						max = dp[i][j];
				}
				else
					dp[i][j] = matrix[i][j] - 48;
			}
			else
				dp[i][j] = matrix[i][j] - 48;
		}
	}
	return max*max;
}
};
//Runtime: 24 ms, faster than 59.76% of C++ online submissions for Maximal Square.
//Memory Usage: 11.2 MB, less than 65.58% of C++ online submissions for Maximal Square.
//Next challenges:Maximal Rectangle  Largest Plus Sign
