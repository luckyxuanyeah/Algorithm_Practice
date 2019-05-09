bool isValid(string s)
{
	if (s.length() == 0)
		return true;
	map<char, char> mp;
	mp[')'] = '(';
	mp['}'] = '{';
	mp[']'] = '[';
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			st.push(s[i]);
		else
		{
			if (st.empty())
				return false;
			char temp = st.top();
			st.pop();
			if (temp != mp[s[i]])
				return false;
		}
	}
	return st.empty();
}
//Runtime: 4 ms, faster than 99.51% of C++ online submissions for Valid Parentheses.
//Memory Usage: 8.7 MB, less than 97.62% of C++ online submissions for Valid Parentheses.
//Next challenges:Generate Parentheses  Longest Valid Parentheses   Remove Invalid Parentheses  Check If Word Is Valid After Substitutions
