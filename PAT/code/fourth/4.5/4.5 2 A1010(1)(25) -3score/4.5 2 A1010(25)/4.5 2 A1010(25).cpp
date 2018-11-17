// 4.5 2 A1010(25).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
typedef long long ll;
int num[130] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129,130 };
ll change(char a[],int r)
{
	int len = strlen(a);
	ll ans = 0;
	int b[10] = {};
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] >= '0'&&a[i] <= '9')
			b[i] = a[i] - '0';
		else if (a[i] >= 'a'&&a[i] <= 'z')
			b[i] = a[i] - 'a' + 10;
	}
	ll mul = 1;
	for (int i = len-1; i >=0; i--)
	{
		ans = ans + b[i] * mul;
		mul = mul*r;
	}
	return ans;
}
int binarySearch(int A[], int left, int right, char a[], ll number)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		ll ans = change(a, A[mid]);
		if (ans == number)
			return mid;
		else if (ans > number)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int main()
{
	char n1[11], n2[11],temp[11];
	int tag, radix;
	scanf("%s%s%d%d", n1, n2, &tag, &radix);
	if (tag == 2)
	{
		strcpy(temp, n1);
		strcpy(n1, n2);
		strcpy(n2, temp);
	}
	ll compare = change(n1, radix);
	int r = binarySearch(num, 0, 129, n2, compare);
	if (r == -1)
		printf("Impossible\n");
	else if (r != -1)
		printf("%d\n", num[r]);
	return 0;
}