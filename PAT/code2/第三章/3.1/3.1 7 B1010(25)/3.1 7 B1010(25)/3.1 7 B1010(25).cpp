// 3.1 7 B1010(25).cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "stdio.h"
const int maxn = 1010;
int main()
{
	int a[maxn] = { 0 };
	int k, e, count = 0;
	while (scanf("%d%d", &k, &e) != EOF)//������ر�֮��ע�⣡
		a[e] = k;
	for (int i = 0; i <=1000; i++)//ע��һ��i�����ֵ��
	{
		a[i - 1] = a[i] * i;
		a[i] = 0;
		if (a[i - 1] != 0)
			count++;
	}
	if (count == 0)
		printf("0 0\n");//�ر��жϵ���Ϊ�����ʽʱ
	else
	{
		for (int i = 1000; i >= 0; i--)
		{
			if (a[i] != 0)
			{
				printf("%d %d", a[i], i);
				count--;
				if (count > 0) printf(" ");
			}
		}
	}
	return 0;
}
