// 3.7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n;
	scanf("%d", &n);
	char a, b;
	int count1 = 0, count2 = 0, count3 = 0;
	int num[6] = {};
	while (n--)
	{
		getchar();
		scanf("%c %c", &a, &b);
		if (a == 'C'&& b == 'J')
		{
			count1++;
			num[0]++;
		}
		if (a == 'J'&&b == 'B')
		{
			count1++;
			num[1]++;
		}
		if (a == 'B'&&b == 'C')
		{
			count1++;
			num[2]++;
		}
		if (a == 'C'&&b == 'C')
			count3++;
		if (a == 'J'&&b == 'J')
			count3++;
		if (a == 'B'&&b == 'B')
			count3++;
		if (a == 'C'&&b == 'B')
		{
			count2++;
			num[3]++;
		}
		if (a == 'J'&&b == 'C')
		{
			count2++;
			num[4]++;
		}
		if (a == 'B'&&b == 'J')
		{
			count2++;
			num[5]++;
		}
	}
	printf("%d %d %d\n", count1, count3, count2);
	printf("%d %d %d\n", count2, count3, count1);
	if (num[0] >= num[1] && num[0] > num[2])
		printf("C ");
	if (num[1] > num[0] && num[1] > num[2])
		printf("J ");
	if (num[2] >= num[0] && num[2] >= num[1])
		printf("B ");
	if (num[3] >= num[4] && num[3] >= num[5])
		printf("B\n");
	if (num[4] > num[3] && num[4] >= num[5])
		printf("C\n");
	if (num[5] > num[3] && num[5] > num[4])
		printf("J\n");
	return 0;
}

