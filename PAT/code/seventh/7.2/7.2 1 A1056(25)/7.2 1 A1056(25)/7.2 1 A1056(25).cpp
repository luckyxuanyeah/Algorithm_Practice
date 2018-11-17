// 7.2 1 A1056(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "queue"
using namespace std;
struct Mouse{
	int weight;
	int rank;
}array[1010];
int times(int a, int b)
{
	int num = 0;
	if (a > b){
		if (a%b == 0)
			num = a / b;
		else 
			num = a / b + 1;
	}
	else if (a<=b && a>0)
		num = 1;
	return num;
}
int main()
{
	int Np, Ng;
	scanf("%d%d", &Np, &Ng);
	for (int i = 0; i < Np; i++)
		scanf("%d", &array[i].weight);
	queue<int> q;
	for (int i = 0; i < Np; i++)
	{
		int order;
		scanf("%d", &order);
		q.push(order);
	}
	int temp = Np, group;
	while (q.size() !=1){
		if (temp%Ng == 0)
			group = temp / Ng;
		else
			group = temp / Ng + 1;
		for (int i = 0; i < group; i++)
		{
			int k = q.front();
			for (int j = 0; j < Ng; j++)
			{
				if (j + i*Ng >= temp) break;
				int front = q.front();
				if (array[front].weight > array[k].weight)
					k = front;
				array[front].rank = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	array[q.front()].rank = 1;
	for (int i = 0; i < Np; i++)
	{
		printf("%d", array[i].rank);
		if (i < Np - 1) printf(" ");
	}
	printf("\n");
	return 0;
}

