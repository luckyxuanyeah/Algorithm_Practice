int singleNumber(vector<int>& nums)
{
	int sum = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		sum ^= nums[i];
	}
	return sum;
}
//Runtime: 12 ms, faster than 96.18% of C++ online submissions for Single Number.
//Memory Usage: 9.8 MB, less than 35.64% of C++ online submissions for Single Number.
//Next challenges:Single Number II\Single Number III\Missing Number\Find the Difference
