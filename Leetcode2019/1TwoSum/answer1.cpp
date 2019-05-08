vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> ans;
	map<int, int> mp;
	for (int i = 0; i < nums.size(); i++)
	{
		if (mp.count(nums[i]) == 0)
			mp[nums[i]] = 1;
		else
			mp[nums[i]]++;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		int temp = target - nums[i];
		mp[nums[i]]--;
		ans.push_back(i);
		if (mp.count(temp) != 0 && mp[temp]!=0)
		{
			vector<int>::iterator it = find(nums.begin(), nums.end(), temp);
			if (*it == nums[ans[0]])
				it = find(it + 1, nums.end(), temp);
			int pos = distance(nums.begin(), it);
			ans.push_back(pos);
			break;
		}
		else
		{
			ans.pop_back();
			mp[nums[i]]++;
		}
	}
	return ans;
}

//
