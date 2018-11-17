// 3.2 example.cpp : 定义控制台应用程序的入口点。
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
		for (int j = 0; j < n; j++) //查询主体
		{
			if (a[j] == x && j < n)
			{
				printf("%d\n", j);
				break;
			}		//如果找到了就退出循环 找不到要在for遍历结束后再进行打印-1
			k++;
		}
		if (k==n)
			printf("-1");
	}
	return 0;
}

