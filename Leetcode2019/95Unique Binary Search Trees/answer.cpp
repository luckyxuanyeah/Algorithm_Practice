// 96Unique Binary Search Trees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "vector"
using namespace std;
const int maxn = 100000000;
int numTrees(int n)
{
	int dp[maxn];
	if (n <= 0)
		return 0;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - j - 1];
	}
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << numTrees(n) << endl;
    return 0; 
}
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
//Memory Usage: 8.9 MB, less than 5.38% of C++ online submissions for Unique Binary Search Trees.
//Next challenges:Unique Binary Search Trees II
