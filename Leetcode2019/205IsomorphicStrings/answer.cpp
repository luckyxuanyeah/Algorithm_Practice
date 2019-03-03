class Solution {
public:
    bool isIsomorphic(string s, string t) {
	int len1 = s.length(), len2 = t.length();
	if (len1 != len2)
		return false;
	else 
	{
		for (int i = 0; i < len1; i++)
		{
			for (int j = i+1; j < len1; j++)
			{
				if ((s[i] == s[j] && t[i] != t[j]) || (s[i] != s[j] && t[i] == t[j]))
				{
					return false;
				}
			}
		}
		
	}
        return true;
    }
};

//Runtime: 2556 ms, faster than 6.64% of C++ online submissions for Isomorphic Strings.
//Memory Usage: 8.9 MB, less than 65.79% of C++ online submissions for Isomorphic Strings.
//Next challenges: Word Pattern


class Solution {
public:
    bool isIsomorphic(string s, string t) {
	int len1 = s.length(), len2 = t.length();
	bool ans = true;
	map<char, char> mp1, mp2;
	if (len1 != len2)
		ans = false;
	else
	{
		for (int i = 0; i < len1; i++)
		{
			if (mp1.find(s[i]) == mp1.end())
				mp1[s[i]] = t[i];
			else
			{
				if (mp1[s[i]] != t[i])
					ans = false;
			}
		}
		for (int i = 0; i < len2; i++)
		{
			if (mp2.find(t[i]) == mp2.end())
				mp2[t[i]] = s[i];
			else
			{
				if (mp2[t[i]] != s[i])
					ans = false;
			}
		}
		
	}
        return ans;
    }
};


//Runtime: 28 ms, faster than 6.64% of C++ online submissions for Isomorphic Strings.
