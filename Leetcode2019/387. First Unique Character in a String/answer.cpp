int firstUniqChar(string s)
{
	unordered_map<char,int> mp;
	for (int i = 0; i < s.length(); i++)
	{
		if (mp.find(s[i]) == mp.end())
			mp[s[i]] = 0;
		mp[s[i]]++;
	}
	int index = -1;
	for (int i = 0; i < s.length(); i++)
	{
		if (mp[s[i]] == 1)
		{
			index = i;
			break;
		}
	}
	return index;
}
//Runtime: 72 ms, faster than 32.17% of C++ online submissions for First Unique Character in a String.
//Memory Usage: 13.2 MB, less than 96.65% of C++ online submissions for First Unique Character in a String.
//Next challenges:Sort Characters By Frequency
