// 3.2 1 B1041(15) answer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
const int max = 1010;
struct Student{
	long long id;
	int examSeat;
}testSeat[max];//�ṹ������ ��1010��ѧ�����ݽṹ
int main()
{
	int n, examSeat, m, seat;
	scanf("%d", &n);
	long long id;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%d%d", &id, &seat, &examSeat);
		testSeat[seat].id = id;
		testSeat[seat].examSeat = examSeat;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &seat);
		printf("%lld %d\n", testSeat[seat].id, testSeat[seat].examSeat);
	}
	return 0;
}

