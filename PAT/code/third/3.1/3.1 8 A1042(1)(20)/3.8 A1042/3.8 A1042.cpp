// 3.8 A1042.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"


int main()
{
	int n;
	scanf("%d", &n);
	int a[54];
	char b[54][4] = {}, d[54][4] = {};
	char c[54][4]= { "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
		"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
		"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
		"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
		"J1", "J2" };
	for (int i = 0; i < 54; i++)
	{
		scanf("%d", &a[i]);
		b[a[i]][4] = c[i][4];
	}
	while ((n-1)>0)
	{
		for (int j = 0; j < 54; j++)
			d[a[j]][4] = b[j][4];
		for (int j = 0; j < 54; j++)
			b[j][4] = d[j][4];
	}
	for (int k = 0; k < 54; k++)
	{
		if (k < 53)
			printf("%c ", b[k][4]);
		else
			printf("%c", b[k][4]);
	}
	return 0;
}

