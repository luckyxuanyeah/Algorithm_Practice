class Solution {
public:
    int maxProfit(vector<int>& prices)
{
	int min = INT_MAX;
	int maxprofit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		if (min > prices[i])
			min = prices[i];
		else if (prices[i] - min > maxprofit)
			maxprofit = prices[i] - min;
	}
	return maxprofit;
}
};
//Runtime: 8 ms, faster than 99.38% of C++ online submissions for Best Time to Buy and Sell Stock.
//Memory Usage: 9.5 MB, less than 52.61% of C++ online submissions for Best Time to Buy and Sell Stock.
//Next challenges:Best Time to Buy and Sell Stock II   Best Time to Buy and Sell Stock III   Best Time to Buy and Sell Stock IV   Best Time to Buy and Sell Stock with Cooldown
