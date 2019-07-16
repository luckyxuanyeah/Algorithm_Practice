vector<int> findDuplicates(vector<int>& nums)
{
        vector<int> ret;
        for(int i = 0;i<nums.size();i++){
            int tmp = abs(nums[i]) -1;
            nums[tmp] = -nums[tmp];
            if(nums[tmp]>0){
                ret.push_back(tmp+1);
            }
        }
        return ret;
}
//Runtime: 112 ms, faster than 88.61% of C++ online submissions for Find All Duplicates in an Array.
//Memory Usage: 14.8 MB, less than 70.02% of C++ online submissions for Find All Duplicates in an Array.
//Next challenges:Find All Numbers Disappeared in an Array
