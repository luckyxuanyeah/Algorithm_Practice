// 4.5 4 A1048(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int maxn = 100001;
int binarySearch(int a[], int left, int right, int m)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == m)
			return mid;
		else if (a[mid] > m)
			right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int num[maxn];
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	sort(num, num + n);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int j = binarySearch(num, i + 1, n - 1, m - num[i]);
		if (j != -1)
		{
			printf("%d %d\n", num[i], num[j]);
			count++;
			break;
		}
	}
	if (count == 0)
		printf("No Solution\n");
	return 0;
}
