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
