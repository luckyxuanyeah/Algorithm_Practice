// haha3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int main()
{
	int C1, C2;
	scanf("%d%d", &C1, &C2);
	int S = C2 - C1;
	double s;
	if (S % 100 != 0)
		s = round((double)S / 100);
	else
		s = (double)S /100;
	int hh, mm, ss;
	hh = (int)s / 3600;
	s =(int) s % 3600;
	mm = (int)s / 60;
	ss = (int)s % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
	system("pause");
	return 0;
}

