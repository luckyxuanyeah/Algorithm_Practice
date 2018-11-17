// 4.1 5 A1028(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;

const int maxn = 100010;
struct Info{
	int id;
	char name[9];
	int grade;
}stu[maxn];
bool cmp1(Info a,Info b)
{
	return a.id < b.id;
}
bool cmp2(Info a, Info b)
{
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name, b.name) < 0;
	else return a.id < b.id;
}
bool cmp3(Info a, Info b)
{
	if(a.grade!=b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}
int main()
{
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].grade);
	if (c == 1) sort(stu, stu + n, cmp1);
	else if (c == 2) sort(stu, stu + n, cmp2);
	else if (c == 3) sort(stu, stu + n, cmp3);
	for (int i = 0; i < n; i++)
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	return 0;
}

