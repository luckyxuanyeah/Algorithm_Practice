// 3.1 5 A1042(20).cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "stdio.h"
//��mpӳ����˿��ƵĻ�ɫ
char mp[5] = { 'S', 'H', 'C', 'D', 'J' };
//������������ start next end
int start[54], next[54], end[54];
int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= 54; i++)
		start[i] = i;
	for (int i = 1; i <= 54; i++)
		scanf("%d", &next[i]);
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= 54; j++)
			end[next[j]] = start[j];
		for (int j = 1; j <= 54; j++)//��start���¸�ֵ ���ڽ�����ʹ��
			start[j] = end[j];
	}
	for (int i = 1; i <= 54; i++)
	{
		if (i != 1) printf(" ");
		printf("%c%d", mp[(start[i] - 1) / 13], (start[i] - 1) % 13 + 1);//�����ɫ�Ͷ�Ӧ�ַ�
	}
	return 0;
}

