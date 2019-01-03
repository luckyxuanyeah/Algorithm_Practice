#include "iostream"
#include "string.h"
#include "queue"
using namespace std;
int t;
typedef long long ll;
int yu[250];
const ll mod = 233;
struct data
{
	ll x;
	ll ci;
};
ll F(ll x)
{
	x %= mod;
	return (x*x*x + x*x) % mod;
}
ll G(ll x)
{
	x %= mod;
	return (x*x*x - x*x) % mod;
}
ll bfs(ll x, ll y)
{
	queue<data> q;
	data t;
	t.ci = 0, t.x = x;
	q.push(t);
	while (!q.empty())
	{
		data now = q.front();
		q.pop();
		if (now.x == y)
			return now.ci;
		data next;
		next.ci = now.ci + 1;
		next.x = F(now.x);
		if (yu[next.x] == 0)
		{
			yu[next.x]++;
			q.push(next);
		}
		next.x = G(now.x);
		if (yu[next.x] == 0)
		{
			yu[next.x]++;
			q.push(next);
		}
	}
	return -1;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(yu, 0, sizeof(yu));
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if (a == b)
			printf("0\n");
		else if (b >= mod)
			printf("-1\n");
		else
			printf("%lld\n", bfs(a, b));
	}
	return 0;
}
