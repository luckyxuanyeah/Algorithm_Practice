// 4.2 6 B1043(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

char change[6] = { 'P', 'A', 'T', 'e', 's', 't' };
int main()
{
	char str[10010];
	gets_s(str);
	int len = strlen(str);
	int count[6] = {};
	for (int i = 0; i < len+1; i++)
	{
		if (str[i] == 'P')
			count[0]++;
		else if (str[i] == 'A')
			count[1]++;
		else if (str[i] == 'T')
			count[2]++;
		else if (str[i] == 'e')
			count[3]++;
		else if (str[i] == 's')
			count[4]++;
		else if (str[i] == 't')
			count[5]++;
	}
	for (int i = 0; i <100010; i++)
	{
		if (count[i % 6] > 0){
			printf("%c", change[i % 6]);
			count[i % 6]--;
		}
	}
	return 0;
}

