#include "iostream"
using namespace std;
const int MAX = 31;
int n;
int num[MAX];
int F(int now)
{
	if (now == 0)
	{
		num[0] = 0;
		return 0;
	}
	if (now == 1)
	{
		num[1] = 1;
		return 1;
	}
	if (num[now] != -1)
		return num[now];
	else
	{
		num[now] = F(now - 1) + F(now - 2);
		return num[now];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		num[i] = -1;
	printf("%d", F(n));
	return 0;
}
