#include "stdio.h"
#include "cstring"

const int MAX = 1010;
char S[MAX];
int dp[MAX][MAX];
int main()
{
	fgets(S, MAX, stdin);
	if (S[strlen(S) - 1] == '\n')
		S[strlen(S) - 1] = '\0';
	int L = strlen(S);
	int ans = 1;
	for (int i = 0; i < L; i++)
	{
		dp[i][i] = 1;
		if (i<L - 1)
		{
			if (S[i] == S[i + 1])
			{
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	for (int l = 3; l <= L; l++)
	{
		for (int i = 0; i < L; i++)
		{
			int j = i + l - 1;
			if (S[i] == S[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = 1;
				ans = l;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
