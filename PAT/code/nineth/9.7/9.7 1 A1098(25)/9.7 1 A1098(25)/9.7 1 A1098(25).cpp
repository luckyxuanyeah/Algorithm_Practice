// 9.7 1 A1098(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int N = 111;
int origin[N], changed[N], tempOri[N];
int n;
bool isSame(int a[], int b[])
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != b[i]) 
			return false;
	}
	return true;
}
void showArray(int a[])
{
	for (int i = 1; i <= n; i++)
	{
		printf("%d", a[i]);
		if (i < n)
			printf(" ");
	}
	printf("\n");
}
bool insertSort()
{
	bool flag = false;
	for (int i = 2; i <= n; i++)
	{
		if (i != 2 && isSame(tempOri, changed))
			flag = true;
		sort(tempOri, tempOri + i + 1);
		if (flag == true)
			return true;
	}
	return false;
}
void downAdjust(int low, int high)
{
	int i = low, j = 2 * i;
	while (j <= high)
	{
		if (j + 1 <= high && tempOri[j + 1] > tempOri[j])
			j = j + 1;
		if (tempOri[j] > tempOri[i])
		{
			swap(tempOri[j], tempOri[i]);
			i = j;
			j = i * 2;
		}
		else 
			break;
	}
}
void heapSort()
{
	bool flag = false;
	for (int i = n / 2; i >= 1; i--)
		downAdjust(i, n);
	for (int i = n; i > 1; i--)
	{
		if (i != n && isSame(tempOri, changed))
			flag = true;
		swap(tempOri[i], tempOri[1]);
		downAdjust(1, i - 1);
		if (flag == true)
		{
			showArray(tempOri);
			return;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &changed[i]);
	if (insertSort())
	{
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else
	{
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++)
			tempOri[i] = origin[i];
		heapSort();
	}
	return 0;
}