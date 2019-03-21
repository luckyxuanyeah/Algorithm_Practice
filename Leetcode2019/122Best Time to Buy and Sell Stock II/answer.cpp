class Solution {
public:
   int maxProfit(vector<int>& prices) 
{
	int sum = 0;
	for (int i = 0; i < prices.size(); i++)
	{
        if(i + 1 < prices.size())
        {   
            if (prices[i] < prices[i + 1])
			    sum += prices[i + 1] - prices[i];
        }
	}
	return sum;
}
};
//Runtime: 8 ms, faster than 99.38% of C++ online submissions for Best Time to Buy and Sell Stock II.
//Memory Usage: 9.5 MB, less than 63.48% of C++ online submissions for Best Time to Buy and Sell Stock II.
//Next challenges:Best Time to Buy and Sell Stock III  Best Time to Buy and Sell Stock IV  Best Time to Buy and Sell Stock with Cooldown  Best Time to Buy and Sell Stock with Transaction Fee
