// 3.6 11 A1035(2)(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

struct node{
	char name[20], password[20];
	bool ischange;
}T[1005];

void crypt(node& t, int& cnt)
{
	int len = strlen(t.password);
	for (int i = 0; i < len; i++)
	{
		if (t.password[i] == '1')
		{
			t.password[i] = '@';
			t.ischange = true;
		}
		else if (t.password[i] == '0')
		{
			t.ischange = true;
			t.password[i] = '%';
		}
		else if (t.password[i] == 'l')
		{
			t.ischange = true;
			t.password[i] = 'L';
		}
		else if (t.password[i] == 'O')
		{
			t.ischange = true;
			t.password[i] = 'o';
		}
	}
	if (t.ischange)
		cnt++;
}

int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", T[i].name, T[i].password);
		T[i].ischange = false;
	}
	for (int i = 0; i < n; i++)
		crypt(T[i], cnt);
	if (cnt == 0)
	{
		if (n == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified", n);
	}
	else
	{
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++)
		{
			if (T[i].ischange)
				printf("%s %s\n", T[i].name, T[i].password);
		}
	}
	return 0;
}

