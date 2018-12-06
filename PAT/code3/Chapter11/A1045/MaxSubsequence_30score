#include "iostream"
#include "algorithm"
#include "map"
using namespace std;

const int MAX = 210;
const int INF = 10010;
int dp[INF], A[INF], favorite[MAX];
bool yes[MAX] = { false };
map<int, int> FtoA;
int main()
{
	int N, M, L;
	cin >> N;
	cin >> M;
	for (int i = M; i > 0; i--)
	{
		cin >> favorite[i];
		yes[favorite[i]] = true;
		FtoA[favorite[i]] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		if (yes[i] == false)
			FtoA[i] = 0;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> A[i];
		A[i] = FtoA[A[i]];
		dp[i] = 1;
	}
	int ans = -1;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dp[i]<dp[j] + 1 && A[i]<=A[j] &&A[i]!=0)
				dp[i] = dp[j] + 1;
		}
		if (ans < dp[i])
			ans = dp[i];
	}
	cout << ans;
	return 0;
}
