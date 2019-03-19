class Solution {
public:
    const int maxn = 1000;

int minDistance(string word1, string word2) 
{
    int dp[maxn][maxn] = { 0 };
	int len1=word1.length();
	int len2 = word2.length();
	for (int i = 1; i <= len1; i++)//表示从第一个开始 不存在第0个开始转化的
		dp[i][0] = i;
	for (int j = 1; j <= len2; j++)
		dp[0][j] = j;
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			int number1 = dp[i - 1][j] + 1;
			int number2 = dp[i][j - 1] + 1;
			int number3;
			if (word1[i - 1] == word2[j - 1])
				number3 = dp[i - 1][j - 1];
			else
				number3 = dp[i - 1][j - 1] + 1;
			dp[i][j] = min(number3, (min(number1, number2)));
		}
	}
	return dp[len1][len2];
}
};
//Runtime: 1456 ms, faster than 5.09% of C++ online submissions for Edit Distance.
//Memory Usage: 12.8 MB, less than 5.22% of C++ online submissions for Edit Distance.
//Next challenges:One Edit Distance   Delete Operation for Two Strings   Minimum ASCII Delete Sum for Two Strings
