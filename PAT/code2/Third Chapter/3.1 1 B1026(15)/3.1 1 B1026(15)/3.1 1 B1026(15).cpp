// 3.1 1 B1026(15).cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
const int CLK_TCK = 100;
int main()
{
	int c1, c2, c;
	scanf("%d%d", &c1, &c2);
	/*����д��������*/
	(int)c = round((double)(c2 - c1) / CLK_TCK);

	/*if ((c2 - c1) % 100 >= 50)
		c = c / 100 + 1;
	else
		c = c / 100;
	*/
	//1.02������ 2.��������û�п��Ǻ� ����math.h��round
	printf("%02d:%02d:%02d\n", c / 3600, c % 3600 / 60, c % 3600 % 60); 
	return 0;
}
