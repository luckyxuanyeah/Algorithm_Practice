// 3.2 3 B1028(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
const int max = 10010;
struct Info{
	char name[10];
	int yy, mm, dd;
}temp,old,young,left,right;

bool older(Info a,Info b )
{
	if (a.yy != b.yy) return a.yy <= b.yy;
	else if (a.mm != b.mm) return a.mm <= b.mm;
	else return a.dd <= b.dd;
}

bool younger(Info a, Info b)
{
	if (a.yy != b.yy) return a.yy >= b.yy;
	else if (a.mm != b.mm) return a.mm >= b.mm;
	else return a.dd >= b.dd;
}

int main()
{
	int n;
	scanf("%d", &n);
	bool in1, in2;
	int count = 0;
	old.yy = right.yy = 2014;
	old.mm = right.mm = 9;
	old.dd = right.dd = 6;
	young.yy = left.yy = 1814;
	young.mm = left.mm = 9;
	young.dd = left.dd = 6;
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
		in1 = older(temp, right);
		in2 = younger(temp,left);
		if (in1 == true && in2 == true)
		{
			count++;
			if (older(temp, old))
				old = temp;
			if (younger(temp, young))
				young = temp;
		}
	}
	if (count == 0)
		printf("0");
	else
		printf("%d %s %s\n", count, old.name, young.name);
	return 0;
}

