// 4.2 11 A1048(25).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

int main()
{
	int n, m;
	int k;
	scanf("%d %d", &n, &m);
	int hash[1010] = {};
	for (int i = 0; i < n; i++){
		scanf("%d", &k); 
		hash[k]++;
	}
	int p = m - 1, count = 0;
	for (int i = 1; i < 1001; i++)
	{
		if (i + p == m){
			hash[i]--;
			hash[p]--;
			if (hash[i] >= 0 && hash[p] >= 0)
				break;
		}
		p--;
		count = i;
	}	
	if (count==1000)
		printf("No Solution\n");
	else printf("%d %d\n", count+1, p);
	return 0;
}

