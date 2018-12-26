#include "iostream"
#include "vector"
using namespace std;

int N, P, K;
const int MAXN = 410;
int maxSum = -1, Ap[MAXN];
vector<int> temp, ans;

int chengfang(int a)
{
	int cheng = 1, now = 0;
	while (now < P)
	{
		cheng = cheng*a;
		now++;
	}
	return cheng;
}
void DFS(int index, int nowK, int sum, int sumSqu)
{
	if (nowK == K && sum == N)
	{
		if (sumSqu > maxSum)
		{
			maxSum = sumSqu;
			ans = temp;
		}
		return;
	}
	if (nowK > K || sum > N)
		return;
	if (index - 1 >= 0)
	{
		temp.push_back(index);
		DFS(index, nowK + 1, sum + Ap[index], sumSqu + index);
		temp.pop_back();
		DFS(index - 1, nowK, sum, sumSqu);
	}
}
int main()
{
	scanf("%d%d%d", &N, &K, &P);
	int number = N;
	for (int i = 0; i < N + 1; i++)
		Ap[i] = chengfang(i);
	DFS(N, 0, 0, 0); 
	if (maxSum == -1)
		printf("Impossible");
	else
	{
		printf("%d = %d^%d", N, ans[0], P);
		for (int i = 1; i < ans.size();i++)
			printf(" + %d^%d", ans[i], P);
	}
	return 0;
}
