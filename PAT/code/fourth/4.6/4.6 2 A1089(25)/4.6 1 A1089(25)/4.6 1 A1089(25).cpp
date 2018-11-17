// 4.6 1 A1089(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int N = 111;
int orign[N], tempOri[N], changed[N];
int n;
bool isSame(int a[], int b[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}
void show(int a[])
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1) printf(" ");
		else printf("\n");
	}
}
bool insertSort()
{
	bool flag = false;
	for (int i = 1; i < n; i++)
	{
		if (i != 1 && isSame(tempOri, changed))
			flag = true;
		int temp = tempOri[i], j = i;
		while (j>0 && tempOri[j - 1] > temp)
		{
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if (flag == true)
			return true;
	}
	return false;
}
void mergeSort()
{
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2){
		if (step != 2 && isSame(tempOri, changed))
			flag = true;
		for (int i = 0; i < n; i += step)
			sort(tempOri + i, tempOri + min(i + step, n));
		if (flag == true)
		{
			show(tempOri);
			return;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &orign[i]);
		tempOri[i] = orign[i];
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &changed[i]);
	if (insertSort())
	{
		printf("Insertion Sort\n");
		show(tempOri);
	}
	else
	{
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++)
			tempOri[i] = orign[i];
		mergeSort();
	}
	return 0;
}