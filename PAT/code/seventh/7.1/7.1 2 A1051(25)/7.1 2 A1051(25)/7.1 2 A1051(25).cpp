// 7.1 2 A1051(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "stack"
using namespace std;
const int maxn = 1010;
int array[maxn];
stack<int> s;
int main()
{
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	while (k--)
	{
		while (!s.empty())
			s.pop();
		for (int i = 1; i <= n; i++)
			scanf("%d", &array[i]);
		int count = 1;
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			s.push(i);
			if (s.size() > m)
			{
				flag = false;
				break;
			}
			while (!s.empty() && s.top() == array[count])
			{
				s.pop();
				count++;
			}
		}
		if (s.empty()==true && flag==true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}