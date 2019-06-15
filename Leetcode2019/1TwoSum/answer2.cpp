//20190615记录：这里使用了无序的map，使用无序的map可以进行数字和index的映射，查找的时间复杂度为O(1)，因此整体的时间复杂度为O(n)。
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> indices;
	for (int i = 0; i < nums.size(); i++) {
		if (indices.find(target - nums[i]) != indices.end())
			return { indices[target - nums[i]], i };
		indices[nums[i]] = i;
	}
	return {};
}
//Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
//Memory Usage: 10.2 MB, less than 53.10% of C++ online submissions for Two Sum.
//Next challenges:4Sum  Two Sum II - Input array is sorted  Two Sum III - Data structure design  Subarray Sum Equals K  Two Sum IV - Input is a BST
