class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& ans, int target, int now, int& sum, vector<int>& temp)
{
	sum += candidates[now];
	temp.push_back(candidates[now]);
	if (sum > target)
	{
		sum -= candidates[now];
		temp.pop_back();
		return;
	}
	else if (sum == target)
	{
		if (find(ans.begin(), ans.end(), temp) == ans.end())
			ans.push_back(temp);
		sum -= candidates[now];
		temp.pop_back();
		return;
	}
	else if (sum < target)
	{
		for (int i = now; i < candidates.size(); i++)
			dfs(candidates, ans, target, i, sum, temp);
		sum -= candidates[now];
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> ans;
	int sum = 0;
	vector<int> temp;
	for(int i=0;i<candidates.size();i++)
		dfs(candidates, ans, target, i, sum, temp);
	return ans;
}

};
//Runtime: 20 ms, faster than 65.16% of C++ online submissions for Combination Sum.
//Memory Usage: 10.3 MB, less than 89.18% of C++ online submissions for Combination Sum.
//Next challenges:Letter Combinations of a Phone Number   Combination Sum II   Combination Sum III   Factor Combinations   Combination Sum IV
