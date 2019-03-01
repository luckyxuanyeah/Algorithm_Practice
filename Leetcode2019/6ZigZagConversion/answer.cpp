// 6. ZigZag Conversion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "vector"
using namespace std;
const int maxn = 100000;
vector<char> ans[maxn];

int main()
{
	int numRows;
	char s[maxn] = {'\0'};
	scanf("%s%d", s, &numRows);
	char output[maxn] = {'\0'};
	int j = 0;
	int len = strlen(s);
	if (len == 1 || len == 0 || numRows == 1)
		strcpy(output, s);
	while (j < len) 
	{
		for (int number = 0; number < numRows * 2 - 2; number++)
		{
			if (number < numRows && s[j]!='\0')
				ans[number].push_back(s[j++]);
			else if (number >= numRows && s[j]!='\0')
				ans[2 * numRows - 2 - number].push_back(s[j++]);
		}
	}
	int count = 0;
	for (int i = 0; i < numRows; i++)
	{
		for (int n = 0; n < ans[i].size(); n++)
			output[count++] = ans[i][n];
	}
	printf("%s", output);
    return 0;
}
//Runtime: 96 ms, faster than 9.17% of C++ online submissions for ZigZag Conversion.
//Memory Usage: 20.9 MB, less than 22.06% of C++ online submissions for ZigZag Conversion.
//Next challenges:Integer to Roman    Masking Personal Information    Score of Parentheses
