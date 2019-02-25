#include "iostream"
#include "string"
#include "vector"
using namespace std;

int main()
{
	string S = "";
	//scanf("%s", S);//字符串不需要加&，字符数组char a[]也不需要加&！！！
	vector<char> substring;
	vector<int> ans;
	substring.push_back(S[0]);
	int count = 0;
	for (int i = 1; i < S.length(); i++)
	{
		for (int j = 0; j < substring.size(); j++)
		{
			if (S[i] == substring[j])
			{
				count = 0;
				ans.push_back(substring.size());
				substring.clear();
				substring.push_back(S[i]);
				break;
			}
			else if (S[i] != substring[j])
				count++;
		}
		if (count == substring.size())
		{
			count = 0;
			substring.push_back(S[i]);
		}
	}
	int maxn = 0;
	for (int i = 0; i < ans.size(); i++)
	{
		if (maxn < ans[i])
			maxn = ans[i];
	}
	printf("%d", maxn);
    return 0;
}
