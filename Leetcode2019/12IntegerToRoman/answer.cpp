// 12Integer to Roman.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	vector<int> a;
	while (num != 0)
	{
		a.push_back(num % 10);
		num = num / 10;
	}
	vector<char> output;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (i == 3)
		{
			if (a[i] <= 3)
			{
				for (int j = 0; j < a[i]; j++)
					output.push_back('M');
			}
		}
		else if (i == 2)
		{
			if (a[i] <= 3 && a[i] >= 1)
			{
				for (int j = 0; j < a[i]; j++)
					output.push_back('C');
			}
			else if (a[i] == 4)
			{
				output.push_back('C');
				output.push_back('D');
			}
			else if (a[i] == 5)
				output.push_back('D');
			else if (a[i] >= 6 && a[i] <= 8)
			{
				output.push_back('D');
				for (int j = 0; j < a[i]-5; j++)
					output.push_back('C');
			}
			else if (a[i] == 9)
			{
				output.push_back('C');
				output.push_back('M');
			}
		}
		else if (i == 1)
		{
			if (a[i] <= 3 && a[i] >= 1)
			{
				for (int j = 0; j < a[i]; j++)
					output.push_back('X');
			}
			else if (a[i] == 4)
			{
				output.push_back('X');
				output.push_back('L');
			}
			else if (a[i] == 5)
				output.push_back('L');
			else if (a[i] >= 6 && a[i] <= 8)
			{
				output.push_back('L');
				for (int j = 0; j < a[i]-5; j++)
					output.push_back('X');
			}
			else if (a[i] == 9)
			{
				output.push_back('X');
				output.push_back('C');
			}
		}
		else if (i == 0)
		{
			if (a[i] <= 3 && a[i] >= 1)
			{
				for (int j = 0; j < a[i]; j++)
					output.push_back('I');
			}
			else if (a[i] == 4)
			{
				output.push_back('I');
				output.push_back('V');
			}
			else if (a[i] == 5)
				output.push_back('V');
			else if (a[i] >= 6 && a[i] <= 8)
			{
				output.push_back('V');
				for (int j = 0; j < a[i]-5; j++)
					output.push_back('I');
			}
			else if (a[i] == 9)
			{
				output.push_back('I');
				output.push_back('X');
			}
		}
	}
	char ans[100000] = {'\0'};
	int number = 0;
	for (int i = 0; i < output.size(); i++)
		ans[number++] = output[i];
    ans[number]='\0';
	printf("%s", ans);
  return 0;
}
//Runtime: 52 ms, faster than 95.45% of C++ online submissions for Integer to Roman.
//Memory Usage: 32.4 MB, less than 40.86% of C++ online submissions for Integer to Roman.
//Next challenges:Roman to Integer
//Integer to English Words
