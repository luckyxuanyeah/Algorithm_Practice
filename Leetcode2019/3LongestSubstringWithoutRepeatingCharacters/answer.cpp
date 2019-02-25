#include "iostream"
#include "string"
#include "vector"
#include <algorithm>
using namespace std;

int main()
{
	string s = "dvdf";
	if (s.length() == 0 || s.length() == 1)//这两个特殊情况一定要考虑呀!!!
		return s.length();
	vector<char> a;
	a.push_back(s[0]);
	int num = 1;
	vector<char>::iterator it;
	for (int i = 1; i < s.length(); i++) 
	{
		while (1) 
		{
			it = find(a.begin(), a.end(), s[i]);//借助algorithm库，在vector子字符串a中查找某个字符是否存在
			if (it != a.end())//如果迭代器查找到存在，并且不是在子字符串的最后找出来的
			{
				a.erase(a.begin());//将子字符串中的第一个字符删除，然后继续循环，直到迭代器中找不到，也就是删除了
				continue;
			}
			else //在子字符串中找不到，就把它加入到子字符串序列中
			{
				a.push_back(s[i]);
				if (num < a.size())
					num = a.size();
				break;//打破循环进行下一个字符的判断
			}
		}
	}
	//string S = "dvdf";
	////scanf("%s", S);//字符串不需要加&，字符数组char a[]也不需要加&！！！
	//vector<char> substring;
	//vector<int> ans;
	//substring.push_back(S[0]);
	//int count = 0;
	//for (int i = 1; i < S.length(); i++)//这个方法不对啊啊啊，应该是每判断完一个字符有重复之后，就继续向后移动一位，接着判断剩下的每一个字符
	//{
	//	for (int j = 0; j < substring.size(); j++)
	//	{
	//		if (S[i] == substring[j])
	//		{
	//			count = 0;
	//			ans.push_back(substring.size());
	//			substring.clear();
	//			substring.push_back(S[i]);
	//			break;
	//		}
	//		else if (S[i] != substring[j])
	//			count++;
	//	}
	//	if (count == substring.size())
	//	{
	//		count = 0;
	//		substring.push_back(S[i]);
	//		if (i == S.length()-1)
	//			ans.push_back(substring.size());
	//	}
	//}
	//int maxn = 0;
	//for (int i = 0; i < ans.size(); i++)
	//{
	//	if (maxn < ans[i])
	//		maxn = ans[i];
	//}
    printf("%d", num);
    return 0;
}
