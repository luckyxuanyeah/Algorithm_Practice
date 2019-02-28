#include "iostream"
#include "string"
using namespace std;
int dp[1010][1010];
int main()
{
	char s[1010];
	scanf("%s", s);
	int len = strlen(s);
	//.length();
	//int dp[1010][1010] = { 0 };
	memset(dp, 0, sizeof(dp));
	int ans = 1;
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = 1;
		if (i < len - 1) 
		{
			if (s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	for (int l = 3; l <= len; l++)
	{
		for (int i = 0; i + l - 1 < len; i++)
		{
			int j = i + l - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = 1;
				ans = l;
			}
		}
	}
	char output[1010] = {'\0'};
	for (int i = 0; i<len; i++)
	{
		if (dp[i][i + ans-1] == 1)
		{
			for (int j = 0; j<ans; j++)
				output[j] = s[i++];
			break;
		}
	}
	printf("%s", output);
	return 0;
}

//Runtime: 100 ms, faster than 53.49% of C++ online submissions for Longest Palindromic Substring.
//Memory Usage: 13.3 MB, less than 52.70% of C++ online submissions for Longest Palindromic Substring.
//Next challenges:
//Shortest Palindrome   Palindrome Permutation   Palindrome Pairs    Longest Palindromic Subsequence
//Palindromic Substrings
