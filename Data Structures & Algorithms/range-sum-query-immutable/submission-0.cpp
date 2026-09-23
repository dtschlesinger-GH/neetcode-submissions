class NumArray {
public:
    NumArray(vector<int>& nums) {
        internalNums = nums;
    }
    
    int sumRange(int left, int right) {
        int totalSum = 0;
        while (left <= right) 
        {
            totalSum += internalNums[left];
            left++;
        }
        return totalSum;
    }
    vector<int> internalNums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */