// 3.6 4 B1031(15).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

char Z[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
int pow[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
int main()
{
	int n;
	scanf("%d", &n);
	char a[102][19];
	int count[101] = {};
	int sum[101] = {};
	for (int i = 0; i < n; i++)
		scanf("%s", &a[i]);
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < 17; j++)
		{
			if (a[i][j]>'9' || a[i][j] < '0')
			{
				count[i]++;
				break;
			}
			sum[i] = sum[i] + (a[i][j] - '0') * pow[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (count[i] == 0)
		{
			if (i < n - 1)
			{
				if (Z[sum[i] % 11] != a[i][17])
					printf("%s\n", a[i]);
			}
			else
			{
				if (Z[sum[i] % 11] == a[i][17])
					printf("All passed\n");
				else
					printf("%s\n", a[i]);
			}
		}
		else if (count[i]!=0)
			printf("%s\n", a[i]);
	}
	return 0;
}

