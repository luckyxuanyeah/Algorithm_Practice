#include "iostream"
#include "string"
#include "vector"
using namespace std;
using ll = long long int;
ll A, B;
ll L1, L2, R1, R2;
string Li, Ri, Lj, Rj;
ll minn, maxx;
vector<int> Ax;

ll change(string s, int base)
{
	ll ans = 0, cnt = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		ans += (s[i] - '0')*cnt;
		cnt *= base;
	}
	return ans;
}
ll exchange(vector<int> v, int base)
{
	ll ans = 0, cnt = 1;
	for (int i = 0; i < v.size(); i++)
	{
		ans += v[i] * cnt;
		cnt *= base;
	}
	return ans;
}
bool judge(ll l, ll r)
{
	ll li = 0, ri = 0;
	Ax.clear();
	while (l)
	{
		Ax.push_back(l%A);
		l /= A;
	}
	li = exchange(Ax, B);
	Ax.clear();
	while (r)
	{
		Ax.push_back(r%A);
		r /= A;
	}
	ri = exchange(Ax, B);//将小进制下的数转化成大进制下的数！！！
	return li <= R2 && ri >= L2;
}
bool check1(ll x)
{
	ll y = 0;
	Ax.clear();
	while (x)
	{
		Ax.push_back(x%A);
		x /= A;
	}
	y = exchange(Ax, B);
	if (y <= R2)
		return true;
	return false;
}
bool check2(ll x)
{
	ll y = 0;
	Ax.clear();
	while (x)
	{
		Ax.push_back(x%A);
		x /= A;
	}
	y = exchange(Ax, B);
	if (y >= L2)
		return true;
	return false;
}
void bs()
{
	ll l = L1, r = R1;
	while (l < r)
	{
		ll mid = (l + r + 1) / 2;
		if (check1(mid))
			l = mid;
		else
			r = mid - 1;
	}
	maxx = l;
	l = L1, r = maxx;
	while (l < r)
	{
		ll mid = (l + r) / 2;
		if (check2(mid))
			r = mid;
		else
			l = mid + 1;
	}
	minn = r;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> A >> B >> Li >> Ri >> Lj >> Rj;
		L1 = change(Li, A);
		L2 = change(Lj, B);
		R1 = change(Ri, A);
		R2 = change(Rj, B);
		if (A > B)
		{
			swap(A, B);
			swap(L1, L2);
			swap(R1, R2);
		}
		if (!judge(L1, R1))
		{
			printf("0\n");
			continue;
		}
		bs();
		cout << maxx - minn + 1 << endl;
	}
	return 0;
}
