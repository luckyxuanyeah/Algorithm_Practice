class Solution {
public:
   const int maxn = 1000000;

int maxSubArray(vector<int>& nums) 
{
    int maxx=INT_MIN;
	int dp[maxn] = { 0 };
	dp[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    for(int i=0;i<nums.size();i++)
    {
        if(maxx<dp[i])
            maxx=dp[i];
    }
	return maxx;
}
};
//Runtime: 268 ms, faster than 5.63% of C++ online submissions for Maximum Subarray.
//Memory Usage: 14.6 MB, less than 5.15% of C++ online submissions for Maximum Subarray.
//Next challenges:Best Time to Buy and Sell Stock   Maximum Product Subarray   Degree of an Array   Longest Turbulent Subarray
