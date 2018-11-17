// 3.6 6 A1061(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

char day[7][5] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
char change[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
char time[24] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E',
'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N' };

bool english(char a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return true;
	else
		return false;
}
int main()
{
	char a[4][61];
	int num = 0, m = 0;;
	int len[4] = {};
	char count[61] = {};
	for (int i = 0; i < 4; i++)
	{
		scanf("%s", a[i]);
		len[i] = strlen(a[i]);
	}
	if (len[0]>len[1])
		len[0] = len[1];
	int g = len[0];
	for (int i = 0; i < len[0]; i++)
	{
		if (a[0][i]>=65 && a[0][i] <= 71)
		{
			if (a[0][i] == a[1][i])
			{
				count[m++] = a[1][i];
				g = i;
			}
		}
		else if ((a[0][i] >= 48 && a[0][i] <= 57) || (a[0][i] >= 65 && a[0][i]<=78))
		{
			if (a[0][i] == a[1][i] && g < i)
			{
				count[m++] = a[1][i];
				break;
			}
		}
	}
	int p = 0;
	for (int i = 0; i < len[2]; i++)
	{
		if (a[2][p] != a[3][p])
			p++;
		else if (english(a[2][p]) == false)
			p++;
		else break;
	}
	int la1 = 0, la2 = 0;
	for (int i = 0; i < 7; i++)
	{
		if (count[0] == change[i])
		{
			la1 = i;
			break;
		}
	}
	printf("%s ", day[la1]);
	for (int i = 0; i < 24; i++)
	{
		if (count[1] == time[i])
		{
			la2 = i;
			break;
		}
	}
	printf("%02d:%02d", la2, p);
	return 0;
}