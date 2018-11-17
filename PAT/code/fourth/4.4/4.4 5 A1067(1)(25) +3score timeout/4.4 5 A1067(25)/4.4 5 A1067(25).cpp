#include "stdafx.h"
#include "stdio.h"
#include "algorithm"
using namespace std;
int number(bool a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == false)
			count++;
	}
	return count;
}
int main()
{
	int n;
	scanf("%d", &n);
	int s[100010];
	int num = 0;
	bool hash[100010] = { false };
	for (int i = 0; i < n; i++){
		scanf("%d", &s[i]);
		if (s[i] == 0)
			num = i;
		if (s[i] == i)
			hash[i] = true;
	}
	int total = number(hash, n);
	int count = 0;
	while (total != 0){
		if (num != 0){
			for (int i = 0; i < n; i++){
				if (s[i] == num){
					int temp = s[num];
					s[num] = s[i];
					s[i] = temp;
					count++;
					hash[num] = true;
					total--;
					num = i;
					break;
				}
			}
		}
		else{
			for (int i = 0; i < n; i++)
			{
				if (hash[i] == false)
				{
					int temp = s[num];
					s[num] = s[i];
					s[i] = temp;
					count++;
					num = i;
					break;
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
