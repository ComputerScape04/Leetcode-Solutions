class NumArray {
public:
    vector<int> nums;

    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        vector<int> pfx(nums.size());
        pfx[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            pfx[i] = pfx[i-1] + nums[i];
        return (left == 0) ? pfx[right] : (pfx[right] - pfx[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
