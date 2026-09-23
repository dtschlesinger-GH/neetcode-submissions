class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> uniqueList;
        int currentIdx = -1000;

        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] > currentIdx) 
            {
                uniqueList.push_back(nums[i]);
                currentIdx = nums[i];
            }
        }
        nums = uniqueList;
        return uniqueList.size();
    }
};