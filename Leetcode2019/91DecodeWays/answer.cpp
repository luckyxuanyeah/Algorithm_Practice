//这个是比较好的做法啊啊啊！
int numDecodings(string s){
        if(s.size() == 0 || s[0] == '0') return 0;
        int prev1 = 1, prev2 = 1;
        for(int i = 1; i < s.size(); i++){
            int num1 = stoi(s.substr(i,1));
            int num2 = stoi(s.substr(i-1,2));
            int t = 0;
            if(num1 > 0 && num1 <= 9)
                t += prev1;
            if(num2 >= 10 && num2 <= 26)
                t += prev2;
            prev2 = prev1;
            prev1 = t;
        }
        return prev1;
    }
    
 //自己的做法
 class Solution {
public:
    int numDecodings(string s)
{
	int len = s.length();
	if (len == 0)
		return 0;
	if (s[0] - 48 == 0)
		return 0;
	int dp[100001] = { 0 };
	if (s[len - 1] - 48 > 0 && s[len - 1] - 48 <= 9)
		dp[len - 1] = 1;
	else if (s[len - 1] - 48 == 0)
		dp[len - 1] = 0;
	bool judge= true;
	if (s[len - 2] - 48 == 0)
	{
		if (s[len - 1] - 48 == 0)
			judge = false;
		else
			dp[len - 2] = dp[len - 1];
	}
	else if (s[len - 2] - 48 == 1 || s[len - 2] - 48 == 2)
	{
		if (s[len - 1] - 48 == 0)
			dp[len - 2] = 1;
		else
		{
			if (10 * (s[len - 2] - 48) + s[len - 1] - 48 > 10 && 10 * (s[len - 2] - 48) + s[len - 1] - 48 <= 26 && 10 * (s[len - 2] - 48) + s[len - 1] - 48 != 20)
				dp[len - 2] = 2;
			else
				dp[len - 2] = dp[len - 1];
		}
	}
	else if (s[len - 2] - 48 > 2 && s[len - 2] - 48 <= 9)
	{
		if (s[len - 1] - 48 == 0)
		{
			dp[len - 2] = 0;
			judge = false;
		}
		else
			dp[len - 2] = dp[len - 1];
	}
	for (int i = len-3; i >=0; i--)
	{
		if (judge == false)
			return 0;
		if (s[i] - 48 == 0) 
		{
			if (s[i+1] - 48 == 0)
				judge = false;
			else
				dp[i] = dp[i + 1];
		}
		else if (s[i] - 48 == 1 || s[i] - 48 == 2)
		{
			if (s[i + 1] - 48 == 0)
				dp[i] = dp[i + 1];
			else
			{
				int temp = 10 * (s[i] - 48) + s[i+1] - 48;
				if (temp > 10 && temp <= 26 && temp != 20)
					dp[i] = dp[i + 1] + dp[i + 2];
				else
					dp[i] = dp[i + 1];
			}
		}
		else if (s[i] - 48 > 2 && s[i] - 48 <= 9)
		{
			if (s[i + 1] - 48 == 0)
			{
				dp[i] = 0;
				judge = false;
			}
			else
				dp[i] = dp[i + 1];
		}
	}
	return dp[0];
}
};
//Runtime: 8 ms, faster than 35.74% of C++ online submissions for Decode Ways.
//Memory Usage: 8.8 MB, less than 8.86% of C++ online submissions for Decode Ways.
//Next challenges:Decode Ways II
