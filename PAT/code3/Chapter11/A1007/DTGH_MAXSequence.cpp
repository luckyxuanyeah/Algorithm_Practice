#include "iostream"
#include "algorithm"
using namespace std;

const int MAX = 10010;
int num[MAX], start[MAX], dp[MAX];
int K;
int main()
{
	scanf("%d", &K);
	int count = 0;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] < 0)
			count++;
	}
	if (count == K)
		printf("0 %d %d", num[0], num[K - 1]);
	else
	{
		dp[0] = num[0];
		start[0] = 0;
		for (int i = 0; i < K; i++)
		{
			dp[i] = max(num[i], dp[i - 1] + num[i]);
			if (dp[i] == num[i])
				start[i] = i;
			else
				start[i] = start[i - 1];
		}
		int k = 0;
		int max = -100000;
		for (int i = 0; i < K; i++)
		{
			if (dp[i] > max)
			{
				k = i;
				max = dp[i];
			}
		}
		printf("%d %d %d", dp[k], num[start[k]], num[k]);
	}
	return 0;
}
