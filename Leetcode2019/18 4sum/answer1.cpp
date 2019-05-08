 vector<vector<int>> fourSum(vector<int> nums, int target)
{
	if (nums.size() < 4)
		return {};
	sort(nums.begin(), nums.end());
	vector<vector<int>> ans;
	for (int i = 0; i < nums.size() - 3; i++)
	{
		if (i != 0 && nums[i] == nums[i - 1])
			continue;
		if (target < (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]))
			break;
		if (target > (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3]))
			continue;
		for (int j = i + 1; j < nums.size() - 2; j++)
		{
			if (j != i + 1 && nums[j] == nums[j - 1])
				continue;
			if (target < (nums[i] + nums[j] + nums[j + 1] + nums[j + 2]))
				break;
			if (target > (nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2]))
				continue;
			int front = j + 1;
			int back = nums.size() - 1;
			int sum = target - nums[i] - nums[j];
			while(front<back)
			{
				if (nums[front] + nums[back] == sum)
				{
					ans.push_back({ nums[i],nums[j],nums[front],nums[back] });
					while ((front < back) && nums[front] == nums[front + 1])
						front++;
					while ((front < back) && nums[back] == nums[back - 1])
						back--;
					front++;
					back--;
				}
				else if (nums[front] + nums[back] > sum)
					back--;
				else
					front++;
			}
		}
	}
	return ans;
}
//Runtime: 8 ms, faster than 100.00% of C++ online submissions for 4Sum.
//Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for 4Sum.
//Next challenges:4Sum II
