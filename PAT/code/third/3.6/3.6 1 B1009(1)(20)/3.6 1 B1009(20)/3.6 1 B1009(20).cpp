// 3.6 1 B1009(20).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	char a[81];
	char b[81][81] = {};
	int i = 0, k = 0, count = 0;
	while (scanf("%c", &a[i]) != EOF)//Ϊʲô��һ��ʼ�Ͱ��ַ�������!!!
		i++;
	for (int j = 0; j < i - 1; j++)
	{
		b[k][j - count] = a[j];
		if (a[j] == ' ')
		{
			count = j+1;
			k++;
		}
	}
	for (int j = k; j >=0; j++)
	{
		if (j == k)
		{
			printf("%s", b[j]);
			printf(" ");
		}
		else if (j == 0)
		{
			int m = 0;
			while (b[j][m] != ' ')
			{
				printf("%c", b[j][m]);
				m++;
			}
		}
		else
			printf("%s", b[j]);
	}
	return 0;
}

