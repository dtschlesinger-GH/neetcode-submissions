class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
       int fixedSize = nums.size();
       for (int i = 0; i < fixedSize; i++) 
       {
            nums.push_back(nums[i]);
       } 
       return nums;
    }
};