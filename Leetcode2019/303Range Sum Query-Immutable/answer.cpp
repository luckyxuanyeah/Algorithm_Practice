class NumArray {
private:
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            data.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0)
            return data[j];
        else
            return data[j]-data[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
 
//Runtime: 48 ms, faster than 30.34% of C++ online submissions for Range Sum Query - Immutable.
//Memory Usage: 17.3 MB, less than 24.69% of C++ online submissions for Range Sum Query - Immutable.
//Next challenges:Range Sum Query 2D - Immutable  Range Sum Query - Mutable  Maximum Size Subarray Sum Equals k
