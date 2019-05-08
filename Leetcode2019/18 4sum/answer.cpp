vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> ans;
	unordered_map<int, vector<vector<int>>> mp;
	set<string> st;
	sort(nums.begin(), nums.end());
	if (nums.size() < 4)
		return ans;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			int sum = nums[i] + nums[j];
			mp[sum].push_back({ i, j });
		}
	}
	for (int i = 0; i < nums.size()-1; i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (mp.count(target - nums[i] - nums[j]) != 0)
			{
				vector<vector<int>> temp = mp[target - nums[i] - nums[j]];
				for (int k = 0; k < temp.size(); k++)
				{
					if (temp[k][0] == i || temp[k][1] == i || temp[k][0] == j || temp[k][1] == j)
						continue;
					else
					{
						vector<int> ak = { nums[i],nums[j],nums[temp[k][0]],nums[temp[k][1]] };
						sort(ak.begin(), ak.end());
						string str;
						for (int z = 0; z < ak.size(); z++)
							str += to_string(ak[z]);
						if (st.find(str) == st.end())
						{
							st.insert(str);
							ans.push_back({ nums[i],nums[j],nums[temp[k][0]],nums[temp[k][1]] });
						}
					}
				}
			}
		}
	}
	return ans;
}
//Runtime: 160 ms, faster than 9.93% of C++ online submissions for 4Sum.
//Memory Usage: 49.2 MB, less than 5.21% of C++ online submissions for 4Sum.
//Next challenges:4Sum II
