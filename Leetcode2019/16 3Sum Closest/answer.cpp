int threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	int ans = 0, sum = 0, temp = INT_MAX;
	for (int i = 0; i < nums.size() - 2; i++)
	{
		int j = i + 1, k = nums.size() - 1;
		while (j < k) 
		{
			sum = nums[i] + nums[j] + nums[k];
			if (temp > abs(sum - target))
			{
				temp = abs(sum - target);
				ans = sum;
			}
			if (sum > target)
				k--;
			else if (sum < target)
				j++;
            else if(sum==target)
                break;
		}
	}
	return ans;
}
//Runtime: 12 ms, faster than 63.17% of C++ online submissions for 3Sum Closest.
//Memory Usage: 8.9 MB, less than 98.33% of C++ online submissions for 3Sum Closest.
//Next challenges:3Sum Smaller
