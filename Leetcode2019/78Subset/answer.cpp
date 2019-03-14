class Solution {
public:
    
void help(int start, vector<int>& tmp, vector<vector<int>>& ans,vector<int>& nums)
{
	if (find(ans.begin(), ans.end(), tmp) == ans.end())
		ans.push_back(tmp);
	for (int i = start; i < nums.size(); i++)
	{
		tmp.push_back(nums[i]);
		help(i + 1, tmp, ans,nums);
		tmp.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> tmp;
	help(0, tmp, ans,nums);
	return ans;
}
};
//Runtime: 12 ms, faster than 35.75% of C++ online submissions for Subsets.
//Memory Usage: 9.2 MB, less than 52.03% of C++ online submissions for Subsets.
//Next challenges:Subsets II   Generalized Abbreviation   Letter Case Permutation
