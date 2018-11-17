// 3.6 11 A1035(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "memory.h"

int main()
{
	int n;
	scanf("%d", &n);
	char name[1010][11], password[1010][11];
	int len[1010] = {};
	bool change[1010];
	int count = 0;
	memset(change, false, sizeof(change));
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", name[i], password[i]);
		len[i] = strlen(password[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < len[i]; j++){
			if (password[i][j] == '1')
			{
				change[i] = true;
				password[i][j] = '@';
			}
			else if (password[i][j] == '0')
			{
				change[i] = true;
				password[i][j] = '%';
			}
			else if (password[i][j] == 'l')
			{
				change[i] = true;
				password[i][j] = 'L';
			}
			else if (password[i][j] == 'O')
			{
				change[i] = true;
				password[i][j] = 'o';
			}
		}
		if (change[i] == true)
			count++;
	}
	if (count != 0){
		printf("%d\n", count);
		for (int i = 0; i < n; i++)
		{
			if (change[i] == true)
				printf("%s %s\n", name[i], password[i]);
		}
	}
	else if (count == 0)
	{
		if (n>1)
			printf("There are %d accounts and no account is modified\n", n);
		else if (n = 1)
			printf("There is 1 account and no account is modified\n");
	}
	return 0;
}

