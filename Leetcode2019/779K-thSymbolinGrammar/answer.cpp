class Solution {
public:
    int kthGrammar(int N, int K)
{
	int ans = 0;
	int position[35] = { 0 };
	int symbol[35];
	position[N] = K;
	for (int i = N-1; i > 0; i--)
		position[i] = (position[i + 1] + 1) / 2;
	symbol[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (position[i] % 2 == 0)//偶数
			symbol[i] = 1 - symbol[i - 1];
		else
			symbol[i] = symbol[i - 1];

	}
	ans = symbol[N];
	return ans;
}

};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for K-th Symbol in Grammar.
//Memory Usage: 8.5 MB, less than 64.00% of C++ online submissions for K-th Symbol in Grammar.
//Next challenges:Strobogrammatic Number III   Minimum Factorization   All Possible Full Binary Trees
