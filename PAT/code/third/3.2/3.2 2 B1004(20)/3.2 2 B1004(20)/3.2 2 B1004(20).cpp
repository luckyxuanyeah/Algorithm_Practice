// 3.2 2 B1004(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
const int max = 100010;
struct Student{
	char name[11];
	char id[11];
	int score;
}Student[max];

int main()
{
	int n, k = 0, p = 0;
	int maxinum = -1,min=101;
	scanf("%d", &n);		
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%d",Student[i].name, Student[i].id, &Student[i].score);
		if (maxinum < Student[i].score)
		{
			maxinum = Student[i].score;
			k = i;
		}
		if (min>Student[i].score)
		{
			min = Student[i].score;
			p = i;
		}
	}
	printf("%s %s\n",Student[k].name, Student[k].id);
	printf("%s %s\n",Student[p].name, Student[p].id);
	return 0;
}

