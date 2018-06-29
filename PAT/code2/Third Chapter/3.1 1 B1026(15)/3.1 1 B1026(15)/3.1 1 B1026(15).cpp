// 3.1 1 B1026(15).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
const int CLK_TCK = 100;
int main()
{
	int c1, c2, c;
	scanf("%d%d", &c1, &c2);
	/*这样写会编译错误*/
	(int)c = round((double)(c2 - c1) / CLK_TCK);

	/*if ((c2 - c1) % 100 >= 50)
		c = c / 100 + 1;
	else
		c = c / 100;
	*/
	//1.02忘记了 2.四舍五入没有考虑好 用了math.h的round
	printf("%02d:%02d:%02d\n", c / 3600, c % 3600 / 60, c % 3600 % 60); 
	return 0;
}
