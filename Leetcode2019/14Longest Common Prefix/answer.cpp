class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int number = strs.size();
	string temp;
	if (number <= 0)
		return "";
	temp = strs[0];
	for (int i = 1; i < number; i++)
	{
		int j = 0;
		while (temp[j] != '\0' && strs[i][j] != '\0' && strs[i][j] == temp[j])
			j++;
		temp[j] = '\0';
	}
	return temp; 
    }
};
//Runtime: 8 ms, faster than 98.83% of C++ online submissions for Longest Common Prefix.
//Memory Usage: 8.9 MB, less than 99.27% of C++ online submissions for Longest Common Prefix.
//Next challenges:Repeated Substring Pattern  Design Log Storage System   Split Array into Fibonacci Sequence
