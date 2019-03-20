class Solution {
public:
    int rob(vector<int>& nums) {
	int dp[10000] = { 0 };
	dp[0] = 0;
	if (nums.size() == 0)
		return 0;
	dp[1] = nums[0];
	for (int i = 2; i <= nums.size(); i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	return dp[nums.size()];
    }
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for House Robber.
//Memory Usage: 9.1 MB, less than 17.29% of C++ online submissions for House Robber.
//Next challenges:Maximum Product Subarray  House Robber II  Paint House  Paint Fence  House Robber III  Non-negative Integers without Consecutive Ones  Coin Path  Delete and Earn
