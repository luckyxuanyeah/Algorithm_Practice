// 4.2 2 B1033(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
const int maxn = 100010;
char str[maxn];
bool hash[256];

int main()
{
	memset(hash, true, sizeof(hash));
	gets_s(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		hash[str[i]] = false;
	}
	gets_s(str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			int low = str[i] - 'A' + 'a';
			if (hash['+'] == true && hash[low] == true)
				printf("%c", str[i]);
		}
		else if (hash[str[i]] == true)
			printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}

