// 3.11 B1010(25).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int a[1010] = {};
	int b, k, max = 0, count = 0;
	while (scanf("%d%d", &k, &b) != EOF)
	{
		a[b] = k;
		if (max < b)
			max = b;
	}
	for (int i = max; i >= 0; i--)
	{
		a[i] = i*a[i];
		if (a[i] != 0)
			count++;
	}
	if (count ==0)//��������û�з���ֵ�������0 0
			printf("0 0");
	else
	{
		for (int i = max; i >= 0; i--)
		{

			if (a[i] != 0)//ö�� ����Ϊ������
			{
				printf("%d %d", a[i], i - 1);
				count--;
				if (count != 0)
					printf(" ");//���ո�������������
			}
		}
	}
	return 0;
}

