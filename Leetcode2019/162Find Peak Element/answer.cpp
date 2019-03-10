// 162Find Peak Element.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "vector"
using namespace std;

int findPeakElement(vector<int>& nums) {
	int ans;
	if (nums.size() == 0)
		return 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0 && i + 1 < nums.size())
		{
			if (nums[i] > nums[i + 1])
			{
				ans = i;
				break;
			}
		}
		if (i == nums.size() - 1)
		{
			if (nums[i - 1] < nums[i])
			{
				ans = i;
				break;
			}
		}
		if (i + 1 < nums.size() && i - 1 >= 0)
		{
			if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
			{
				ans = i;
				break;
			}
		}
	}
	return ans;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	int a=findPeakElement(nums);
	cout << a << endl;
	return 0;
}

//Runtime: 8 ms, faster than 99.23% of C++ online submissions for Find Peak Element.
//Memory Usage: 8.9 MB, less than 63.44% of C++ online submissions for Find Peak Element.
//Next challenges:Peak Index in a Mountain Array
