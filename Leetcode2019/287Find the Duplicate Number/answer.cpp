int findDuplicate(vector<int>& nums) 
{
    int fast = nums[nums[0]], slow = nums[0];
    while(fast != slow){
    slow = nums[slow];
    fast = nums[nums[fast]];
    }
    slow = nums[slow];
    fast = nums[0];
    while(fast != slow){
    fast = nums[fast];
    slow = nums[slow];
    }
    return fast;
}
//Runtime: 8 ms, faster than 98.12% of C++ online submissions for Find the Duplicate Number.
//Memory Usage: 9.9 MB, less than 38.88% of C++ online submissions for Find the Duplicate Number.
//Next challenges:First Missing Positive    Single Number    Missing Number    Set Mismatch
