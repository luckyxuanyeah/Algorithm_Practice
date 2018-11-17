// 6.4 1 A1100(20).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "map"
#include "string"
using namespace std;
string unitDigt[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly",
"aug", "sep", "oct", "nov", "dec" };
string tenDigt[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy",
"lok", "mer", "jou" };
string numToStr[170];
map<string, int> strToNum;
void init()
{
	for (int i = 0; i < 13; i++)
	{
		numToStr[i] = unitDigt[i];
		strToNum[unitDigt[i]] = i;
		numToStr[i * 13] = tenDigt[i];
		strToNum[tenDigt[i]] = i * 13;
	}
	for (int i = 1; i < 13; i++)
	{
		for (int j = 1; j < 13; j++)
		{
			string str = tenDigt[i] + " " + unitDigt[j];
			numToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}
}
int main()
{
	init();
	int n;
	scanf("%d\n", &n);
	while (n--)
	{
		string temp;
		getline(cin, temp);
		if (temp[0] >= '0' && temp[0] <= '9')
		{
			int num = 0;
			for (int i = 0; i < temp.length(); i++)
				num = num * 10 + (temp[i] - '0');
			cout << numToStr[num] << endl;
		}
		else
			cout << strToNum[temp] << endl;
	}
	return 0;
}