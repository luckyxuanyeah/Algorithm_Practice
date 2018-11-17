// 3.2 7 A1036(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
struct Info{
	char name[11];
	char gender;
	char id[11];
	int grade;
}temp,high,low;

bool female_yes(Info a)
{
	if (a.gender == 'F') return  true;
	else return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	high.grade = 0, low.grade = 100;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %c%s%d", temp.name, &temp.gender, &temp.id, &temp.grade);
		if (female_yes(temp) == true)
		{
			if (temp.grade>high.grade)
				high = temp;
			count1++;
		}
		else
		{
			if (temp.grade < low.grade)
				low = temp;
			count2++;
		}
	}
	if (count1 == 0)
		printf("Absent\n");
	else
		printf("%s %s\n", high.name, high.id);
	if (count2==0)
		printf("Absent\n");
	else
		printf("%s %s\n", low.name, low.id);
	if (count1==0||count2==0)
		printf("NA\n");
	else
	{
		int sub = high.grade - low.grade;
		printf("%d\n", sub);
	}
	return 0;
}

