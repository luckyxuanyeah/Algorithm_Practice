// 6.4 4 A1022(30).cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "map"
using namespace std;
const int maxn = 1000010;
string change[6] = { "", "title", "author", "keyWords", "publisher", "year" };
struct Info{
	string title, author, keyWords, publisher, year;
}b[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	map<Info, int> book;
	for (int i = 0; i < n; i++)
	{
		int id;
		scanf("%d", &id);
		getline(cin, b[id].title);
		getline(cin, b[id].author);
		getline(cin, b[id].keyWords);
		getline(cin, b[id].publisher);
		getline(cin, b[id].year);
		book[b[id]] = id;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		string temp, str;
		getline(cin, temp);
		int j = 0;
		for (string::iterator it = temp.begin() + 3; it != temp.end(); it++)
			str[j++] = *it;
		int num = temp[0] - '0', count = 0;
		for (map<Info, int>::iterator it = book.begin(); it != book.end(); it++)
		{
			if (change[num] == "title" && it->first.title == str){
				printf("%d\n", it->second);
				count++;
			}
			else if (change[num] == "author" && it->first.author == str){
				printf("%d\n", it->second);
				count++;
			}
			else if (change[num] == "keyWords" && it->first.keyWords == str){
				printf("%d\n", it->second);
				count++;
			}
			else if (change[num] == "publisher" && it->first.publisher == str){
				printf("%d\n", it->second);
				count++;
			}
			else if (change[num] == "year" && it->first.year == str){
				printf("%d\n", it->second);
				count++;
			}
		}
		if (count == 0)
			printf("Not Found\n");
	}
	return 0;
}