class Solution {
public:
   void dfs(vector<vector<int>>& ans, vector<int>& temp, int& sum, int& now, vector<int>& candidates, int target)
{
	++now;
	if (now < candidates.size())
	{
		sum += candidates[now];
		temp.push_back(candidates[now]);
	}
	else 
	{
		return;
	}
	if (sum > target)
	{
		sum -= candidates[now];
		now--;
		temp.pop_back();
		return;
	}
	else if (sum == target)
	{
		if (find(ans.begin(), ans.end(), temp) == ans.end())
			ans.push_back(temp);
		sum -= candidates[now];
		now--;
		temp.pop_back();
		return;
	}
	else if (sum < target)
	{
		for(int i=now;i<candidates.size();i++)
			dfs(ans, temp, sum, i, candidates, target);
		sum -= candidates[now];
		now--;
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
	vector<vector<int>> ans;
	int sum = 0;
	vector<int> temp;
	sort(candidates.begin(), candidates.end());
	for (int i = 0; i < candidates.size(); i++) 
	{
		int now = i - 1;
		dfs(ans, temp, sum, now, candidates, target);
	}
	return ans;
}
};

//Runtime: 24 ms, faster than 28.88% of C++ online submissions for Combination Sum II.
//Memory Usage: 10.1 MB, less than 62.71% of C++ online submissions for Combination Sum II.
//Next challenges:Maximum Average Subarray II  Flipping an Image  Magic Squares In Grid
