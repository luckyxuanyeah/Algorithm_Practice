// 3.4 example.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int month[13][2] = {
	{ 0, 0 }, { 31, 31 }, { 29, 28 }, { 31, 31 }, { 30, 30 }, { 31, 31 }, { 30, 30 }, { 31, 31 }, { 31, 31 },
	{ 30, 30 }, { 31, 31 }, { 30, 30 }, { 31, 31 }
};

bool leap(int a)
{
	return ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0);
}

int main()
{
	int day1, day2, temp, y1=0, y2=0, m1=0, m2=0, d1=0, d2=0;
	scanf("%d", &day1);
	scanf("%d", &day2);
	if (day1 > day2)
	{
		temp = day1;
		day1 = day2;
		day2 = temp;
	}
	y1 = day1 / 10000, y2 = day2 / 10000;
	m1 = day1 % 10000 / 100, m2 = day2 % 10000 / 100;
	d1 = day1 % 100, d2 = day2 % 100;
	int count = 0;
	while (y1 < y2 || m1 < m2 || d1 < d2)
	{
		d1++;
		if (month[m1][leap(y1)] < d1)
		{
			m1++;
			d1 = 1;
		}
		if (m1 == 13)
		{
			y1++;
			m1 = 1;
		}
		count++;
	}
	printf("%d\n", count + 1);
	return 0;
}

