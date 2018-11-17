// 4.2 1 A1084(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char a[81], b[81];
	bool hashTable[128]= {false};
	scanf("%s", a);
	scanf("%s", b);
	int len1 = strlen(a);
	int len2 = strlen(b);
	int j = 0;
	for (int i = 0; i < len1; i++)
	{
		if (a[i] != b[j])
		{
			if (hashTable[a[i]] == false){
				if (a[i]>='a'&&a[i] <= 'z')
					printf("%c", a[i] - 'a' + 'A');
				else
					printf("%c", a[i]);
				hashTable[a[i]] = true;
				if (a[i]>='a'&&a[i]<='z')
					hashTable[a[i] - 32] = true;
				else if (a[i]>='A'&&a[i] <= 'Z')
					hashTable[a[i] + 32] = true;
			}
		}
		else if (a[i] == b[j])
			j++;
	}
	return 0;
}

