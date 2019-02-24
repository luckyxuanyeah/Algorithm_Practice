#include "iostream"
#include "vector"
using namespace std;

int main()
{
	vector<int> nums, ans;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	int target;
	scanf("%d", &target);
	for (int i = 0; i < nums.size(); i++)
	{
		int j = i + 1;
		while (j < nums.size() && nums[i] + nums[j] != target)
			j++;
		if (j< nums.size())
		{
			if (nums[i] + nums[j] == target)
			{
				ans.push_back(i);
				ans.push_back(j);
				break;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
    return 0;
}
//Runtime: 148 ms, faster than 35.18% of C++ online submissions for Two Sum.
//Memory Usage : 9.5 MB, less than 73.42% of C++ online submissions for Two Sum.
//Next challenges :
//4Sum
//Two Sum II - Input array is sorted
//Two Sum III - Data structure design
//Subarray Sum Equals K
//Two Sum IV - Input is a BST
