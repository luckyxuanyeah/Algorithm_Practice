vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		int j = i + 1, k = nums.size() - 1;
		while (j < k)
		{
			int sum = nums[i] + nums[j] + nums[k];
			if (sum == 0)
			{
				ans.push_back({ nums[i],nums[j],nums[k] });
				while (j < k && nums[j] == nums[j + 1])
					j++;
				while (j < k && nums[k] == nums[k - 1])
					k--;
				j++;
				k--;
			}
			else if (sum < 0)
				j++;
			else
				k--;
		}
	}
	return ans;
}
//Runtime: 100 ms, faster than 91.50% of C++ online submissions for 3Sum.
//Memory Usage: 14.9 MB, less than 97.90% of C++ online submissions for 3Sum.
//Next challenges:3Sum Closest  4Sum  3Sum Smaller
