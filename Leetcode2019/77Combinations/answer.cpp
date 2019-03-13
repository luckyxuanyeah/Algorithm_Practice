class Solution {
public:
    void help(int n, int k, int start, vector<vector<int>>& ans, vector<int>& temp)
{
	if (temp.size() == k)
	{
		ans.push_back(temp);
		return;
	}
	for (int i = start; i <= n; i++)
	{
		temp.push_back(i);
		help(n, k, i + 1, ans, temp);
		temp.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) 
{
	vector<vector<int>> ans;
	vector<int> temp;
	help(n, k, 1, ans, temp);//1 2 3; 1 2 4
	return ans;
}
};
//Runtime: 84 ms, faster than 82.52% of C++ online submissions for Combinations.
//Memory Usage: 11.9 MB, less than 64.77% of C++ online submissions for Combinations.
//Next challenges:Combination Sum   Permutations
