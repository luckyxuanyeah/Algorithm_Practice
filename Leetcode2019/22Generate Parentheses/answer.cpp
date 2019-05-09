void helper(vector<string>& ans,string temp,int open,int close,int maxx)
{
	if (open == maxx && close == maxx)
	{
		ans.push_back(temp);
		return;
	}
	if (open < maxx)
	{
		temp.append("(");
		helper(ans, temp, open + 1, close, maxx);
		temp.pop_back();
	}
	if (close < open)
	{
		temp.append(")");
		helper(ans, temp, open, close + 1, maxx);
		temp.pop_back();
	}
}

vector<string> generateParenthesis(int n) 
{
	vector<string> ans;
	string temp;
	helper(ans, temp, 0, 0, n);
	return ans;
}

//Runtime: 4 ms, faster than 99.87% of C++ online submissions for Generate Parentheses.
//Memory Usage: 18.4 MB, less than 14.69% of C++ online submissions for Generate Parentheses.
//Next challenges:Letter Combinations of a Phone Number
