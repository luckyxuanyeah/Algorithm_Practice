// 3.2 example.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"

int main()
{ 
	int n,x;
	int a[203];
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &x);
		int k = 0;
		for (int j = 0; j < n; j++) //��ѯ����
		{
			if (a[j] == x && j < n)
			{
				printf("%d\n", j);
				break;
			}		//����ҵ��˾��˳�ѭ�� �Ҳ���Ҫ��for�����������ٽ��д�ӡ-1
			k++;
		}
		if (k==n)
			printf("-1");
	}
	return 0;
}

