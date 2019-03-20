class Solution {
public:
    
    int rob(vector<int>& nums) 
    {
        int dp1[10000]={0};
	    int dp2[10000]={0};
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
	dp1[0] = 0;
	dp1[1] = nums[0];
	dp2[1] = 0;
	dp2[2] = nums[1];
	for (int i = 2; i < nums.size(); i++)
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
	for (int i = 3; i <= nums.size(); i++)
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
	return max(dp1[nums.size() - 1], dp2[nums.size()]);
    }
};
//Runtime: 8 ms, faster than 19.58% of C++ online submissions for House Robber II.
//Memory Usage: 9.1 MB, less than 26.35% of C++ online submissions for House Robber II.
//Next challenges:Paint House  Paint Fence  House Robber III  Non-negative Integers without Consecutive Ones  Coin Path
