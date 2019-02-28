#include "iostream"
#include "vector"
using namespace std;

int main()
{
	int x;
	scanf("%d", &x);
	int input = x;
	vector<int> panduan;
	if (x<0)
		printf(" false");
	else
	{
		while (x != 0)
		{
			panduan.push_back(x % 10);
			x = x / 10;
		}
		long long y = 0;
		for (int i = 0; i<panduan.size(); i++)
			y = y * 10 + panduan[i];
		if (input == y)
			printf("true");
		else
			printf("false");
	}
    return 0;
}
//Runtime: 132 ms, faster than 94.75% of C++ online submissions for Palindrome Number.
//Memory Usage: 76.6 MB, less than 5.10% of C++ online submissions for Palindrome Number.
//Next challenges:
//Palindrome Linked List
