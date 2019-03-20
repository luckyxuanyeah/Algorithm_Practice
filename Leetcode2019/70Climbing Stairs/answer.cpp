class Solution {
public:
    int climbStairs(int n) 
{
	int dp[10000];
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
//Memory Usage: 8.5 MB, less than 48.13% of C++ online submissions for Climbing Stairs.
//Next challenges:Min Cost Climbing Stairs   Fibonacci Number
