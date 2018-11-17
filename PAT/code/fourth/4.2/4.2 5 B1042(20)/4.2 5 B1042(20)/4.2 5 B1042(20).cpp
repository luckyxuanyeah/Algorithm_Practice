// 4.2 5 B1042(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
int main()
{
	char input[1001];
	gets_s(input);
	int len = strlen(input);
	int count[30] = {};
	for (int i = 0; i < len; i++)
	{
		if (input[i] >= 'A'&&input[i] <= 'Z')
			count[input[i] - 'A']++;
		else if (input[i] >= 'a'&&input[i] <= 'z')
			count[input[i] - 'a']++;
	}
	int max = 0, num = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < count[i])
		{
			max = count[i];
			num = i;
		}
	}
	printf("%c %d\n", num + 'a', max);
	return 0;
}

