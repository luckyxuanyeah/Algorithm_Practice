// 4.1 8 A1083(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
const int maxn = 10010;
struct Student{
	char name[11],id[11];
	int grade;
}stu[maxn];
bool cmp(Student a, Student b)
{
	return a.grade > b.grade;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);
	int grade1, grade2;
	scanf("%d%d", &grade1, &grade2);
	sort(stu, stu + n, cmp);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].grade >= grade1&&stu[i].grade <= grade2){
			printf("%s %s\n", stu[i].name, stu[i].id);
			count++;
		}
	}
	if (count == 0)
		printf("NONE\n");
	return 0;
}

