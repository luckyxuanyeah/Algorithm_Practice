// 3.6 3 B1021(15).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char n[1010];
	int i = 0;
	int count[10] = {};
	gets_s(n);
	int len = strlen(n);
	for (int j = 0; j < len; j++)
	{
		if (n[j] == '0')
			count[0]++;
		else if (n[j] == '1')
			count[1]++;
		else if (n[j] == '2')
			count[2]++;
		else if (n[j] == '3')
			count[3]++;
		else if (n[j] == '4')
			count[4]++;
		else if (n[j] == '5')
			count[5]++;
		else if (n[j] == '6')
			count[6]++;
		else if (n[j] == '7')
			count[7]++;
		else if (n[j] == '8')
			count[8]++;
		else if (n[j] == '9')
			count[9]++;
	}
	for (int m = 0; m < 10; m++)
	{
		if (count[m] != 0)
			printf("%d:%d\n", m, count[m]);
	}
	return 0;
}

