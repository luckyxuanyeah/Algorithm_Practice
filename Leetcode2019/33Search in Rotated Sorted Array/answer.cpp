// 33Search in Rotated Sorted Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "vector"
using namespace std;

int search(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;
	else if (nums.size() == 1)
	{
		if (target == nums[0])
			return 0;
		else
			return -1;
	}
	int pos = 0;
	int beginLeft = nums[0];
	int you = nums.size() - 1;
	int zuo = 0;
	int erfen = (zuo + you) / 2;
	while (zuo <= you)
	{
		if (erfen + 1 < nums.size()) 
		{
			if (nums[erfen] > nums[erfen + 1])
			{
				pos = erfen + 1;
				break;
			}
		}
		if (nums[erfen] >= beginLeft)
		{
			zuo = erfen + 1;
			erfen = (you + zuo) / 2;
		}
		else if (nums[erfen] < beginLeft)
		{
			you = erfen - 1;
			erfen = (zuo + you) / 2;
		}
	}
	if (zuo > you)
	{
		if (target<nums[0] || target>nums[nums.size() - 1])
			return -1;
		else if (target >= nums[0] && target <= nums[nums.size() - 1])
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (target == nums[i])
					return i;
			}
		}
		return -1;
	}
	int ans = 0;
	int left = 0;
	int right = nums.size() - 1;
	int endLeft = nums[pos - 1];
	int beginRight = nums[pos];
	int endRight = nums[nums.size() - 1];
	int temp = (left + right) / 2;
	if (nums[temp] == target)
		ans = temp;
	else if (target >= beginRight && target <= endRight)
	{
		if (target == beginRight)
			ans = pos;
		else if (target == endRight)
			ans = nums.size() - 1;
		else
		{
			left = pos;
			right = nums.size() - 1;
			temp = (left + right) / 2;
			while (left <= right)
			{
				if (nums[temp] == target)
				{
					ans = temp;
					break;
				}
				if (nums[temp] > target)
				{
					right = temp - 1;
					temp = (left + right) / 2;
				}
				else if (nums[temp] < target)
				{
					left = temp + 1;
					temp = (left + right) / 2;
				}
			}
			if (left > right)
				return -1;
		}
	}
	else if (target >= beginLeft && target <= endLeft)
	{
		if (target == beginLeft)
			ans = 0;
		else if (target == endLeft)
			ans = pos - 1;
		else
		{
			left = 0;
			right = pos - 1;
			temp = (left + right) / 2;
			while (left <= right)
			{
				if (nums[temp] == target)
				{
					ans = temp;
					break;
				}
				if (nums[temp] > target)
				{
					right = temp - 1;
					temp = (left + right) / 2;
				}
				else if (nums[temp] < target)
				{
					left = temp + 1;
					temp = (left + right) / 2;
				}
			}
			if (left > right)
				return -1;
		}
	}
	else if (target > endLeft || (target<beginLeft&& target>endRight) || target < beginRight)
		return -1;
	return ans;
}

int main()
{
	vector<int> nums;
	/*nums.push_back(1);
	nums.push_back(3)*/;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	int target;
	cin >> target;
	int ans = search(nums, target);
	cout << ans << endl;
    return 0; 
}
//Runtime: 8 ms, faster than 99.30% of C++ online submissions for Search in Rotated Sorted Array.
//Memory Usage: 9.7 MB, less than 94.15% of C++ online submissions for Search in Rotated Sorted Array.
//Next challenges:Search in Rotated Sorted Array II   Find Minimum in Rotated Sorted Array
