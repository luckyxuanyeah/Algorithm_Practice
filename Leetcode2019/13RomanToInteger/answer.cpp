// 13Roman to Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	char s[100000];
	scanf("%s", s);
	int len = strlen(s);
	int ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'M')
		{
			if (s[i - 1] == 'C')
				ans += 900;
			else
				ans = ans + 1000;
		}
		else if (s[i] == 'C')
		{
			if (s[i + 1] == 'M')
				continue;
			else if (s[i + 1] == 'D')
				continue;
			else if (s[i - 1] == 'X')
				ans += 90;
			else
				ans += 100;
		}
		else if (s[i] == 'D')
		{
			if (s[i - 1] == 'C')
				ans += 400;
			else
				ans += 500;
		}
		else if (s[i] == 'X')
		{
			if (s[i + 1] == 'C')
				continue;
			else if (s[i + 1] == 'L')
				continue;
			else if (s[i - 1] == 'I')
				ans += 9;
			else
				ans += 10;
		}
		else if (s[i] == 'L')
		{
			if (s[i - 1] == 'X')
				ans += 40;
			else
				ans += 50;
		}
		else if (s[i] == 'V')
		{
			if (s[i - 1] == 'I')
				ans += 4;
			else
				ans += 5;
		}
		else if (s[i] == 'I')
		{
			if (s[i + 1] == 'V')
				continue;
			else if (s[i + 1] == 'X')
				continue;
			else
				ans += 1;
		}
			
	}
	printf("%d", ans);
	return 0;
}
//Runtime: 48 ms, faster than 97.18% of C++ online submissions for Roman to Integer.
//Memory Usage: 31 MB, less than 67.44% of C++ online submissions for Roman to Integer.
//Next challenges:Sort Transformed Array    Groups of Special-Equivalent Strings     K Closest Points to Origin
