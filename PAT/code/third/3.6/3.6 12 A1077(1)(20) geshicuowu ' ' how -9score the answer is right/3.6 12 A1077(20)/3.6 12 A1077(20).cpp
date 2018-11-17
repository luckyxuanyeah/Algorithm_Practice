// 3.6 12 A1077(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

void reverse(char s[],int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		int temp1 = s[i];
		s[i] = s[len - 1 - i];
		s[len -1 - i] = temp1;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	char sentence[101][270] = {};
	int len[101] = {};
	char temp[270] = {};
	int count[101] = {};
	getchar();
	for (int i = 0; i < n; i++){
		gets_s(sentence[i]);
		len[i] = strlen(sentence[i]);
		if (sentence[i][len[i] - 1] == ' '){
			sentence[i][len[i] - 1] = '\0';
			len[i] = len[i] - 1;
		}
		reverse(sentence[i],len[i]);
	}
	strcpy(temp, sentence[0]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < len[i]; j++)
		{
			if (temp[j] != sentence[i][j])
			{
				count[i] = j;
				break;
			}
		}
		if (i >= 1){
			if (count[i] < count[i - 1])
				strcpy(temp, sentence[i]);
		}
	}
	if (count[n - 1] == 0)
		printf("nai\n");
	else
	{
		for (int i = count[n - 1] -1; i >= 0; i--)
				printf("%c", sentence[0][i]);
	}
	return 0;
}

