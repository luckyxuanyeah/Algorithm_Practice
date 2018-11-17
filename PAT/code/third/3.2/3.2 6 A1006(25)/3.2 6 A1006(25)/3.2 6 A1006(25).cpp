// 3.2 6 A1006(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

struct person{
	char ID_number[20];
	int hh_in, mm_in, ss_in;
	int hh_out, mm_out, ss_out;
}temp, early, late;

bool earlyer(person a, person b)
{
	if (a.hh_in != b.hh_in) return a.hh_in < b.hh_in;
	else if (a.mm_in != b.mm_in) return a.mm_in < b.mm_in;
	else return a.ss_in <= b.ss_in;
}
bool later(person a, person b)
{
	if (a.hh_out != b.hh_out) return a.hh_out > b.hh_out;
	else if (a.mm_out != b.mm_out) return a.mm_out > b.mm_out;
	else return a.ss_out >= b.ss_out;
}

int main()
{
	int m;
	scanf("%d", &m);
	early.hh_in = 23, early.mm_in = 59, early.ss_in = 59;
	late.hh_out = 0, late.mm_out = 0, late.ss_out = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%s%d:%d:%d", temp.ID_number, &temp.hh_in, &temp.mm_in, &temp.ss_in);
		scanf("%d:%d:%d",&temp.hh_out, &temp.mm_out, &temp.ss_out);//不能连着读入两个签到和签退时间
		if (earlyer(temp, early) == true)
			early = temp;
		if (later(temp, late) == true)
			late = temp;
	}		
	printf("%s %s\n", early.ID_number, late.ID_number);
	return 0;
}

