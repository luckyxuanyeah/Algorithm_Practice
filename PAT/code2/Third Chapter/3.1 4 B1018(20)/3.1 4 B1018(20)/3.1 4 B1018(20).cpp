// 3.1 4 B1018(20).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
int mp[3] = { 'B', 'C', 'J' };
//����ĸ�����ֶ�Ӧӳ��
int change(char c)
{
	if (c == 'B')
		return 0;
	else if (c == 'C')
		return 1;
	else if (c == 'J')
		return 2;
}
int main()
{
	int n, count1[3] = { 0 }, count2[3] = { 0 }, ans1 = 0, ans2 = 0, ans3 = 0;
	scanf("%d", &n);
	char a, b;
	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c %c", &a, &b);
		int p, q;
		p = change(a);
		q = change(b);
		if ((p + 1) % 3 == q)
		{
			ans1++;
			count1[p]++;
		}
		else if (p == q)
			ans2++;
		else if ((q + 1) % 3 == p)
		{
			ans3++;
			count2[q]++;
		}
	}
	printf("%d %d %d\n", ans1, ans2, ans3);
	printf("%d %d %d\n", ans3, ans2, ans1);
	int num1=0, num2=0;//��ʼ��Ĭ�����ֵ��count1[0] ���Ƚ� �����ֵ��num1��
	for (int i = 0; i < 3; i++)
	{
		if (count1[i] >count1[num1])
			num1 = i;
		if (count2[i] > count2[num2])
			num2 = i;
	}
	printf("%c %c\n", mp[num1], mp[num2]);
	return 0;
}