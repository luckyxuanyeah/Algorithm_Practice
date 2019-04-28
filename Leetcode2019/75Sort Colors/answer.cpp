class Solution {
public:
    void swap(vector<int>& a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void sortColors(vector<int>& nums)
{
    if(nums.size()==1||nums.size()==0)
        return;
	int p0 = 0;
	int p2 = nums.size()-1;
	int p1=p0;//p1从p0的位置开始遍历
	while (p1 <= p2)
	{
		if (nums[p1] == 1)
			p1++;
		else if (nums[p1] == 0)
		{
			swap(nums, p0, p1);
			p0++;
			p1++;
		}
		else
		{
			swap(nums, p2, p1);
			p2--;
		}
	}
}
};
//Runtime: 8 ms, faster than 38.53% of C++ online submissions for Sort Colors.
//Memory Usage: 8.6 MB, less than 37.18% of C++ online submissions for Sort Colors.
//Next challenges:Sort List  Wiggle Sort  Wiggle Sort II
